#pragma once

#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <variant>

namespace ecs 
{
    using bitmask = std::uint64_t; // => 64 component types max.
    constexpr int MAX_COMP_ID = 63;

    /// Gets a new component ID. Maximum ID is 64.
    unsigned int next_comp_id();

    /// Counts (starting from 0) the set bits in sig until arriving to the only set 
    /// bit in comp_sig.
    /// Useful for sorting components based on their position in a bitmask signature.
    /// Example:
    ///     sig =       0011010101
    ///     comp_sig =  0000010000
    ///     returns: 2
    unsigned int get_comp_index(bitmask sig, bitmask comp_sig);

    template <typename comp_type>
    class component 
    {
    private:
        static unsigned int m_id; //made this private because I couldn't make it const
        
    public:
        static unsigned int id() 
        {
            return m_id;
        }

        static bitmask signature() 
        {
            return 1 << m_id;
        }
    };
    template <typename comp_type>
    unsigned int component<comp_type>::m_id = next_comp_id();

    template <typename... comp_types>
    inline bitmask gen_signature()
    {
        return (comp_types::signature() | ...);
    }

    template <typename comp_type>
    struct component_buffer
    {
        std::vector<component<comp_type>> buffer;

        component_buffer()
            : buffer{}
        {

        }

        component_buffer(comp_type components...)
            : buffer{components}
        {

        }
    };

    template<typename... comp_types>
    struct archetype 
    {
        bitmask signature;
        std::array<void*, sizeof...(comp_types)> comp_buffers;
        std::array<unsigned int, sizeof...(comp_types)> comp_buffers_order;
        /* The buffers in comp_buffers are indexed by a specific order generated from the
        archetype's signature (get_comp_index()). But there needs to be a way to relate the 
        template's types with these indexes so things that require the buffer's types, like 
        destroying them, can be achieved. So comp_buffers_order will save every comp_buffers 
        index in the order that they were created (which always matches with the typenames 
        order). */ 

        archetype()
            : signature( gen_signature<comp_types...>() ),
            comp_buffers{},
            comp_buffers_order()
        {
            ((comp_buffers[get_comp_index(signature, comp_types::signature())] = 
                new component_buffer<comp_types>()), ...);
            int i = 0;
            ((comp_buffers_order[i++] = get_comp_index(signature, comp_types::signature())), ...);
        }

        archetype(const comp_types& ... components) 
            : signature( gen_signature<comp_types...>() ),
            comp_buffers{},
            comp_buffers_order()
        {
            ((comp_buffers[get_comp_index(signature, comp_types::signature())] = 
                new component_buffer(components)), ...);
            int i = 0;
            ((comp_buffers_order[i++] = get_comp_index(signature, comp_types::signature())), ...);
        }

        ~archetype()
        {
            int i = 0;
            ((delete static_cast<component_buffer<comp_types>*>
                (comp_buffers[comp_buffers_order[i++]])), ...);
        }
    };
}
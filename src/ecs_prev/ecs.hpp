#pragma once

#include "entity.hpp"
#include "component.hpp"

namespace ecs 
{
    class world
    {
    public:
        std::map<bitmask, void*> archetypes;

        template <typename... comp_types>
        entity<comp_types...> new_entity()
        {
           bitmask signature = (comp_types::signature() | ...);
         
        }
        template <typename... comp_types>
        entity<comp_types...> new_entity(const comp_types& ... components)
        {

        }
    };
}

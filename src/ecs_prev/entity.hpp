#include "component.hpp"
#include <memory>

namespace ecs
{
    class world;

    template <typename... comp_types>
    class entity
    {
        friend class world;
    public:
        std::shared_ptr<archetype<comp_types...>> archetype_ptr;
        entity()
        {

        }
        entity(const comp_types& ... components)
        {

        }
    };
}
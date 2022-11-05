#include "component.hpp"

namespace ecs 
{

    unsigned int next_comp_id()
    {
        static unsigned int free_id = 0;
        if (!( free_id < (MAX_COMP_ID + 1) )) 
        {
            std::cerr << "A component has broken the MAX_COMP_ID limit." << std::endl;
            abort();
        }
        return free_id++;
    }

    unsigned int get_comp_index(bitmask sig, bitmask comp_sig)
    {
        unsigned int index = -1;
        while (sig & comp_sig)
        {
            sig &= (sig - 1); // Based on Brian Kernighan's algorithm
            index++;
        }
        return index;
    }
}
#ifndef OCL_CURSOR_HPP_
#define OCL_CURSOR_HPP_

#include <iostream>

namespace ocl::tools::linux {
    class cursor {
    public:
        static void position(int x, int y) {
            std::cout << "\033[%d;%df";    
        }

        static void color() {
            
        }
    };
}

#endif
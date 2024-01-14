#ifndef OCL_OBJECT_HPP_
#define OCL_OBJECT_HPP_

#include <string>
#include "interface.hpp"

namespace ocl {
    class object {
    public:
        virtual ~object() = default;

        virtual ::std::string to_string() {
            return {"ocl::object"};
        }
    };
}

#endif
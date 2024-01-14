#ifndef OCL_NOT_IMPL_HPP_
#define OCL_NOT_IMPL_HPP_

#include <string>
#include <stdexcept>
#include "../object.hpp"

namespace ocl::exception {
    class not_implemented_exception : public std::logic_error, public ocl::object {
    public:
        not_implemented_exception() : not_implemented_exception{"Function not yet implemented."} {   }    
        not_implemented_exception(decltype(nullptr)) : not_implemented_exception() {  }
        not_implemented_exception(const char* msg) : std::logic_error{msg} {    }
        not_implemented_exception(const std::string &msg) : std::logic_error{msg} {   }
        not_implemented_exception(std::string &&msg) : std::logic_error{msg.data()} {   }

        
        virtual ::std::string to_string() override {
            return ::std::string{"ocl::exception::not_implemented_exception:\n"} + what();
        }
    };
}

#endif

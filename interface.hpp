#ifndef OCL_INTERFACE_HPP
#define OCL_INTERFACE_HPP

namespace ocl::interface {
    template<typename T>
    class comparable {
    public:
        virtual bool compare(T obj) = 0;
    };
}

#endif
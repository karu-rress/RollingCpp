// 
//
//
//      ocl/os/os.hpp
//      
//      enums and constexpr variables for
//      conditional compilation.
//
//      Last update date: 2018/01/05. V1.0
//
#ifndef OCL_OS_HPP_
#define OCL_OS_HPP_

namespace ocl {
    enum class os {
        linux,
        mac,
        windows,
    };
    
// constexpr variables. the_os contains what os have compiled this.
#ifdef __linux__
    constexpr os the_os = os::linux;
#elif defined(__APPLE__)
    constexpr os the_os = os::mac;
#elif defined(_WIN32)
    constexpr os the_os = os::windows;
#endif
}

// preprocessor macros
#if __linux__
#   define DEPRECATED_IN_LINUX [[deprecated("It's deprecated in Linux.")]]
#   define DEPRECATED_IN_MAC
#   define DEPRECATED_IN_WINDOWS
#   define IN_LINUX(value) = value
#   define IN_MAC(_) /* nothing */
#   define IN_WINDOWS(_) /* nothing */
#elif defined(__APPLE__)
#   define DEPRECATED_IN_LINUX
#   define DEPRECATED_IN_MAC [[deprecated("It's deprecated in Mac.")]]
#   define DEPRECATED_IN_WINDOWS
#   define IN_LINUX(_) /* nothing */
#   define IN_MAC(value) = value
#   define IN_WINDOWS(_) /* nothing */
#elif defined(_WIN32)
#   define DEPRECATED_IN_LINUX
#   define DEPRECATED_IN_MAC
#   define DEPRECATED_IN_WINDOWS [[deprecated("It's deprecated in Windows.")]]
#   define IN_LINUX(_) /* nothing */
#   define IN_MAC(_) /* nothing */
#   define IN_WINDOWS(value) = value
#endif


#endif // #ifndef OCL_OS_HPP_
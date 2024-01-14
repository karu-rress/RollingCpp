#ifndef OCL_COLORS_HPP_
#define OCL_COLORS_HPP_

#include "os/os.hpp"
/*
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47
*/
namespace ocl {
    enum class color { 
        BLACK IN_WINDOWS(0) IN_LINUX(30),
        BLUE IN_LINUX(34),
        GREEN IN_LINUX(32),
        AQUA DEPRECATED_IN_LINUX,
        RED IN_LINUX(31),
        PURPLE IN_LINUX(35),
        YELLOW IN_LINUX(33),
        WHITE IN_LINUX(37),
        GRAY DEPRECATED_IN_LINUX,
        LIGHT_BLUE IN_LINUX(36),
        LIGHT_GREEN DEPRECATED_IN_LINUX,
        LIGHT_AQUA DEPRECATED_IN_LINUX,
        LIGHT_RED DEPRECATED_IN_LINUX,
        LIGHT_PURPLE DEPRECATED_IN_LINUX,
        LIGHT_YELLOW DEPRECATED_IN_LINUX,
        BRIGHT_WHITE DEPRECATED_IN_LINUX,
    };
}
#endif
#ifndef OCL_IO_HPP_
#define OCL_IO_HPP_

#include <iostream>
#include "../os/os.hpp"
#include "../exception/not_impl.hpp"
#include "../colors.hpp"
#include <chrono>
#include <optional>
#include <thread>
#include <string>

#ifdef _WIN32
#   include <Windows.h>
#elif defined(__linux__)
//#   define SetConsoleCursorPotision(...)
#   define GetStdHandle(x)
#   define STD_OUTPUT_HANDLE
      using COORD = struct { int x, y; };
#endif

namespace ocl::io {
    class oistream {
    public:
        oistream() = default;

        template <typename T>
        oistream &operator<<(T t) {
            std::cout << t;
            return *this;
        }

        template <typename T>
        oistream &operator>>(T t) {
            std::cin >> t;
            return *this;
        }

        template <typename... Args>
        static void print(Args... args) {
            ((std::cout << args << ' '), ...);
        }

        static inline void println() {
            std::putchar('\n');
        }

        template <typename T>
        static void println(T t) {
            std::cout << t << std::endl;
        }

        template <typename T, typename... Args>
        static void println(Args&& ...args) {
            print(args..., std::endl);
        }

        template <typename... Args>
        static void println(const char *format, Args &&... args) {
            print(format, args..., std::endl);
        }

        template <typename... Args>
        static void scan(Args &... args) {
            (std::cin.operator>>(args), ...);
        }

        template <typename... Args>
        static void scan(const char *format, Args &... ref_args) {
            std::scanf(format, ((&ref_args), ...));
        }

        static void scanln(std::string &s) {
            std::getline(std::cin, s);
        }

        template <size_t N>
        static void scanln(char (&buf)[N]) {
            std::cin.getline(buf, N);
        }

        oistream& clear() {
            if constexpr (ocl::the_os == ocl::os::windows) {
            system("cls");
            }
            else {
            system("clear");
            }
            return *this;
        }

        static void cursor(int x, int y) {
            if constexpr (ocl::the_os == ocl::os::windows) {
            //SetConsoleCursorPotision(GetStdHandle(STD_OUTPUT_HANDLE), COORD{x, y});
            }
            else if (ocl::the_os == ocl::os::linux) {
                std::printf("\033[%d;%df", y, x);
            }
            else {
            throw ::ocl::exception::not_implemented_exception{};
            }
        }

        static ::std::string to_string() {
            return {"ocl::io::oistream"};
        }

        static void set_color(ocl::color c) {

        }

        template <typename REP, typename PER = std::ratio<1>>
        static void sleep(std::chrono::duration<REP, PER> &&millisec) {
            std::this_thread::sleep_for(millisec);
        }

        static void log(const char* const game, std::optional<bool> win) {

        }

    } constexpr cio [[maybe_unused]];
}

#endif

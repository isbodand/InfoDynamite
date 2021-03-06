//
// Created by tudom on 2019-12-28.
//

#include "../include.hpp"
#include LIBLUCENT_INCLUDE_HEADER_F(lucent.hpp)

#include <cxxabi.h>

LIBLUCENT_API
std::string liblucent::Demangle(std::string_view name) {
    int succ;
    auto _d = abi::__cxa_demangle(name.data(), nullptr, nullptr, &succ);

    if (succ < 0) {
        return std::string{name};
    }

    auto ret = std::string{_d};

    return free(_d), ret;
}

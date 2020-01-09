#pragma once

#ifndef XCHENGSIGNAPK_KERNAL_HPP
#define XCHENGSIGNAPK_KERNAL_HPP

#include <iostream>
#include <thread>

#include <string_view>
#include <string>

#include <LibrarySignAPK.h>
#include <jemalloc/jemalloc.h>

using Jbyte  = unsigned char;
using Juint  = unsigned int;
using Julong = unsigned long;
using Jchar  = char;
using Jint   = int;
using Jlong  = long;
using Jllong = long long;
using Jbool  = bool;
using Jsize  = size_t;

void *operator new(Jsize vLen)
{
    auto &&obj = je_malloc(vLen);
    if (obj != nullptr)
        memset(obj, 0, vLen);
    return obj;
}

void operator delete(void *v) noexcept
{
    je_free(v);
}

void *operator new[](Jsize vLen)
{
    auto &&obj = je_malloc(vLen);
    if (obj != nullptr)
        memset(obj, 0, vLen);
    return obj;
}

void operator delete[](void *v) noexcept
{
    je_free(v);
}

#include "x_app/APPApplication.hpp"

#endif //XCHENGSIGNAPK_KERNAL_HPP

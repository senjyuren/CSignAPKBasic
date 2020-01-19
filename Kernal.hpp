#pragma once

#ifndef XCHENGSIGNAPK_KERNAL_HPP
#define XCHENGSIGNAPK_KERNAL_HPP

#include <iostream>
#include <thread>
#include <fstream>
#include <filesystem>
#include <mutex>

#include <string_view>
#include <string>
#include <list>
#include <vector>

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
    auto &&obj = malloc(vLen);
    if (obj != nullptr)
        memset(obj, 0, vLen);
    return obj;
}

void operator delete(void *v) noexcept
{
    free(v);
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

#include "x_utils/UtilsString.hpp"
#include "x_utils/UtilsLog.hpp"
#include "x_app/APPApplication.hpp"
#include "x_cmd/CmdApplication.hpp"

#endif //XCHENGSIGNAPK_KERNAL_HPP

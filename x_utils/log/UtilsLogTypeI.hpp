#pragma once

#ifndef XCHENGSIGNAPK_UTILSLOGTYPEI_HPP
#define XCHENGSIGNAPK_UTILSLOGTYPEI_HPP

namespace x
{

inline namespace xcheng
{

class UtilsLogTypeI
{
public:
    virtual ~UtilsLogTypeI();

    virtual void next(UtilsLogType type, const Jchar *v, Jint vLen) = 0;
};

UtilsLogTypeI::~UtilsLogTypeI() = default;

}

}

#endif //XCHENGSIGNAPK_UTILSLOGTYPEI_HPP

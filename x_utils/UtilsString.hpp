#pragma once

#ifndef XCHENGSIGNAPK_UTILSSTRING_HPP
#define XCHENGSIGNAPK_UTILSSTRING_HPP

namespace x
{

inline namespace xcheng
{

class UtilsString
{
public:
    static Jbool equals(const Jchar *a, const Jchar *b);
};

Jbool UtilsString::equals(const Jchar *a, const Jchar *b)
{
    Jint i    = 0;
    Jint aLen = 0;
    Jint bLen = 0;

    if ((a == nullptr) || (b == nullptr))
        return false;

    aLen = strlen(a);
    bLen = strlen(b);
    if (aLen != bLen)
        return false;

    for (i = 0; i < aLen; ++i)
    {
        if (a[i] != b[i])
            break;
    }
    return (i == aLen);
}

}

}

#endif //XCHENGSIGNAPK_UTILSSTRING_HPP

#pragma once

#ifndef XCHENGSIGNAPK_APPCONFIGSIGNTAG_HPP
#define XCHENGSIGNAPK_APPCONFIGSIGNTAG_HPP

namespace x
{

inline namespace xcheng
{

enum class APPConfigSignTag
        : Juint
{
    CITY              = 0,
    COMMON            = 1,
    EMAIL             = 2,
    COUNTRY           = 3,
    PROVINCE          = 4,
    ORGANIZATION      = 5,
    ORGANIZATION_UNIT = 6,
};

}

}

#endif //XCHENGSIGNAPK_APPCONFIGSIGNTAG_HPP

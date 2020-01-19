#pragma once

#ifndef XCHENGSIGNAPK_CMDCONFIGURATIONTYPE_HPP
#define XCHENGSIGNAPK_CMDCONFIGURATIONTYPE_HPP

namespace x
{

inline namespace xcheng
{

enum class CmdConfigurationType
        : Juint
{
    CITY              = 0,
    COUNTRY           = 1,
    PROVINCE          = 2,
    COMMON            = 3,
    EMAIL             = 4,
    OGRANIZATION      = 5,
    OGRANIZATION_UNIT = 6,
};

}

}

#endif //XCHENGSIGNAPK_CMDCONFIGURATIONTYPE_HPP

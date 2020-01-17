#pragma once

#ifndef XCHENGSIGNAPK_APPCONFIGOPERATINGI_HPP
#define XCHENGSIGNAPK_APPCONFIGOPERATINGI_HPP

namespace x
{

inline namespace xcheng
{

class APPConfigOperatingI
{
public:
    virtual ~APPConfigOperatingI();

    virtual Jbool check() = 0;

    virtual Jbool save() = 0;

    virtual Jbool read() = 0;
};

APPConfigOperatingI::~APPConfigOperatingI() = default;

}

}

#endif //XCHENGSIGNAPK_APPCONFIGOPERATINGI_HPP

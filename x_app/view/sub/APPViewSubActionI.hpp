#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWSUBACTIONI_HPP
#define XCHENGSIGNAPK_APPVIEWSUBACTIONI_HPP

namespace x
{

inline namespace xcheng
{

class APPViewSubActionI
{
public:
    virtual ~APPViewSubActionI();

    virtual void disable() = 0;

    virtual void enable() = 0;
};

APPViewSubActionI::~APPViewSubActionI() = default;

}

}

#endif //XCHENGSIGNAPK_APPVIEWSUBACTIONI_HPP

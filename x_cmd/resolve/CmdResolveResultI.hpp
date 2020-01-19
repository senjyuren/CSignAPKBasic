#pragma once

#ifndef XCHENGSIGNAPK_CMDRESOLVERESULTI_HPP
#define XCHENGSIGNAPK_CMDRESOLVERESULTI_HPP

namespace x
{

inline namespace xcheng
{

class CmdResolveResultI
{
public:
    virtual ~CmdResolveResultI();

    virtual void cmdHelp(CmdSets &v) = 0;

    virtual void cmdCheck(CmdSets &v) = 0;

    virtual void cmdX509(CmdSets &v) = 0;

    virtual void cmdSign(CmdSets &v) = 0;
};

CmdResolveResultI::~CmdResolveResultI() = default;

}

}

#endif //XCHENGSIGNAPK_CMDRESOLVERESULTI_HPP

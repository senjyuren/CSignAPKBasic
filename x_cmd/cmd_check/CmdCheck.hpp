#pragma once

#ifndef XCHENGSIGNAPK_CMDCHECK_HPP
#define XCHENGSIGNAPK_CMDCHECK_HPP

namespace x
{

inline namespace xcheng
{

class CmdCheck
{
private:
    constexpr static Jchar TEMPLATE[] = "Device status: isOK\n";

public:
    CmdCheck();
};

CmdCheck::CmdCheck()
{
    printf(TEMPLATE);
}

}

}

#endif //XCHENGSIGNAPK_CMDCHECK_HPP

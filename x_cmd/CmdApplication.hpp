#pragma once

#ifndef XCHENGSIGNAPK_CMDAPPLICATION_HPP
#define XCHENGSIGNAPK_CMDAPPLICATION_HPP

#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>

#include "CmdSet.hpp"
#include "CmdSets.hpp"
#include "configuration/CmdConfiguration.hpp"

#include "cmd_help/CmdHelp.hpp"
#include "cmd_sign/CmdSign.hpp"
#include "cmd_check/CmdCheck.hpp"
#include "cmd_config/CmdConfig.hpp"

#include "resolve/CmdResolve.hpp"

namespace x
{

inline namespace xcheng
{

class CmdApplication
        : public CmdResolveResultI
{
public:
    CmdApplication(Jchar **args, Jint argc);

    void cmdHelp(CmdSets &v) override;

    void cmdCheck(CmdSets &v) override;

    void cmdX509(CmdSets &v) override;

    void cmdSign(CmdSets &v) override;
};

CmdApplication::CmdApplication(Jchar **args, Jint argc)
{
    (new CmdResolveProcess::Builder(args, argc))
            ->add(this)
            .build();
}

void CmdApplication::cmdHelp(CmdSets &)
{
    CmdHelp();
}

void CmdApplication::cmdCheck(CmdSets &)
{
    CmdCheck();
}

void CmdApplication::cmdX509(CmdSets &v)
{
    (new CmdConfig::Builder())
            ->setCommandSets(v)
            .build();
}

void CmdApplication::cmdSign(CmdSets &v)
{
    (new CmdSign::Builder())
            ->setCommandSets(v)
            .build();
}

}

}

#endif //XCHENGSIGNAPK_CMDAPPLICATION_HPP

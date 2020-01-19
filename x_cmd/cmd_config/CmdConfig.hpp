#pragma once

#ifndef XCHENGSIGNAPK_CMDCONFIG_HPP
#define XCHENGSIGNAPK_CMDCONFIG_HPP

namespace x
{

inline namespace xcheng
{

class CmdConfig
{
public:
    class Builder;

private:
    constexpr static Jchar CMD_CREATE[] = "create";
    constexpr static Jchar CMD_LOOK[]   = "look";

    Builder *mBuilder;

public:
    class Builder
    {
    private:
        CmdSets mCmd;

    public:
        friend CmdConfig;

        Builder();

        Builder &setCommandSets(CmdSets &v);

        std::shared_ptr<CmdConfig> build();
    };

    explicit CmdConfig(Builder *builder);

    ~CmdConfig();
};

CmdConfig::Builder::Builder()
        : mCmd{}
{
}

CmdConfig::Builder &CmdConfig::Builder::setCommandSets(CmdSets &v)
{
    this->mCmd = v;
    return (*this);
}

std::shared_ptr<CmdConfig> CmdConfig::Builder::build()
{
    return std::make_shared<CmdConfig>(this);
}

CmdConfig::CmdConfig(Builder *builder)
        : mBuilder{builder}
{
    auto &&cmd = builder->mCmd;

    if (cmd.findKey(CMD_LOOK))
    {
        printf("%s", CmdConfiguration::read());
    } else if (cmd.findKey(CMD_CREATE))
    {
        CmdConfiguration::save();
    }
}

CmdConfig::~CmdConfig()
{
    delete (this->mBuilder);
}

}

}

#endif //XCHENGSIGNAPK_CMDCONFIG_HPP

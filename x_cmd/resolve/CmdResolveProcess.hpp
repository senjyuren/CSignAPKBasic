#pragma once

#ifndef XCHENGSIGNAPK_CMDRESOLVEPROCESS_HPP
#define XCHENGSIGNAPK_CMDRESOLVEPROCESS_HPP

namespace x
{

inline namespace xcheng
{

class CmdResolveProcess
{
public:
    class Builder;

private:
    constexpr static Jchar S_LINK[]       = "=";
    constexpr static Jchar T_CMD_HELP[]   = "help";
    constexpr static Jchar T_CMD_CONFIG[] = "config";
    constexpr static Jchar T_CMD_CHECK[]  = "check";
    constexpr static Jchar T_CMD_SIGN[]   = "sign";

    Builder *mBuilder;

    std::list<CmdResolveResultI *> &mProcess;

    CmdSets mCmdSets;

public:
    class Builder
    {
    private:
        Jint  mArgc;
        Jchar **mArgs;

        std::list<CmdResolveResultI *> mProcess;

    public:
        friend CmdResolveProcess;

        Builder(Jchar **args, Jint argc);

        Builder &add(CmdResolveResultI *v);

        std::shared_ptr<CmdResolveProcess> build();
    };

    explicit CmdResolveProcess(Builder *builder);

    ~CmdResolveProcess();

    void notifyCmdHelp(CmdSets &v);

    void notifyCmdCheck(CmdSets &v);

    void notifyCmdX509(CmdSets &v);

    void notifyCmdSign(CmdSets &v);
};

CmdResolveProcess::Builder::Builder(Jchar **args, Jint argc)
        : mArgc{argc}
          , mArgs{args}
          , mProcess{}
{
}

CmdResolveProcess::Builder &CmdResolveProcess::Builder::add(CmdResolveResultI *v)
{
    this->mProcess.push_back(v);
    return (*this);
}

std::shared_ptr<CmdResolveProcess> CmdResolveProcess::Builder::build()
{
    return std::make_shared<CmdResolveProcess>(this);
}

CmdResolveProcess::CmdResolveProcess(Builder *builder)
        : mBuilder{builder}
          , mProcess{builder->mProcess}
          , mCmdSets{}
{
    Jint        i = 0;
    std::string tplt;

    for (i = 0; i < builder->mArgc; ++i)
    {
        tplt.clear();

        tplt.append(builder->mArgs[i]);
        auto &&point = tplt.find(S_LINK);
        if (point == std::string::npos)
        {
            this->mCmdSets.setKey(tplt.data());
            continue;
        }

        auto &&vPoint = point + 1;
        this->mCmdSets.setKeyAndValue(tplt.substr(0, point).data(), tplt.substr(vPoint).data());
    }

    if (this->mCmdSets.findKey(T_CMD_HELP))
        this->notifyCmdHelp(this->mCmdSets);
    else if (this->mCmdSets.findKey(T_CMD_CHECK))
        this->notifyCmdCheck(this->mCmdSets);
    else if (this->mCmdSets.findKey(T_CMD_CONFIG))
        this->notifyCmdX509(this->mCmdSets);
    else if (this->mCmdSets.findKey(T_CMD_SIGN))
        this->notifyCmdSign(this->mCmdSets);
}

CmdResolveProcess::~CmdResolveProcess()
{
    delete (this->mBuilder);
}

void CmdResolveProcess::notifyCmdHelp(CmdSets &v)
{
    for (auto &p : this->mProcess)
        p->cmdHelp(v);
}

void CmdResolveProcess::notifyCmdCheck(CmdSets &v)
{
    for (auto &p : this->mProcess)
        p->cmdCheck(v);
}

void CmdResolveProcess::notifyCmdX509(CmdSets &v)
{
    for (auto &p : this->mProcess)
        p->cmdX509(v);
}

void CmdResolveProcess::notifyCmdSign(CmdSets &v)
{
    for (auto &p : this->mProcess)
        p->cmdSign(v);
}

}

}

#endif //XCHENGSIGNAPK_CMDRESOLVEPROCESS_HPP

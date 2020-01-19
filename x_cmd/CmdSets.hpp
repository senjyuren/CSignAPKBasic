#pragma once

#ifndef XCHENGSIGNAPK_CMDSETS_HPP
#define XCHENGSIGNAPK_CMDSETS_HPP

namespace x
{

inline namespace xcheng
{

class CmdSets
{
private:
    std::list<CmdSet> mCmd;

public:
    CmdSets();

    CmdSets &setKeyAndValue(const Jchar *k, const Jchar *v);

    CmdSets &setKey(const Jchar *v);

    Jbool findKey(const Jchar *v);

    const Jchar *getValue(const Jchar *v);
};

CmdSets::CmdSets()
        : mCmd{}
{
}

CmdSets &CmdSets::setKeyAndValue(const Jchar *k, const Jchar *v)
{
    this->mCmd.emplace_back(k, v);
    return (*this);
}

CmdSets &CmdSets::setKey(const Jchar *v)
{
    this->mCmd.push_back(CmdSet().setKey(v));
    return (*this);
}

Jbool CmdSets::findKey(const Jchar *v)
{
    Jbool state = false;

    for (auto &cmd : this->mCmd)
    {
        if (cmd.getKey() != v)
            continue;

        state = true;
        break;
    }
    return state;
}

const Jchar *CmdSets::getValue(const Jchar *v)
{
    const Jchar *value = nullptr;

    for (auto &cmd : this->mCmd)
    {
        if (cmd.getKey() != v)
            continue;

        value = cmd.getValue().data();
        break;
    }
    return value;
}

}

}

#endif //XCHENGSIGNAPK_CMDSETS_HPP

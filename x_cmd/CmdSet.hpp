#pragma once

#ifndef XCHENGSIGNAPK_CMDSET_HPP
#define XCHENGSIGNAPK_CMDSET_HPP

namespace x
{

inline namespace xcheng
{

class CmdSet
{
private:
    std::string mK;
    std::string mV;

public:
    CmdSet();

    CmdSet(const Jchar *k, const Jchar *v);

    CmdSet &setKey(const Jchar *v);

    CmdSet &setValue(const Jchar *v);

    const std::string &getKey();

    const std::string &getValue();
};

CmdSet::CmdSet()
        : mK{}
          , mV{}
{
}

CmdSet::CmdSet(const Jchar *k, const Jchar *v)
        : mK{k}
          , mV{v}
{
}

CmdSet &CmdSet::setKey(const Jchar *v)
{
    this->mK.append(v);
    return (*this);
}

CmdSet &CmdSet::setValue(const Jchar *v)
{
    this->mV.append(v);
    return (*this);
}

const std::string &CmdSet::getKey()
{
    return this->mK;
}

const std::string &CmdSet::getValue()
{
    return this->mV;
}

}

}

#endif //XCHENGSIGNAPK_CMDSET_HPP

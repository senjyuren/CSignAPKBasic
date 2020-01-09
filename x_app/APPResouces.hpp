#pragma once

#ifndef XCHENGSIGNAPK_APPRESOUCES_HPP
#define XCHENGSIGNAPK_APPRESOUCES_HPP

namespace x
{

inline namespace xcheng
{

enum class RS
        : Juint
{
    APP_NAME,

    SIGN_TIPS,

    DIALOG_SIGNING_NAME,
};

class R
{
private:
    std::map<RS, std::string_view> mStrings;

    R();

    const Jchar *get(RS rs);

public:
    static R &getInstance();

    template<RS _Rs>
    static const Jchar *getString();
};

R::R()
        : mStrings()
{
    this->mStrings[RS::APP_NAME] = "签名应用";

    this->mStrings[RS::SIGN_TIPS] = "请将文件拖至此处";

    this->mStrings[RS::DIALOG_SIGNING_NAME] = "正在对应用进行签名";
}

const Jchar *R::get(RS rs)
{
    return this->mStrings[rs].data();
}

R &R::getInstance()
{
    static R *obj = nullptr;
    if (obj == nullptr)
        obj = new R();
    return (*obj);
}

template<RS _Rs>
const Jchar *R::getString()
{
    return R::getInstance().get(_Rs);
}

}

}

#endif //XCHENGSIGNAPK_APPRESOUCES_HPP

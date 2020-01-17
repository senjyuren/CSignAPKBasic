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
    SIGN_MENU_SIGN,
    SIGN_MENU_SETTING,
    SIGN_MENU_ABOUT,
    SIGN_MENU_SETTING_CITY,
    SIGN_MENU_SETTING_COMMON,
    SIGN_MENU_SETTING_EMAIL,
    SIGN_MENU_SETTING_COUNTRY,
    SIGN_MENU_SETTING_PROVINCE,
    SIGN_MENU_SETTING_ORGANIZATION,
    SIGN_MENU_SETTING_ORGANIZATION_UNIT,
    DIALOG_SIGNING_NAME,
};

enum class RR
        : Juint
{
    WINDOWS_ICO,
    POS_STATUS_GREEN,
    POS_STATUS_RED,
};

class R
{
private:
    std::map<RS, std::string_view> mStrings;
    std::map<RR, std::string_view> mSources;

    R();

    const Jchar *get(RS rs);

    const Jchar *get(RR rr);

public:
    static R &getInstance();

    template<RS _Rs>
    static const Jchar *getString();

    template<RR _Rr>
    static const Jchar *getSources();
};

R::R()
        : mStrings()
          , mSources{}
{
    this->mStrings[RS::APP_NAME]                            = "The Sign Application";
    this->mStrings[RS::SIGN_TIPS]                           = "Please move the APK file here.";
    this->mStrings[RS::SIGN_MENU_SIGN]                      = "SIGN";
    this->mStrings[RS::SIGN_MENU_SETTING]                   = "SETTING";
    this->mStrings[RS::SIGN_MENU_ABOUT]                     = "ABOUT";
    this->mStrings[RS::SIGN_MENU_SETTING_CITY]              = "City:";
    this->mStrings[RS::SIGN_MENU_SETTING_COMMON]            = "Common:";
    this->mStrings[RS::SIGN_MENU_SETTING_EMAIL]             = "Email:";
    this->mStrings[RS::SIGN_MENU_SETTING_COUNTRY]           = "Country:";
    this->mStrings[RS::SIGN_MENU_SETTING_PROVINCE]          = "Province:";
    this->mStrings[RS::SIGN_MENU_SETTING_ORGANIZATION]      = "Organization:";
    this->mStrings[RS::SIGN_MENU_SETTING_ORGANIZATION_UNIT] = "Organization Unit:";
    this->mStrings[RS::DIALOG_SIGNING_NAME]                 = "正在对应用进行签名";

    this->mSources[RR::WINDOWS_ICO]      = "images/a1.ico";
    this->mSources[RR::POS_STATUS_GREEN] = "images/green.png";
    this->mSources[RR::POS_STATUS_RED]   = "images/red.png";
}

const Jchar *R::get(RS rs)
{
    return this->mStrings[rs].data();
}

const Jchar *R::get(RR rr)
{
    return this->mSources[rr].data();
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

template<RR _Rr>
const Jchar *R::getSources()
{
    return R::getInstance().get(_Rr);
}

}

}

#endif //XCHENGSIGNAPK_APPRESOUCES_HPP

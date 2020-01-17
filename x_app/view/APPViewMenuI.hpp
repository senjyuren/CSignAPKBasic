#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWMENUI_HPP
#define XCHENGSIGNAPK_APPVIEWMENUI_HPP

namespace x
{

inline namespace xcheng
{

class APPViewMenuI
{
public:
    virtual ~APPViewMenuI();

    virtual void menuOnSignView() = 0;

    virtual void menuOnSettingView() = 0;

    virtual void menuOnAboutView() = 0;
};

APPViewMenuI::~APPViewMenuI() = default;

}

}

#endif //XCHENGSIGNAPK_APPVIEWMENUI_HPP

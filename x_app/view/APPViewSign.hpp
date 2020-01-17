#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWSIGN_HPP
#define XCHENGSIGNAPK_APPVIEWSIGN_HPP

namespace x
{

inline namespace xcheng
{

class APPViewSign
        : public APPViewActivity
          , public APPViewMenuI
{
private:
    APPViewSubSign    mSignM;
    APPViewSubSetting mSetnM;
    APPViewSubAbout   mAbotM;

    APPViewMenus mMenus;

public:
    APPViewSign();

    ~APPViewSign() override;

    void onCreate(QVBoxLayout *layout) override;

    void menuOnSignView() override;

    void menuOnSettingView() override;

    void menuOnAboutView() override;
};

APPViewSign::APPViewSign()
        : mSignM{}
          , mSetnM{}
          , mAbotM{}
          , mMenus{}
{
    this->mMenus.addMenuCallback(this);
}

APPViewSign::~APPViewSign()
{
    this->mMenus.removeMenuCallback(this);
    APPViewSubActionController::remove(nullptr);
}

void APPViewSign::onCreate(QVBoxLayout *layout)
{
    layout->addWidget(&this->mSignM);
    layout->addWidget(&this->mSetnM);
    layout->addWidget(&this->mAbotM);
    layout->addWidget(&this->mMenus);
    this->mSignM.setFixedSize(APPConfiguresAPP::SIGN_WIDTH, APPConfiguresAPP::SIGN_HEIGHT);
    this->mSetnM.setFixedSize(APPConfiguresAPP::SIGN_WIDTH, APPConfiguresAPP::SIGN_HEIGHT);
    this->mAbotM.setFixedSize(APPConfiguresAPP::SIGN_WIDTH, APPConfiguresAPP::SIGN_HEIGHT);
    this->mMenus.setFixedSize(APPConfiguresAPP::SIGN_MENU_WIDTH, APPConfiguresAPP::SIGN_MENU_HEIGHT);

    APPViewSubActionController::add(&this->mSignM);
    APPViewSubActionController::add(&this->mSetnM);
    APPViewSubActionController::add(&this->mAbotM);

    this->menuOnSignView();
}

void APPViewSign::menuOnSignView()
{
    UtilsLog::info("display the sign");
    APPViewSubActionController::enableOnlyOne(&this->mSignM);
}

void APPViewSign::menuOnSettingView()
{
    UtilsLog::info("display the setting");
    APPViewSubActionController::enableOnlyOne(&this->mSetnM);
}

void APPViewSign::menuOnAboutView()
{
    UtilsLog::info("display the about");
    APPViewSubActionController::enableOnlyOne(&this->mAbotM);
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWSIGN_HPP

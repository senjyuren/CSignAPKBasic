#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWMENUS_HPP
#define XCHENGSIGNAPK_APPVIEWMENUS_HPP

namespace x
{

inline namespace xcheng
{

class APPViewMenus
        : public QWidget
          , public APPViewLabelOnClickReleaseI
{
private:
    QHBoxLayout mRoot;
    QLabel      mPOSSignal;

    QHBoxLayout  mMenus;
    APPViewLabel mSignM;
    APPViewLabel mSetnM;
    APPViewLabel mAbotM;

    std::list<APPViewMenuI *> mViewMenus;

public:
    APPViewMenus();

    void clickRelease(APPViewLabel *ctx) override;

    void addMenuCallback(APPViewMenuI *menu);

    void removeMenuCallback(APPViewMenuI *menu);

    void callSignView();

    void callSettingView();

    void callAboutView();
};

APPViewMenus::APPViewMenus()
        : mRoot{this}
          , mPOSSignal{}
          , mMenus{}
          , mSignM{}
          , mSetnM{}
          , mAbotM{}
          , mViewMenus{}
{
    this->setObjectName("APPViewMenus");
    this->setStyleSheet("#APPViewMenus{background: #080808;border-top: 5px solid #585858}");

    this->mRoot.setMargin(8);
    this->mRoot.setSpacing(0);
    this->mRoot.setAlignment(Qt::AlignCenter);
    this->mRoot.addWidget(&this->mPOSSignal, 5);
    this->mRoot.addLayout(&this->mMenus, 5);

    this->mMenus.setAlignment(Qt::AlignCenter | Qt::AlignRight);
    this->mMenus.addWidget(&this->mSignM);
    this->mMenus.addWidget(&this->mSetnM);
    this->mMenus.addWidget(&this->mAbotM);

    this->mPOSSignal.setPixmap(QPixmap(R::getSources<RR::POS_STATUS_RED>()));
    this->mPOSSignal.setScaledContents(true);
    this->mPOSSignal.setFixedSize(APPConfiguresAPP::SIGN_MENU_WIDGET_SIZE, APPConfiguresAPP::SIGN_MENU_WIDGET_SIZE);

    this->mSignM.setText(R::getString<RS::SIGN_MENU_SIGN>());
    this->mSignM.setStyleSheet("color: #FFFFFF;border-top: 3px solid #585858;padding-top: 2px");
    this->mSignM.setAlignment(Qt::AlignCenter);
    this->mSignM.setFixedWidth(APPConfiguresAPP::SIGN_MENU_WIDGET_FONT_SIZE);

    this->mSetnM.setText(R::getString<RS::SIGN_MENU_SETTING>());
    this->mSetnM.setStyleSheet("color: #FFFFFF");
    this->mSetnM.setAlignment(Qt::AlignCenter);
    this->mSetnM.setFixedWidth(APPConfiguresAPP::SIGN_MENU_WIDGET_FONT_SIZE);

    this->mAbotM.setText(R::getString<RS::SIGN_MENU_ABOUT>());
    this->mAbotM.setStyleSheet("color: #FFFFFF");
    this->mAbotM.setAlignment(Qt::AlignCenter);
    this->mAbotM.setFixedWidth(APPConfiguresAPP::SIGN_MENU_WIDGET_FONT_SIZE);

    this->mSignM.setOnClickRelease(this);
    this->mSetnM.setOnClickRelease(this);
    this->mAbotM.setOnClickRelease(this);

    UtilsLog::info("menu view to initialization");
}

void APPViewMenus::clickRelease(APPViewLabel *ctx)
{
    this->mSignM.setStyleSheet("color: #FFFFFF");
    this->mSetnM.setStyleSheet("color: #FFFFFF");
    this->mAbotM.setStyleSheet("color: #FFFFFF");

    if (ctx == &this->mSignM)
    {
        this->callSignView();
        this->mSignM.setStyleSheet("color: #FFFFFF;border-top: 3px solid #585858;padding-top: 2px");
    } else if (ctx == &this->mSetnM)
    {
        this->callSettingView();
        this->mSetnM.setStyleSheet("color: #FFFFFF;border-top: 3px solid #585858;padding-top: 2px");
    } else if (ctx == &this->mAbotM)
    {
        this->callAboutView();
        this->mAbotM.setStyleSheet("color: #FFFFFF;border-top: 3px solid #585858;padding-top: 2px");
    }
}

void APPViewMenus::addMenuCallback(APPViewMenuI *menu)
{
    this->mViewMenus.push_back(menu);
}

void APPViewMenus::removeMenuCallback(APPViewMenuI *menu)
{
    this->mViewMenus.remove(menu);
}

void APPViewMenus::callSignView()
{
    for (auto &v : this->mViewMenus)
        v->menuOnSignView();
}

void APPViewMenus::callSettingView()
{
    for (auto &v : this->mViewMenus)
        v->menuOnSettingView();
}

void APPViewMenus::callAboutView()
{
    for (auto &v : this->mViewMenus)
        v->menuOnAboutView();
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWMENUS_HPP

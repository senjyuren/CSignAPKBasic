#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWSUBSETTING_HPP
#define XCHENGSIGNAPK_APPVIEWSUBSETTING_HPP

namespace x
{

inline namespace xcheng
{

class APPViewSubSetting
        : public QWidget
          , public APPViewSubActionI
          , public APPViewSubItemEditerI
{
private:
    QVBoxLayout mRoot;
    QHBoxLayout mProvinceAndCity;

    APPViewSubItemEditer mCity;
    APPViewSubItemEditer mCommon;
    APPViewSubItemEditer mEmail;
    APPViewSubItemEditer mCountry;
    APPViewSubItemEditer mProvince;
    APPViewSubItemEditer mOrganization;
    APPViewSubItemEditer mOrganizationUnit;

public:
    APPViewSubSetting();

    ~APPViewSubSetting() override;

    void disable() override;

    void enable() override;

    void notifyEdited(APPViewSubItemEditer *v) override;

    void saveAction();
};

APPViewSubSetting::APPViewSubSetting()
        : mRoot{this}
          , mProvinceAndCity{}
          , mCity{}
          , mCommon{}
          , mEmail{}
          , mCountry{}
          , mProvince{}
          , mOrganization{}
          , mOrganizationUnit{}
{
    this->mRoot.addWidget(&this->mCountry, 1);
    this->mRoot.addLayout(&this->mProvinceAndCity, 1);
    this->mRoot.addWidget(&this->mCommon, 1);
    this->mRoot.addWidget(&this->mEmail, 1);
    this->mRoot.addWidget(&this->mOrganization, 1);
    this->mRoot.addWidget(&this->mOrganizationUnit, 1);
    this->mRoot.setAlignment(Qt::AlignCenter);

    this->mProvinceAndCity.addWidget(&this->mProvince);
    this->mProvinceAndCity.addWidget(&this->mCity);

    this->mCity.add(this);
    this->mCommon.add(this);
    this->mEmail.add(this);
    this->mCountry.add(this);
    this->mProvince.add(this);
    this->mOrganization.add(this);
    this->mOrganizationUnit.add(this);

    this->mCity.setKAndV(
            R::getString<RS::SIGN_MENU_SETTING_CITY>(),
            APPConfigSignInfo::get<APPConfigSignTag::CITY>()
    );

    this->mCommon.setKAndV(
            R::getString<RS::SIGN_MENU_SETTING_COMMON>(),
            APPConfigSignInfo::get<APPConfigSignTag::COMMON>()
    );

    this->mEmail.setKAndV(
            R::getString<RS::SIGN_MENU_SETTING_EMAIL>(),
            APPConfigSignInfo::get<APPConfigSignTag::EMAIL>()
    );

    this->mCountry.setKAndV(
            R::getString<RS::SIGN_MENU_SETTING_COUNTRY>(),
            APPConfigSignInfo::get<APPConfigSignTag::COUNTRY>()
    );

    this->mProvince.setKAndV(
            R::getString<RS::SIGN_MENU_SETTING_PROVINCE>(),
            APPConfigSignInfo::get<APPConfigSignTag::PROVINCE>()
    );

    this->mOrganization.setKAndV(
            R::getString<RS::SIGN_MENU_SETTING_ORGANIZATION>(),
            APPConfigSignInfo::get<APPConfigSignTag::ORGANIZATION>()
    );

    this->mOrganizationUnit.setKAndV(
            R::getString<RS::SIGN_MENU_SETTING_ORGANIZATION_UNIT>(),
            APPConfigSignInfo::get<APPConfigSignTag::ORGANIZATION_UNIT>()
    );
}

APPViewSubSetting::~APPViewSubSetting()
{
    this->mCity.remove(this);
    this->mCommon.remove(this);
    this->mEmail.remove(this);
    this->mCountry.remove(this);
    this->mProvince.remove(this);
    this->mOrganization.remove(this);
    this->mOrganizationUnit.remove(this);
}

void APPViewSubSetting::disable()
{
    APPConfigManipulator::save();
    this->saveAction();
    this->setVisible(false);
}

void APPViewSubSetting::enable()
{
    APPConfigManipulator::save();
    this->saveAction();
    this->setVisible(true);
}

void APPViewSubSetting::notifyEdited(APPViewSubItemEditer *v)
{
    if (v == &this->mCity)
        UtilsLog::debug("user editing the %s", this->mCity.getKey());
    else if (v == &this->mCommon)
        UtilsLog::debug("user editing the %s", this->mCommon.getKey());
    else if (v == &this->mEmail)
        UtilsLog::debug("user editing the %s", this->mEmail.getKey());
    else if (v == &this->mCountry)
        UtilsLog::debug("user editing the %s", this->mCountry.getKey());
    else if (v == &this->mProvince)
        UtilsLog::debug("user editing the %s", this->mProvince.getKey());
    else if (v == &this->mOrganization)
        UtilsLog::debug("user editing the %s", this->mOrganization.getKey());
    else if (v == &this->mOrganizationUnit)
        UtilsLog::debug("user editing the %s", this->mOrganizationUnit.getKey());
}

void APPViewSubSetting::saveAction()
{
    APPConfigSignInfo::set<APPConfigSignTag::CITY>(this->mCity.getValue());
    APPConfigSignInfo::set<APPConfigSignTag::COMMON>(this->mCommon.getValue());
    APPConfigSignInfo::set<APPConfigSignTag::COUNTRY>(this->mCountry.getValue());
    APPConfigSignInfo::set<APPConfigSignTag::EMAIL>(this->mEmail.getValue());
    APPConfigSignInfo::set<APPConfigSignTag::PROVINCE>(this->mProvince.getValue());
    APPConfigSignInfo::set<APPConfigSignTag::ORGANIZATION>(this->mOrganization.getValue());
    APPConfigSignInfo::set<APPConfigSignTag::ORGANIZATION_UNIT>(this->mOrganizationUnit.getValue());
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWSUBSETTING_HPP

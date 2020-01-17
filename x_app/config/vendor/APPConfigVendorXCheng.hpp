#pragma once

#ifndef XCHENGSIGNAPK_APPCONFIGVENDORXCHENG_HPP
#define XCHENGSIGNAPK_APPCONFIGVENDORXCHENG_HPP

namespace x
{

inline namespace xcheng
{

class APPConfigVendorXCheng
        : public APPConfigSignInfoI
{
private:
    constexpr static Jchar D_CITY[]              = "PuDong";
    constexpr static Jchar D_COMMON[]            = "xcheng";
    constexpr static Jchar D_EMAIL[]             = "xcheng@xchengtech.com";
    constexpr static Jchar D_COUNTRY[]           = "CN";
    constexpr static Jchar D_ORGANIZATION[]      = "Xchengtech";
    constexpr static Jchar D_ORGANIZATION_UNIT[] = "SW";
    constexpr static Jchar D_PROVINCE[]          = "Shanghai";

    std::string mCity;
    std::string mCommon;
    std::string mEmail;
    std::string mCountry;
    std::string mOrganization;
    std::string mOrganizationUnit;
    std::string mProvince;

public:
    APPConfigVendorXCheng();

    const std::string &infoGetCity() override;

    const std::string &infoGetCommon() override;

    const std::string &infoGetEmail() override;

    const std::string &infoGetCountry() override;

    const std::string &infoGetOrganization() override;

    const std::string &infoGetOrganizationUnit() override;

    const std::string &infoGetProvince() override;

    APPConfigSignInfoI &infoSetCity(const std::string &v) override;

    APPConfigSignInfoI &infoSetCommon(const std::string &v) override;

    APPConfigSignInfoI &infoSetEmail(const std::string &v) override;

    APPConfigSignInfoI &infoSetCountry(const std::string &v) override;

    APPConfigSignInfoI &infoSetOrganization(const std::string &v) override;

    APPConfigSignInfoI &infoSetOrganizationUnit(const std::string &v) override;

    APPConfigSignInfoI &infoSetProvince(const std::string &v) override;
};

APPConfigVendorXCheng::APPConfigVendorXCheng()
        : mCity{D_CITY}
          , mCommon{D_COMMON}
          , mEmail{D_EMAIL}
          , mCountry{D_COUNTRY}
          , mOrganization{D_ORGANIZATION}
          , mOrganizationUnit{D_ORGANIZATION_UNIT}
          , mProvince{D_PROVINCE}
{
}

const std::string &APPConfigVendorXCheng::infoGetCity()
{
    return this->mCity;
}

const std::string &APPConfigVendorXCheng::infoGetCommon()
{
    return this->mCommon;
}

const std::string &APPConfigVendorXCheng::infoGetEmail()
{
    return this->mEmail;
}

const std::string &APPConfigVendorXCheng::infoGetCountry()
{
    return this->mCountry;
}

const std::string &APPConfigVendorXCheng::infoGetOrganization()
{
    return this->mOrganization;
}

const std::string &APPConfigVendorXCheng::infoGetOrganizationUnit()
{
    return this->mOrganizationUnit;
}

const std::string &APPConfigVendorXCheng::infoGetProvince()
{
    return this->mProvince;
}

APPConfigSignInfoI &APPConfigVendorXCheng::infoSetCity(const std::string &v)
{
    this->mCity = v;
    return (*this);
}

APPConfigSignInfoI &APPConfigVendorXCheng::infoSetCommon(const std::string &v)
{
    this->mCommon = v;
    return (*this);
}

APPConfigSignInfoI &APPConfigVendorXCheng::infoSetEmail(const std::string &v)
{
    this->mEmail = v;
    return (*this);
}

APPConfigSignInfoI &APPConfigVendorXCheng::infoSetCountry(const std::string &v)
{
    this->mCountry = v;
    return (*this);
}

APPConfigSignInfoI &APPConfigVendorXCheng::infoSetOrganization(const std::string &v)
{
    this->mOrganization = v;
    return (*this);
}

APPConfigSignInfoI &APPConfigVendorXCheng::infoSetOrganizationUnit(const std::string &v)
{
    this->mOrganizationUnit = v;
    return (*this);
}

APPConfigSignInfoI &APPConfigVendorXCheng::infoSetProvince(const std::string &v)
{
    this->mProvince = v;
    return (*this);
}

}

}

#endif //XCHENGSIGNAPK_APPCONFIGVENDORXCHENG_HPP

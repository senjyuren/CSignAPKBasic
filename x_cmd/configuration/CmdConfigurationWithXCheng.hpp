#pragma once

#ifndef XCHENGSIGNAPK_CMDCONFIGURATIONWITHXCHENG_HPP
#define XCHENGSIGNAPK_CMDCONFIGURATIONWITHXCHENG_HPP

namespace x
{

inline namespace xcheng
{

class CmdConfigurationWithXCheng
        : public CmdConfigurationI
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
    std::string mCountry;
    std::string mEmail;
    std::string mProvince;
    std::string mOrganization;
    std::string mOrganizationUnit;

public:
    CmdConfigurationWithXCheng();

    const std::string &infoGetCity() override;

    const std::string &infoGetCommon() override;

    const std::string &infoGetEmail() override;

    const std::string &infoGetCountry() override;

    const std::string &infoGetOrganization() override;

    const std::string &infoGetOrganizationUnit() override;

    const std::string &infoGetProvince() override;

    CmdConfigurationI &infoSetCity(const Jchar *v) override;

    CmdConfigurationI &infoSetCommon(const Jchar *v) override;

    CmdConfigurationI &infoSetEmail(const Jchar *v) override;

    CmdConfigurationI &infoSetCountry(const Jchar *v) override;

    CmdConfigurationI &infoSetOrganization(const Jchar *v) override;

    CmdConfigurationI &infoSetOrganizationUnit(const Jchar *v) override;

    CmdConfigurationI &infoSetProvince(const Jchar *v) override;
};

CmdConfigurationWithXCheng::CmdConfigurationWithXCheng()
        : mCity{D_CITY}
          , mCommon{D_COMMON}
          , mCountry{D_COUNTRY}
          , mEmail{D_EMAIL}
          , mProvince{D_PROVINCE}
          , mOrganization{D_ORGANIZATION}
          , mOrganizationUnit{D_ORGANIZATION_UNIT}
{
}

const std::string &CmdConfigurationWithXCheng::infoGetCity()
{
    return this->mCity;
}

const std::string &CmdConfigurationWithXCheng::infoGetCommon()
{
    return this->mCommon;
}

const std::string &CmdConfigurationWithXCheng::infoGetEmail()
{
    return this->mEmail;
}

const std::string &CmdConfigurationWithXCheng::infoGetCountry()
{
    return this->mCountry;
}

const std::string &CmdConfigurationWithXCheng::infoGetOrganization()
{
    return this->mOrganization;
}

const std::string &CmdConfigurationWithXCheng::infoGetOrganizationUnit()
{
    return this->mOrganizationUnit;
}

const std::string &CmdConfigurationWithXCheng::infoGetProvince()
{
    return this->mProvince;
}

CmdConfigurationI &CmdConfigurationWithXCheng::infoSetCity(const Jchar *v)
{
    this->mCity = v;
    return (*this);
}

CmdConfigurationI &CmdConfigurationWithXCheng::infoSetCommon(const Jchar *v)
{
    this->mCommon = v;
    return (*this);
}

CmdConfigurationI &CmdConfigurationWithXCheng::infoSetEmail(const Jchar *v)
{
    this->mEmail = v;
    return (*this);
}

CmdConfigurationI &CmdConfigurationWithXCheng::infoSetCountry(const Jchar *v)
{
    this->mCountry = v;
    return (*this);
}

CmdConfigurationI &CmdConfigurationWithXCheng::infoSetOrganization(const Jchar *v)
{
    this->mOrganization = v;
    return (*this);
}

CmdConfigurationI &CmdConfigurationWithXCheng::infoSetOrganizationUnit(const Jchar *v)
{
    this->mOrganizationUnit = v;
    return (*this);
}

CmdConfigurationI &CmdConfigurationWithXCheng::infoSetProvince(const Jchar *v)
{
    this->mProvince = v;
    return (*this);
}

}

}

#endif //XCHENGSIGNAPK_CMDCONFIGURATIONWITHXCHENG_HPP

#pragma once

#ifndef XCHENGSIGNAPK_APPCONFIGSIGNINFOI_HPP
#define XCHENGSIGNAPK_APPCONFIGSIGNINFOI_HPP

namespace x
{

inline namespace xcheng
{

class APPConfigSignInfoI
{
public:
    virtual ~APPConfigSignInfoI();

    virtual const std::string &infoGetCity() = 0;

    virtual const std::string &infoGetCommon() = 0;

    virtual const std::string &infoGetEmail() = 0;

    virtual const std::string &infoGetCountry() = 0;

    virtual const std::string &infoGetOrganization() = 0;

    virtual const std::string &infoGetOrganizationUnit() = 0;

    virtual const std::string &infoGetProvince() = 0;

    virtual APPConfigSignInfoI &infoSetCity(const std::string &v) = 0;

    virtual APPConfigSignInfoI &infoSetCommon(const std::string &v) = 0;

    virtual APPConfigSignInfoI &infoSetEmail(const std::string &v) = 0;

    virtual APPConfigSignInfoI &infoSetCountry(const std::string &v) = 0;

    virtual APPConfigSignInfoI &infoSetOrganization(const std::string &v) = 0;

    virtual APPConfigSignInfoI &infoSetOrganizationUnit(const std::string &v) = 0;

    virtual APPConfigSignInfoI &infoSetProvince(const std::string &v) = 0;
};

APPConfigSignInfoI::~APPConfigSignInfoI() = default;

}

}

#endif //XCHENGSIGNAPK_APPCONFIGSIGNINFOI_HPP

#pragma once

#ifndef XCHENGSIGNAPK_CMDCONFIGURATIONI_HPP
#define XCHENGSIGNAPK_CMDCONFIGURATIONI_HPP

namespace x
{

inline namespace xcheng
{

class CmdConfigurationI
{
public:
    virtual ~CmdConfigurationI();

    virtual const std::string &infoGetCity() = 0;

    virtual const std::string &infoGetCommon() = 0;

    virtual const std::string &infoGetEmail() = 0;

    virtual const std::string &infoGetCountry() = 0;

    virtual const std::string &infoGetOrganization() = 0;

    virtual const std::string &infoGetOrganizationUnit() = 0;

    virtual const std::string &infoGetProvince() = 0;

    virtual CmdConfigurationI &infoSetCity(const Jchar *v) = 0;

    virtual CmdConfigurationI &infoSetCommon(const Jchar *v) = 0;

    virtual CmdConfigurationI &infoSetEmail(const Jchar *v) = 0;

    virtual CmdConfigurationI &infoSetCountry(const Jchar *v) = 0;

    virtual CmdConfigurationI &infoSetOrganization(const Jchar *v) = 0;

    virtual CmdConfigurationI &infoSetOrganizationUnit(const Jchar *v) = 0;

    virtual CmdConfigurationI &infoSetProvince(const Jchar *v) = 0;
};

CmdConfigurationI::~CmdConfigurationI() = default;

}

}

#endif //XCHENGSIGNAPK_CMDCONFIGURATIONI_HPP

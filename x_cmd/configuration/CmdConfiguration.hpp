#pragma once

#ifndef XCHENGSIGNAPK_CMDCONFIGURATION_HPP
#define XCHENGSIGNAPK_CMDCONFIGURATION_HPP

#include "CmdConfigurationType.hpp"
#include "CmdConfigurationI.hpp"
#include "CmdConfigurationWithXCheng.hpp"

namespace x
{

inline namespace xcheng
{

class CmdConfiguration
{
private:
    constexpr static Jint CACHE_SIZE = 1024;

    constexpr static Jchar F_CONFIG[] = "./config.json";

    constexpr static Jchar K_CITY[]              = "City";
    constexpr static Jchar K_COUNTRY[]           = "Country";
    constexpr static Jchar K_COMMON[]            = "Common";
    constexpr static Jchar K_EMAIL[]             = "Email";
    constexpr static Jchar K_PROVINCE[]          = "Province";
    constexpr static Jchar K_OGRANIZATION[]      = "Ogranization";
    constexpr static Jchar K_OGRANIZATION_UNIT[] = "OgranizationUnit";

    CmdConfigurationI *mConfig;

    QJsonDocument mJsonDoc;
    QJsonObject   mJsonObj;
    QByteArray    mJsonData;

    Jchar mCache[CACHE_SIZE];

    CmdConfiguration();

public:
    static CmdConfiguration &getInstance();

    static void save();

    static void load();

    static const Jchar *read();

    template<CmdConfigurationType _Type>
    static void set(const Jchar *v);

    template<CmdConfigurationType _Type>
    static const Jchar *get();

    void saveConfig();

    void loadConfig();

    const Jchar *readConfig();

    void set(CmdConfigurationType type, const Jchar *v);

    const Jchar *get(CmdConfigurationType type);
};

CmdConfiguration::CmdConfiguration()
        : mConfig{new CmdConfigurationWithXCheng()}
          , mJsonDoc{}
          , mJsonObj{}
          , mJsonData{}
          , mCache{}
{
}

CmdConfiguration &CmdConfiguration::getInstance()
{
    static CmdConfiguration *obj = nullptr;
    if (obj == nullptr)
        obj = new CmdConfiguration();
    return (*obj);
}

void CmdConfiguration::save()
{
    CmdConfiguration::getInstance().saveConfig();
}

void CmdConfiguration::load()
{
    CmdConfiguration::getInstance().loadConfig();
}

const Jchar *CmdConfiguration::read()
{
    return CmdConfiguration::getInstance().readConfig();
}

template<CmdConfigurationType _Type>
void CmdConfiguration::set(const Jchar *v)
{
    CmdConfiguration::getInstance().set(_Type, v);
    return (*this);
}

template<CmdConfigurationType _Type>
const Jchar *CmdConfiguration::get()
{
    return CmdConfiguration::getInstance().get(_Type);
}

void CmdConfiguration::saveConfig()
{
    this->mJsonObj.insert(K_CITY, this->get(CmdConfigurationType::CITY));
    this->mJsonObj.insert(K_COUNTRY, this->get(CmdConfigurationType::COUNTRY));
    this->mJsonObj.insert(K_COMMON, this->get(CmdConfigurationType::COMMON));
    this->mJsonObj.insert(K_EMAIL, this->get(CmdConfigurationType::EMAIL));
    this->mJsonObj.insert(K_PROVINCE, this->get(CmdConfigurationType::PROVINCE));
    this->mJsonObj.insert(K_OGRANIZATION, this->get(CmdConfigurationType::OGRANIZATION));
    this->mJsonObj.insert(K_OGRANIZATION_UNIT, this->get(CmdConfigurationType::OGRANIZATION_UNIT));
    this->mJsonDoc.setObject(this->mJsonObj);
    this->mJsonData = this->mJsonDoc.toJson();

    std::ofstream file(F_CONFIG, (std::ios::out | std::ios::binary));
    if (file.is_open())
        file.write(this->mJsonData.data(), this->mJsonData.size());

    file.close();
}

void CmdConfiguration::loadConfig()
{
    std::ifstream config;

    if (!std::filesystem::exists(F_CONFIG))
        return;

    config.open(F_CONFIG, (std::ios::in | std::ios::binary));
    this->mJsonData.clear();

    do
    {
        config.read(this->mCache, sizeof(this->mCache));
        this->mJsonData.append(this->mCache, config.gcount());
    } while (config.gcount() == sizeof(this->mCache));

    config.close();
    this->mJsonDoc = QJsonDocument::fromJson(this->mJsonData, nullptr);
    this->mJsonObj = this->mJsonDoc.object();

    this->set(
            CmdConfigurationType::CITY,
            this->mJsonObj.value(K_CITY).toString().toStdString().c_str()
    );

    this->set(
            CmdConfigurationType::COMMON,
            this->mJsonObj.value(K_COMMON).toString().toStdString().c_str()
    );

    this->set(
            CmdConfigurationType::COUNTRY,
            this->mJsonObj.value(K_COUNTRY).toString().toStdString().c_str()
    );

    this->set(
            CmdConfigurationType::PROVINCE,
            this->mJsonObj.value(K_PROVINCE).toString().toStdString().c_str()
    );

    this->set(
            CmdConfigurationType::EMAIL,
            this->mJsonObj.value(K_EMAIL).toString().toStdString().c_str()
    );

    this->set(
            CmdConfigurationType::OGRANIZATION,
            this->mJsonObj.value(K_OGRANIZATION).toString().toStdString().c_str()
    );

    this->set(
            CmdConfigurationType::OGRANIZATION_UNIT,
            this->mJsonObj.value(K_OGRANIZATION_UNIT).toString().toStdString().c_str()
    );
}

const Jchar *CmdConfiguration::readConfig()
{
    this->mJsonObj.insert(K_CITY, this->get(CmdConfigurationType::CITY));
    this->mJsonObj.insert(K_COUNTRY, this->get(CmdConfigurationType::COUNTRY));
    this->mJsonObj.insert(K_COMMON, this->get(CmdConfigurationType::COMMON));
    this->mJsonObj.insert(K_EMAIL, this->get(CmdConfigurationType::EMAIL));
    this->mJsonObj.insert(K_PROVINCE, this->get(CmdConfigurationType::PROVINCE));
    this->mJsonObj.insert(K_OGRANIZATION, this->get(CmdConfigurationType::OGRANIZATION));
    this->mJsonObj.insert(K_OGRANIZATION_UNIT, this->get(CmdConfigurationType::OGRANIZATION_UNIT));
    this->mJsonDoc.setObject(this->mJsonObj);
    this->mJsonData = this->mJsonDoc.toJson();
    return this->mJsonData.toStdString().c_str();
}

void CmdConfiguration::set(CmdConfigurationType type, const Jchar *v)
{
    if (type == CmdConfigurationType::CITY)
        this->mConfig->infoSetCity(v);
    else if (type == CmdConfigurationType::COMMON)
        this->mConfig->infoSetCommon(v);
    else if (type == CmdConfigurationType::COUNTRY)
        this->mConfig->infoSetCountry(v);
    else if (type == CmdConfigurationType::EMAIL)
        this->mConfig->infoSetEmail(v);
    else if (type == CmdConfigurationType::PROVINCE)
        this->mConfig->infoSetProvince(v);
    else if (type == CmdConfigurationType::OGRANIZATION)
        this->mConfig->infoSetOrganization(v);
    else
        this->mConfig->infoSetOrganizationUnit(v);
}

const Jchar *CmdConfiguration::get(CmdConfigurationType type)
{
    if (type == CmdConfigurationType::CITY)
        return this->mConfig->infoGetCity().c_str();
    else if (type == CmdConfigurationType::COMMON)
        return this->mConfig->infoGetCommon().c_str();
    else if (type == CmdConfigurationType::COUNTRY)
        return this->mConfig->infoGetCountry().c_str();
    else if (type == CmdConfigurationType::EMAIL)
        return this->mConfig->infoGetEmail().c_str();
    else if (type == CmdConfigurationType::PROVINCE)
        return this->mConfig->infoGetProvince().c_str();
    else if (type == CmdConfigurationType::OGRANIZATION)
        return this->mConfig->infoGetOrganization().c_str();
    else
        return this->mConfig->infoGetOrganizationUnit().c_str();
}

}

}

#endif //XCHENGSIGNAPK_CMDCONFIGURATION_HPP

#pragma once

#ifndef XCHENGSIGNAPK_APPCONFIGSIGNINFO_HPP
#define XCHENGSIGNAPK_APPCONFIGSIGNINFO_HPP

namespace x
{

inline namespace xcheng
{

class APPConfigSignInfo
        : public APPConfigOperatingI
{
private:
    constexpr static Jint CACHE_SIZE = 1024;

    constexpr static Jchar D_CONFIG_FILE[] = "./sign_info.json";

    constexpr static Jchar G_X509[] = "x509";

    constexpr static Jchar V_CITY[]              = "City";
    constexpr static Jchar V_COMMON[]            = "Common";
    constexpr static Jchar V_EMAIL[]             = "Email";
    constexpr static Jchar V_COUNTRY[]           = "Country";
    constexpr static Jchar V_ORGANIZATION[]      = "Organization";
    constexpr static Jchar V_ORGANIZATION_UNIT[] = "OrganizationUnit";
    constexpr static Jchar V_PROVINCE[]          = "Province";

    std::unique_ptr<APPConfigSignInfoI> mInfo;

    QByteArray    mJsonData;
    QJsonObject   mJsonObject;
    QJsonDocument mJsonDocument;
    QJsonObject   mJsonX509;
    Jchar         mCache[CACHE_SIZE];

    APPConfigSignInfo();

public:
    static APPConfigSignInfo &getInstance();

    Jbool check() override;

    Jbool save() override;

    Jbool read() override;

    template<APPConfigSignTag _Tag>
    static const Jchar *get();

    template<APPConfigSignTag _Tag>
    static void set(const Jchar *v);

    const Jchar *get(APPConfigSignTag tag);

    void set(APPConfigSignTag tag, const Jchar *v);
};

APPConfigSignInfo::APPConfigSignInfo()
        : mInfo{new APPConfigVendorXCheng()}
          , mJsonData{}
          , mJsonObject{}
          , mJsonDocument{}
          , mJsonX509{}
          , mCache{}
{
}

APPConfigSignInfo &APPConfigSignInfo::getInstance()
{
    static APPConfigSignInfo *obj = nullptr;
    if (obj == nullptr)
        obj = new APPConfigSignInfo();
    return (*obj);
}

Jbool APPConfigSignInfo::check()
{
    this->mJsonData.clear();
    if (std::filesystem::exists(D_CONFIG_FILE))
    {
        std::ifstream config(D_CONFIG_FILE, (std::ios::in | std::ios::binary));

        do
        {
            config.read(this->mCache, sizeof(this->mCache));
            this->mJsonData.append(this->mCache, config.gcount());
        } while (config.gcount() == sizeof(this->mCache));

        this->mJsonDocument = QJsonDocument::fromJson(this->mJsonData, nullptr);
        this->mJsonX509     = this->mJsonDocument.object();
        this->mJsonObject   = this->mJsonX509.value(G_X509).toObject();

        this->set(
                APPConfigSignTag::CITY,
                this->mJsonObject.value(V_CITY).toString().toStdString().c_str()
        );
        this->set(
                APPConfigSignTag::COUNTRY,
                this->mJsonObject.value(V_COUNTRY).toString().toStdString().c_str()
        );
        this->set(
                APPConfigSignTag::PROVINCE,
                this->mJsonObject.value(V_PROVINCE).toString().toStdString().c_str()
        );
        this->set(
                APPConfigSignTag::COMMON,
                this->mJsonObject.value(V_COMMON).toString().toStdString().c_str()
        );
        this->set(
                APPConfigSignTag::EMAIL,
                this->mJsonObject.value(V_EMAIL).toString().toStdString().c_str()
        );
        this->set(
                APPConfigSignTag::ORGANIZATION,
                this->mJsonObject.value(V_ORGANIZATION).toString().toStdString().c_str()
        );
        this->set(
                APPConfigSignTag::ORGANIZATION_UNIT,
                this->mJsonObject.value(V_ORGANIZATION_UNIT).toString().toStdString().c_str()
        );

        config.close();
    } else
    {
        std::ofstream config(D_CONFIG_FILE, (std::ios::out | std::ios::binary));

        this->mJsonObject.insert(V_CITY, this->get(APPConfigSignTag::CITY));
        this->mJsonObject.insert(V_COUNTRY, this->get(APPConfigSignTag::COUNTRY));
        this->mJsonObject.insert(V_PROVINCE, this->get(APPConfigSignTag::PROVINCE));
        this->mJsonObject.insert(V_EMAIL, this->get(APPConfigSignTag::EMAIL));
        this->mJsonObject.insert(V_COMMON, this->get(APPConfigSignTag::COMMON));
        this->mJsonObject.insert(V_ORGANIZATION, this->get(APPConfigSignTag::ORGANIZATION));
        this->mJsonObject.insert(V_ORGANIZATION_UNIT, this->get(APPConfigSignTag::ORGANIZATION_UNIT));

        this->mJsonX509.insert(G_X509, this->mJsonObject);
        this->mJsonDocument.setObject(this->mJsonX509);
        this->mJsonData = this->mJsonDocument.toJson();

        config.write(this->mJsonData.data(), this->mJsonData.size());
        config.close();
    }

    UtilsLog::debug("|------------------------------- Current Configuration Start -------------------------------|");
    UtilsLog::debug("City: %s", this->get(APPConfigSignTag::CITY));
    UtilsLog::debug("Country: %s", this->get(APPConfigSignTag::COUNTRY));
    UtilsLog::debug("Province: %s", this->get(APPConfigSignTag::PROVINCE));
    UtilsLog::debug("Email: %s", this->get(APPConfigSignTag::EMAIL));
    UtilsLog::debug("Common: %s", this->get(APPConfigSignTag::COMMON));
    UtilsLog::debug("Organization: %s", this->get(APPConfigSignTag::ORGANIZATION));
    UtilsLog::debug("Organization Unit: %s", this->get(APPConfigSignTag::ORGANIZATION_UNIT));
    UtilsLog::debug("|-------------------------------- Current Configuration End --------------------------------|");
    return true;
}

Jbool APPConfigSignInfo::save()
{
    std::ofstream config(D_CONFIG_FILE, (std::ios::out | std::ios::binary));

    this->mJsonObject.insert(V_CITY, this->get(APPConfigSignTag::CITY));
    this->mJsonObject.insert(V_COUNTRY, this->get(APPConfigSignTag::COUNTRY));
    this->mJsonObject.insert(V_PROVINCE, this->get(APPConfigSignTag::PROVINCE));
    this->mJsonObject.insert(V_EMAIL, this->get(APPConfigSignTag::EMAIL));
    this->mJsonObject.insert(V_COMMON, this->get(APPConfigSignTag::COMMON));
    this->mJsonObject.insert(V_ORGANIZATION, this->get(APPConfigSignTag::ORGANIZATION));
    this->mJsonObject.insert(V_ORGANIZATION_UNIT, this->get(APPConfigSignTag::ORGANIZATION_UNIT));

    this->mJsonX509.insert(G_X509, this->mJsonObject);
    this->mJsonDocument.setObject(this->mJsonX509);
    this->mJsonData = this->mJsonDocument.toJson();

    config.write(this->mJsonData.data(), this->mJsonData.size());
    config.close();
    return true;
}

Jbool APPConfigSignInfo::read()
{
    return this->check();
}

template<APPConfigSignTag _Tag>
const Jchar *APPConfigSignInfo::get()
{
    return APPConfigSignInfo::getInstance().get(_Tag);
}

template<APPConfigSignTag _Tag>
void APPConfigSignInfo::set(const Jchar *v)
{
    APPConfigSignInfo::getInstance().set(_Tag, v);
}

const Jchar *APPConfigSignInfo::get(APPConfigSignTag tag)
{
    if (tag == APPConfigSignTag::CITY)
        return this->mInfo->infoGetCity().c_str();
    else if (tag == APPConfigSignTag::COMMON)
        return this->mInfo->infoGetCommon().c_str();
    else if (tag == APPConfigSignTag::EMAIL)
        return this->mInfo->infoGetEmail().c_str();
    else if (tag == APPConfigSignTag::COUNTRY)
        return this->mInfo->infoGetCountry().c_str();
    else if (tag == APPConfigSignTag::ORGANIZATION)
        return this->mInfo->infoGetOrganization().c_str();
    else if (tag == APPConfigSignTag::ORGANIZATION_UNIT)
        return this->mInfo->infoGetOrganizationUnit().c_str();
    else
        return this->mInfo->infoGetProvince().c_str();
}

void APPConfigSignInfo::set(APPConfigSignTag tag, const Jchar *v)
{
    if (tag == APPConfigSignTag::CITY)
        this->mInfo->infoSetCity(v);
    else if (tag == APPConfigSignTag::COMMON)
        this->mInfo->infoSetCommon(v);
    else if (tag == APPConfigSignTag::EMAIL)
        this->mInfo->infoSetEmail(v);
    else if (tag == APPConfigSignTag::COUNTRY)
        this->mInfo->infoSetCountry(v);
    else if (tag == APPConfigSignTag::ORGANIZATION)
        this->mInfo->infoSetOrganization(v);
    else if (tag == APPConfigSignTag::ORGANIZATION_UNIT)
        this->mInfo->infoSetOrganizationUnit(v);
    else
        this->mInfo->infoSetProvince(v);
}

}

}

#endif //XCHENGSIGNAPK_APPCONFIGSIGNINFO_HPP

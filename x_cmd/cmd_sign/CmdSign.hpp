#pragma once

#ifndef XCHENGSIGNAPK_CMDSIGN_HPP
#define XCHENGSIGNAPK_CMDSIGN_HPP

namespace x
{

inline namespace xcheng
{

class CmdSign
{
public:
    class Builder;

private:
    constexpr static Jchar TEST_PUB_KEY[] =
                                   "-----BEGIN RSA PUBLIC KEY-----\n"
                                   "MIIBCgKCAQEAqeA2foi9PTtcS6mEznVZ5mmqAk37VkpkM2vBdjRZpa/60E50YSKg\n"
                                   "bKUIk2i6VHLKg3snjLZ8MAAjU0H0rKfE0gNWlsfcfLF/9anaiKsUxgzfNgs2JS9F\n"
                                   "H9sf7hZzNqF1wd5fSCX4EJSUuHdTEC4zGObXhFkZXa81AauLqNDmHn2C18nzqPWl\n"
                                   "xFz3dPB77POikTatS/oJgDqL/MCzH7YinicySQ0Ypf/LjC+xPlCRhkDVWmajR3zg\n"
                                   "PZtGGjPQsWgCFJq61j44hHSybZhczzocr3amzQPYJJEAJuSKIjexRgW+/qgaRhXT\n"
                                   "te+yRkLZngFxhLzS7TJFcyWms5e28rocgwIDAQAB\n"
                                   "-----END RSA PUBLIC KEY-----";

    constexpr static Jchar TEST_PRI_KEY[] =
                                   "-----BEGIN RSA PRIVATE KEY-----\n"
                                   "MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQCp4DZ+iL09O1xL\n"
                                   "qYTOdVnmaaoCTftWSmQza8F2NFmlr/rQTnRhIqBspQiTaLpUcsqDeyeMtnwwACNT\n"
                                   "QfSsp8TSA1aWx9x8sX/1qdqIqxTGDN82CzYlL0Uf2x/uFnM2oXXB3l9IJfgQlJS4\n"
                                   "d1MQLjMY5teEWRldrzUBq4uo0OYefYLXyfOo9aXEXPd08Hvs86KRNq1L+gmAOov8\n"
                                   "wLMftiKeJzJJDRil/8uML7E+UJGGQNVaZqNHfOA9m0YaM9CxaAIUmrrWPjiEdLJt\n"
                                   "mFzPOhyvdqbNA9gkkQAm5IoiN7FGBb7+qBpGFdO177JGQtmeAXGEvNLtMkVzJaaz\n"
                                   "l7byuhyDAgMBAAECggEBAKGgvdiom30uBIPM15pkV1P+Rw6ISdHxV+MA7IJeDsmx\n"
                                   "ZW9apiphesfEQiOW6mo9CegNfjTIz+IPz4yA3Z6ExaSYHoO5x1QwwjHoGRAdztcd\n"
                                   "GidehXbdweQsZfXvEFHzT4pU3M1Vqu+DnvjgN3zWqDFSOc4nxBW6BTIAmRHXKIvq\n"
                                   "i9Vj7nBjbkXuD8xG2pQuNhoEXY/x35QbJmknTInHqqhtx+mS4xh2TU4V404qt+0O\n"
                                   "Oj03oszRQrlYqrOgxVWZuMoYk4LvKYJ3S9aUd6weFwHfn1xzZ7/RO58ICYxwCbGT\n"
                                   "Rf+ME1Fvkg++AlQfNrinWhoZX9tdXTgSJq/ko6WBTjECgYEA3S17x8HEbmuPTdN1\n"
                                   "tHxB2cynrVsi0iS36dOMeOIgJ0qpfgw1SBaqR4RBJS1WlI4pq4JeBOB5WHJWA2en\n"
                                   "WDU/nEFsWyYRwfWsEWxLJCPUtYfKOFfZcfsK5EA48ZO252KRRnHSjIGLT711aoFr\n"
                                   "7Hu8tH1MCzLiwbhyz2jkC3UeJ4sCgYEAxJ8FLhkmGIE0V8knGMQzowEWqhnoDhF7\n"
                                   "ByOiTlyGNet3sTGrKhNIswJIJgs2VshRZiw42bNjfJVdCAUkR+HcEPTNzAoCDRzs\n"
                                   "ADmbj9w5XdgC8CJtjWTIeAlBsyJFVPXr99J3uxQMk5UoESHNhnnLPIQde75pPt+t\n"
                                   "/T9IdLwUPekCgYBPcogU7/hURZSbOwr7wuqQhp/weF0gqQnbFx9NSMSN+Ja7bT0y\n"
                                   "YNnXiJ0x8oA4KnyzW8fT7qIH8EIPRQtqdu4bfbCjaSBV0J53P7QaDjjY4Cb2aC/2\n"
                                   "bluyM5OAyzOXF+PhLv+Xcu0MvpxPnp+aubPGDX/kQeoL9epfsGjB6NblEwKBgAa7\n"
                                   "ey3s5oUIR4aJ+LC8Zxg5vVDtuihhKNlBuxj7ygyml16V2MqEBoU6msXStHWcPk1F\n"
                                   "Tl0F624knx7bLjbX4PUjrLhDz3Yre1k2n8D5RW2VK+SVCTNCNCsIBhvgHIegNAg0\n"
                                   "SK07LoMPJGQRyDvGh9L2oxvNlUT127tEI3L7zaWhAoGAIfFclp2i/7TXr/R07kQ4\n"
                                   "ucYqz2yq61+354mkppkW56JsYCqom8S1/VVMwPwCuAxJGhGy/S03kW6N63u3qMAo\n"
                                   "iVLUM8fvoPwCrcgM8yLHl3Vt36xLXxS3+ckibelKZHjMR1VvA3KWGWjGgy4555fH\n"
                                   "ce5GWWG5ljMNle7zFhkJqY4=\n"
                                   "-----END RSA PRIVATE KEY-----";

    constexpr static Jchar CMD_IN[]  = "in";
    constexpr static Jchar CMD_OUT[] = "out";

    Builder *mBuilder;

public:
    class Builder
    {
    private:
        CmdSets mCmd;

    public:
        friend CmdSign;

        Builder();

        Builder &setCommandSets(CmdSets &v);

        std::shared_ptr<CmdSign> build();
    };

    explicit CmdSign(Builder *v);

    ~CmdSign();
};

CmdSign::Builder::Builder()
        : mCmd{}
{
}

CmdSign::Builder &CmdSign::Builder::setCommandSets(CmdSets &v)
{
    this->mCmd = v;
    return (*this);
}

std::shared_ptr<CmdSign> CmdSign::Builder::build()
{
    return std::make_shared<CmdSign>(this);
}

CmdSign::CmdSign(CmdSign::Builder *v)
        : mBuilder{v}
{
    const Jchar *outPath = nullptr;
    auto        &&cmd    = v->mCmd;

    if (!cmd.findKey(CMD_IN))
        return;

    if (!cmd.findKey(CMD_OUT))
        outPath = cmd.getValue(CMD_IN);
    else
        outPath = cmd.getValue(CMD_OUT);

    auto &&apk = m::LibrarySignAPK::build(nullptr);
    apk->apkInputAPKPath(cmd.getValue(CMD_IN))
            .apkOutputPath(outPath)
            .apkPrivateKey(TEST_PRI_KEY)
            .apkPublicKey(TEST_PUB_KEY)
            .apkCity(CmdConfiguration::get<CmdConfigurationType::CITY>())
            .apkCommon(CmdConfiguration::get<CmdConfigurationType::COMMON>())
            .apkEmail(CmdConfiguration::get<CmdConfigurationType::EMAIL>())
            .apkCountry(CmdConfiguration::get<CmdConfigurationType::COUNTRY>())
            .apkOrganization(CmdConfiguration::get<CmdConfigurationType::OGRANIZATION>())
            .apkOrganizationUnit(CmdConfiguration::get<CmdConfigurationType::OGRANIZATION_UNIT>())
            .apkProvince(CmdConfiguration::get<CmdConfigurationType::PROVINCE>())
            .apkSign();

    m::LibrarySignAPK::destroy(apk);
}

CmdSign::~CmdSign()
{
    delete (this->mBuilder);
}

}

}

#endif //XCHENGSIGNAPK_CMDSIGN_HPP

#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWSUBSIGN_HPP
#define XCHENGSIGNAPK_APPVIEWSUBSIGN_HPP

namespace x
{

inline namespace xcheng
{

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

class APPViewSubSign
        : public QWidget
          , public APPViewSubActionI
{
private:
    QVBoxLayout              mRoot;
    QLabel                   mTips;
    std::vector<std::string> mPaths;

public:
    APPViewSubSign();

    void dragEnterEvent(QDragEnterEvent *event) override;

    void dropEvent(QDropEvent *event) override;

    void disable() override;

    void enable() override;
};

APPViewSubSign::APPViewSubSign()
        : mRoot{this}
          , mTips{}
          , mPaths{}
{
    this->setAcceptDrops(true);

    this->mRoot.addWidget(&this->mTips);
    this->mRoot.setAlignment(Qt::AlignCenter);

    this->mTips.setText(R::getString<RS::SIGN_TIPS>());
    this->mTips.setAlignment(Qt::AlignCenter);
    this->mTips.setStyleSheet("color: #FFFFFF");
}

void APPViewSubSign::dragEnterEvent(QDragEnterEvent *event)
{
    UtilsLog::info("listen a message, user move a APK on view");
    event->acceptProposedAction();
}

void APPViewSubSign::dropEvent(QDropEvent *event)
{
    auto &&paths = event->mimeData()->urls();
    if (paths.empty())
        return;

    for (const auto &v : paths)
        this->mPaths.push_back(v.toLocalFile().toStdString());

    for (auto &v : this->mPaths)
        UtilsLog::debug("move apk path: %s", v.c_str());

    std::thread([](std::vector<std::string> *files) {
        Jint i = 0;

        for (i = 0; i < static_cast<Jint>(files->size()); ++i)
        {
            auto &&path = (*files)[i].c_str();
            auto &&apk  = m::LibrarySignAPK::build(nullptr);
            apk->apkInputAPKPath(path)
                    .apkOutputPath(path)
                    .apkPrivateKey(TEST_PRI_KEY)
                    .apkPublicKey(TEST_PUB_KEY)
                    .apkCity(APPConfigSignInfo::get<APPConfigSignTag::CITY>())
                    .apkCommon(APPConfigSignInfo::get<APPConfigSignTag::COMMON>())
                    .apkEmail(APPConfigSignInfo::get<APPConfigSignTag::EMAIL>())
                    .apkCountry(APPConfigSignInfo::get<APPConfigSignTag::COUNTRY>())
                    .apkOrganization(APPConfigSignInfo::get<APPConfigSignTag::ORGANIZATION>())
                    .apkOrganizationUnit(APPConfigSignInfo::get<APPConfigSignTag::ORGANIZATION_UNIT>())
                    .apkProvince(APPConfigSignInfo::get<APPConfigSignTag::PROVINCE>())
                    .apkSign();
            m::LibrarySignAPK::destroy(apk);
        }

        APPDialogLauncher<APPDialogSigning>::getInstance().close();
        UtilsLog::info("the all apk is signed");
    }, &this->mPaths).detach();

    APPDialogLauncher<APPDialogSigning>::getInstance().show();
}

void APPViewSubSign::disable()
{
    this->setVisible(false);
}

void APPViewSubSign::enable()
{
    this->setVisible(true);
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWSUBSIGN_HPP

#pragma once

#ifndef XCHENGSIGNAPK_APPCONFIGURES_HPP
#define XCHENGSIGNAPK_APPCONFIGURES_HPP

namespace x
{

inline namespace xcheng
{

class APPConfiguresVersion
{
public:
    constexpr static Jchar APP_BUILD_TIME[]   = "Build #Time January 16, 2020";
    constexpr static Jchar APP_VERSION[]      = "Verison v0.0.1";
    constexpr static Jchar APP_ORGANIZATION[] = "Copyright © 2019 - 2020 the XCheng Tech";
    constexpr static Jchar APP_POWERED_BY[]   =
                                   "Powered by:\r\n"
                                   "QT5                         LGPL\r\n"
                                   "Jemalloc\r\n"
                                   "ZLib";
};

class APPConfiguresAPP
{
public:
    constexpr static Jint APP_WIDTH  = 800;
    constexpr static Jint APP_HEIGHT = 600;

    constexpr static Jint TITLE_WIDTH       = APP_WIDTH;
    constexpr static Jint TITLE_HEIGHT      = 40;
    constexpr static Jint TITLE_WIDGET_SIZE = 20;

    constexpr static Jint CONTENT_WIDTH  = APP_WIDTH;
    constexpr static Jint CONTENT_HEIGHT = APP_HEIGHT - TITLE_HEIGHT;

    constexpr static Jint SIGN_MENU_WIDTH            = APP_WIDTH;
    constexpr static Jint SIGN_MENU_HEIGHT           = 60;
    constexpr static Jint SIGN_MENU_WIDGET_SIZE      = 20;
    constexpr static Jint SIGN_MENU_WIDGET_FONT_SIZE = 60;

    constexpr static Jint SIGN_WIDTH  = APP_WIDTH;
    constexpr static Jint SIGN_HEIGHT = APP_HEIGHT - TITLE_HEIGHT - SIGN_MENU_HEIGHT;
};

class APPConfiguresDialogSigning
{
public:
    constexpr static Jint DIALOG_WIDTH  = 300;
    constexpr static Jint DIALOG_HEIGHT = 100;
};

}

}

#endif //XCHENGSIGNAPK_APPCONFIGURES_HPP

#pragma once

#ifndef XCHENGSIGNAPK_CMDHELP_HPP
#define XCHENGSIGNAPK_CMDHELP_HPP

namespace x
{

inline namespace xcheng
{

class CmdHelp
{
private:
    constexpr static Jchar TEMPLATE[] =
                                   "[help]  - It might help you.\n"
                                   "[check] - Checking if terminal exsit.\n"
                                   "[config]\n"
                                   "        - create    - Create a configuration file, give you to modify it.\n"
                                   "        - look      - You can see default configuration in application.\n"
                                   "[sign]\n"
                                   "        - in=[file]     - You need fill APK path.\n"
                                   "        - out=[path]    - If you not fill a path in here, it's output directory is the same as the input directory.\n"
                                   "        - import=[file] - Import the configuration file, if your application path has the \"config.json\" file, the application will use it, if not the application will use default configuration in application. You can to use the \"look\" command to see it.\n";

public:
    CmdHelp();
};

CmdHelp::CmdHelp()
{
    printf(TEMPLATE);
}

}

}

#endif //XCHENGSIGNAPK_CMDHELP_HPP

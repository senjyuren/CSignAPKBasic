#include "Kernal.hpp"

constexpr Jchar APP_EXE_CMD_MOD[] = "cmd";

Jint main(Jint argc, Jchar *argv[])
{
    if ((argc > 2) && x::UtilsString::equals(argv[1], APP_EXE_CMD_MOD))
        std::unique_ptr<x::CmdApplication> app(new x::CmdApplication(argv, argc));
    else
        std::unique_ptr<x::APPApplication> app(new x::APPApplication(argv, argc));
    return 0;
}

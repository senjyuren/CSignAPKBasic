#include "Kernal.hpp"

Jint main(Jint argc, Jchar *argv[])
{
    std::unique_ptr<x::APPApplication> app(new x::APPApplication(argv, argc));
    return 0;
}

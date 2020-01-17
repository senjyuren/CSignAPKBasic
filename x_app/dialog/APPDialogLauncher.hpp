#pragma once

#ifndef XCHENGSIGNAPK_APPDIALOGLAUNCHER_HPP
#define XCHENGSIGNAPK_APPDIALOGLAUNCHER_HPP

namespace x
{

inline namespace xcheng
{

template <typename T>
class APPDialogLauncher;

template<>
class APPDialogLauncher<APPDialogSigning>
{
private:
    std::unique_ptr<QDialog> mDialog;

    APPDialogLauncher();

public:
    static APPDialogLauncher &getInstance();

    void show();

    void close();
};

APPDialogLauncher<APPDialogSigning>::APPDialogLauncher()
        : mDialog{new APPDialogSigning()}
{
}

APPDialogLauncher<APPDialogSigning> &APPDialogLauncher<APPDialogSigning>::getInstance()
{
    static APPDialogLauncher *obj = nullptr;
    if (obj == nullptr)
        obj = new APPDialogLauncher();
    return (*obj);
}

void APPDialogLauncher<APPDialogSigning>::show()
{
    this->mDialog->exec();
}

void APPDialogLauncher<APPDialogSigning>::close()
{
    this->mDialog->close();
}

}

}

#endif //XCHENGSIGNAPK_APPDIALOGLAUNCHER_HPP

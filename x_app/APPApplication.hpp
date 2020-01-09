#pragma once

#ifndef XCHENGSIGNAPK_APPAPPLICATION_HPP
#define XCHENGSIGNAPK_APPAPPLICATION_HPP

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

#include <QtGui/QDrag>
#include <QtGui/QDropEvent>

#include <QtCore/QList>
#include <QtCore/QMimeData>

#include "APPResouces.hpp"
#include "APPConfigures.hpp"

#include "dialog/APPDialogSigning.hpp"
#include "dialog/APPDialogLauncher.hpp"
#include "dialog/APPDialogLauncherWithSigning.hpp"

#include "view/APPViewSign.hpp"

namespace x
{

inline namespace xcheng
{

class APPApplication
{
private:
    QApplication mApp;

public:
    APPApplication(Jchar **argv, Jint argc);
};

APPApplication::APPApplication(Jchar **argv, Jint argc)
        : mApp{argc, argv}
{
    std::unique_ptr<QWidget> main(new APPViewSign());
    main->show();
    QApplication::exec();
}

}

}

#endif //XCHENGSIGNAPK_APPAPPLICATION_HPP

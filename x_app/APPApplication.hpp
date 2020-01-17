#pragma once

#ifndef XCHENGSIGNAPK_APPAPPLICATION_HPP
#define XCHENGSIGNAPK_APPAPPLICATION_HPP

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

#include <QtGui/QIcon>
#include <QtGui/QDrag>
#include <QtGui/QDropEvent>

#include <QtCore/QList>
#include <QtCore/QMimeData>
#include <QtCore/QSettings>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>

#include "APPResouces.hpp"
#include "APPConfigures.hpp"
#include "config/APPConfig.hpp"
#include "dialog/APPDialog.hpp"
#include "view/APPView.hpp"

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
    UtilsLog::info("checking the configure");
    // 检查配置
    APPConfigManipulator::add(&APPConfigSignInfo::getInstance());
    APPConfigManipulator::check();

    UtilsLog::info("application ready to run");
    std::unique_ptr<QWidget> main(new APPViewSign());
    main->show();
    QApplication::exec();
}

}

}

#endif //XCHENGSIGNAPK_APPAPPLICATION_HPP

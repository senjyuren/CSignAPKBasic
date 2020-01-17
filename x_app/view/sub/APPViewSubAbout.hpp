#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWSUBABOUT_HPP
#define XCHENGSIGNAPK_APPVIEWSUBABOUT_HPP

namespace x
{

inline namespace xcheng
{

class APPViewSubAbout
        : public QWidget
          , public APPViewSubActionI
{
private:
    QVBoxLayout mRoot;
    QLabel      mStatement;

    std::string mStatementContent;

public:
    APPViewSubAbout();

    void disable() override;

    void enable() override;
};

APPViewSubAbout::APPViewSubAbout()
        : mRoot{this}
          , mStatement{}
          , mStatementContent{}
{
    this->mRoot.addWidget(&this->mStatement);
    this->mRoot.setAlignment(Qt::AlignCenter);

    this->mStatementContent.append(APPConfiguresVersion::APP_BUILD_TIME)
            .append("\r\n\r\n")
            .append(APPConfiguresVersion::APP_VERSION)
            .append("\r\n\r\n")
            .append(APPConfiguresVersion::APP_ORGANIZATION)
            .append("\r\n\r\n")
            .append(APPConfiguresVersion::APP_POWERED_BY);

    this->mStatement.setText(this->mStatementContent.c_str());
    this->mStatement.setStyleSheet("color: #FFFFFF");
}

void APPViewSubAbout::disable()
{
    this->setVisible(false);
}

void APPViewSubAbout::enable()
{
    this->setVisible(true);
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWSUBABOUT_HPP

#pragma once

#ifndef XCHENGSIGNAPK_APPDIALOGSIGNING_HPP
#define XCHENGSIGNAPK_APPDIALOGSIGNING_HPP

namespace x
{

inline namespace xcheng
{

class APPDialogSigning
        : public QDialog
{
private:
    QVBoxLayout mRoot;
    QLabel      mTips;

public:
    explicit APPDialogSigning(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::Popup);

    void showEvent(QShowEvent *event) override;
};

APPDialogSigning::APPDialogSigning(QWidget *, Qt::WindowFlags)
        : mRoot{this}
          , mTips{}
{
    this->setFixedWidth(APPConfiguresDialogSigning::DIALOG_WIDTH);
    this->setFixedHeight(APPConfiguresDialogSigning::DIALOG_HEIGHT);
}

void APPDialogSigning::showEvent(QShowEvent *)
{
    this->mRoot.addWidget(&this->mTips);
    this->mTips.setText(R::getString<RS::DIALOG_SIGNING_NAME>());
    this->mTips.setAlignment(Qt::AlignCenter);
}

}

}

#endif //XCHENGSIGNAPK_APPDIALOGSIGNING_HPP

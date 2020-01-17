#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWACTIVITY_HPP
#define XCHENGSIGNAPK_APPVIEWACTIVITY_HPP

namespace x
{

inline namespace xcheng
{

class APPViewActivity
        : public QWidget
{
private:
    QVBoxLayout    mRoot;
    APPViewTitle   mTitle;
    APPViewContent mContent;

public:
    explicit APPViewActivity(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    void showEvent(QShowEvent *event) override;

    virtual void onCreate(QVBoxLayout *layout) = 0;
};

APPViewActivity::APPViewActivity(QWidget *, Qt::WindowFlags f)
        : mRoot{this}
          , mTitle{this, APPConfiguresAPP::TITLE_WIDTH, APPConfiguresAPP::TITLE_HEIGHT}
          , mContent{APPConfiguresAPP::CONTENT_WIDTH, APPConfiguresAPP::CONTENT_HEIGHT}
{
    this->setWindowFlags(f | Qt::FramelessWindowHint);
    this->setWindowIcon(QIcon(R::getSources<RR::WINDOWS_ICO>()));
    this->setFixedSize(APPConfiguresAPP::APP_WIDTH, APPConfiguresAPP::APP_HEIGHT);
}

void APPViewActivity::showEvent(QShowEvent *)
{
    this->mRoot.addWidget(&this->mTitle);
    this->mRoot.addWidget(&this->mContent);
    this->mRoot.setMargin(0);
    this->mRoot.setSpacing(0);

    this->onCreate(&const_cast<QVBoxLayout &>(this->mContent.getLayout()));
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWACTIVITY_HPP

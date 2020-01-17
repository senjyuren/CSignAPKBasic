#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWTITLE_HPP
#define XCHENGSIGNAPK_APPVIEWTITLE_HPP

namespace x
{

inline namespace xcheng
{

class APPViewTitle
        : public QWidget
{
private:
    QWidget *mContext;

    QHBoxLayout mRoot;
    QLabel      mIcon;
    QLineEdit   mTitle;
    QPushButton mMinimize;
    QPushButton mClose;

    Jbool  isMoveStatus;
    QPoint mMovePoint;

public:
    explicit APPViewTitle(QWidget *context, Jint width, Jint height);

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;
};

APPViewTitle::APPViewTitle(QWidget *context, Jint width, Jint height)
        : mContext{context}
          , mRoot{this}
          , mIcon{}
          , mTitle{}
          , mMinimize{}
          , mClose{}
          , isMoveStatus{}
          , mMovePoint{}
{
    this->setFixedSize(width, height);
    this->setStyleSheet("background: #080808");

    this->mRoot.addWidget(&this->mIcon);
    this->mRoot.addWidget(&this->mTitle);
    this->mRoot.addWidget(&this->mMinimize);
    this->mRoot.addWidget(&this->mClose);
    this->mRoot.setAlignment(Qt::AlignCenter);

    this->mIcon.setPixmap(QPixmap(R::getSources<RR::WINDOWS_ICO>()));
    this->mIcon.setScaledContents(true);
    this->mIcon.setFixedSize(APPConfiguresAPP::TITLE_WIDGET_SIZE, APPConfiguresAPP::TITLE_WIDGET_SIZE);

    this->mTitle.setText(R::getString<RS::APP_NAME>());
    this->mTitle.setEnabled(false);
    this->mTitle.setAlignment(Qt::AlignCenter);
    this->mTitle.setStyleSheet("border-radius: 0px;color: #FFFFFF");

    this->mMinimize.setText("-");
    this->mMinimize.setFixedSize(APPConfiguresAPP::TITLE_WIDGET_SIZE, APPConfiguresAPP::TITLE_WIDGET_SIZE);
    this->mMinimize.setStyleSheet("color: #FFFFFF;font-weight: bold");

    this->mClose.setText("X");
    this->mClose.setFixedSize(APPConfiguresAPP::TITLE_WIDGET_SIZE, APPConfiguresAPP::TITLE_WIDGET_SIZE);
    this->mClose.setStyleSheet("color: #FFFFFF;font-weight: bold");

    QApplication::connect(&this->mMinimize, &QPushButton::clicked, this, [context](bool) {
        context->showMinimized();
    });

    QApplication::connect(&this->mClose, &QPushButton::clicked, this, [context](bool) {
        context->close();
    });
}

void APPViewTitle::mousePressEvent(QMouseEvent *event)
{
    do
    {
        if (this->isMoveStatus)
            break;

        this->mMovePoint   = event->globalPos();
        this->isMoveStatus = true;
    } while (false);

    QWidget::mousePressEvent(event);
}

void APPViewTitle::mouseMoveEvent(QMouseEvent *event)
{
    do
    {
        if ((!this->isMoveStatus) || (event->button() == Qt::LeftButton))
            break;

        this->mContext->move(this->mContext->geometry().topLeft() + event->globalPos() - this->mMovePoint);
        this->mMovePoint = event->globalPos();
    } while (false);

    QWidget::mouseMoveEvent(event);
}

void APPViewTitle::mouseReleaseEvent(QMouseEvent *event)
{
    if (this->isMoveStatus)
        this->isMoveStatus = false;

    QWidget::mouseReleaseEvent(event);
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWTITLE_HPP

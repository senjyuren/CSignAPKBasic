#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWCONTENT_HPP
#define XCHENGSIGNAPK_APPVIEWCONTENT_HPP

namespace x
{

inline namespace xcheng
{

class APPViewContent
        : public QWidget
{
private:
    QVBoxLayout mRoot;

public:
    APPViewContent(Jint width, Jint height);

    const QVBoxLayout &getLayout();
};

APPViewContent::APPViewContent(Jint width, Jint height)
        : mRoot{this}
{
    this->setFixedSize(width,height);
    this->mRoot.setMargin(0);
    this->mRoot.setSpacing(0);
    this->setObjectName("APPViewContent");
    this->setStyleSheet("#APPViewContent{background: #080808;border-top: 5px solid #585858}");
}

const QVBoxLayout &APPViewContent::getLayout()
{
    return this->mRoot;
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWCONTENT_HPP

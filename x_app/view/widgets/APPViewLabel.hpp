#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWLABEL_HPP
#define XCHENGSIGNAPK_APPVIEWLABEL_HPP

namespace x
{

inline namespace xcheng
{

class APPViewLabel
        : public QLabel
{
private:
    APPViewLabelOnClickReleaseI *mRelease;

public:
    APPViewLabel();

    void setOnClickRelease(APPViewLabelOnClickReleaseI *release);

    void mouseReleaseEvent(QMouseEvent *ev) override;
};

APPViewLabel::APPViewLabel()
        : mRelease{}
{
}

void APPViewLabel::setOnClickRelease(APPViewLabelOnClickReleaseI *release)
{
    this->mRelease = release;
}

void APPViewLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    do
    {
        if (ev->button() != Qt::LeftButton)
            break;
        if (this->mRelease == nullptr)
            break;

        this->mRelease->clickRelease(this);
    } while (false);

    QLabel::mouseReleaseEvent(ev);
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWLABEL_HPP

#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWSUBITEMEDITER_HPP
#define XCHENGSIGNAPK_APPVIEWSUBITEMEDITER_HPP

namespace x
{

inline namespace xcheng
{

class APPViewSubItemEditer
        : public QWidget
{
private:
    QVBoxLayout mRoot;
    QLabel      mK;
    QLineEdit   mV;

    std::list<APPViewSubItemEditerI *> mListeners;

public:
    APPViewSubItemEditer();

    void setKAndV(const Jchar *k, const Jchar *v);

    const Jchar *getKey();

    const Jchar *getValue();

    void add(APPViewSubItemEditerI *v);

    void remove(APPViewSubItemEditerI *v);

    void notifyEdited(APPViewSubItemEditer *v);
};

APPViewSubItemEditer::APPViewSubItemEditer()
        : mRoot{this}
          , mK{}
          , mV{}
          , mListeners{}
{
    this->mRoot.addWidget(&this->mK);
    this->mRoot.addWidget(&this->mV);
    this->mRoot.setAlignment(Qt::AlignCenter);

    this->mK.setStyleSheet("color: #FFFFFF");
    this->mV.setStyleSheet("color: #FFFFFF;background: #080808;border: 1px solid #989898;padding: 5px");

    QApplication::connect(&this->mV, &QLineEdit::editingFinished, this, [this]() {
        this->notifyEdited(this);
    });
}

void APPViewSubItemEditer::setKAndV(const Jchar *k, const Jchar *v)
{
    if (k != nullptr)
        this->mK.setText(k);
    if (v != nullptr)
        this->mV.setText(v);
}

const Jchar *APPViewSubItemEditer::getKey()
{
    return this->mK.text().toUtf8().data();
}

const Jchar *APPViewSubItemEditer::getValue()
{
    return this->mV.text().toUtf8().data();
}

void APPViewSubItemEditer::add(APPViewSubItemEditerI *v)
{
    this->mListeners.push_back(v);
}

void APPViewSubItemEditer::remove(APPViewSubItemEditerI *v)
{
    if (v == nullptr)
        this->mListeners.clear();
    else
        this->mListeners.remove(v);
}

void APPViewSubItemEditer::notifyEdited(APPViewSubItemEditer *v)
{
    for (auto &listen : this->mListeners)
        listen->notifyEdited(v);
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWSUBITEMEDITER_HPP

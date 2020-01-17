#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWSUBACTIONCONTROLLER_HPP
#define XCHENGSIGNAPK_APPVIEWSUBACTIONCONTROLLER_HPP

namespace x
{

inline namespace xcheng
{

class APPViewSubActionController
{
private:
    std::list<APPViewSubActionI *> mActions;

    APPViewSubActionController();

public:
    static APPViewSubActionController &getInstance();

    static void add(APPViewSubActionI *v);

    static void remove(APPViewSubActionI *v);

    static void disableOnlyOne(APPViewSubActionI *v);

    static void enableOnlyOne(APPViewSubActionI *v);

    APPViewSubActionController &addObj(APPViewSubActionI *v);

    APPViewSubActionController &removeObj(APPViewSubActionI *v);

    APPViewSubActionController &disableObj(APPViewSubActionI *v);

    APPViewSubActionController &enableObj(APPViewSubActionI *v);
};

APPViewSubActionController::APPViewSubActionController()
        : mActions{}
{
}

APPViewSubActionController &APPViewSubActionController::getInstance()
{
    static APPViewSubActionController *obj = nullptr;
    if (obj == nullptr)
        obj = new APPViewSubActionController();
    return (*obj);
}

void APPViewSubActionController::add(APPViewSubActionI *v)
{
    APPViewSubActionController::getInstance().addObj(v);
}

void APPViewSubActionController::remove(APPViewSubActionI *v)
{
    APPViewSubActionController::getInstance().removeObj(v);
}

void APPViewSubActionController::disableOnlyOne(APPViewSubActionI *v)
{
    APPViewSubActionController::getInstance().disableObj(v);
}

void APPViewSubActionController::enableOnlyOne(APPViewSubActionI *v)
{
    APPViewSubActionController::getInstance().enableObj(v);
}

APPViewSubActionController &APPViewSubActionController::addObj(APPViewSubActionI *v)
{
    this->mActions.push_back(v);
    return (*this);
}

APPViewSubActionController &APPViewSubActionController::removeObj(APPViewSubActionI *v)
{
    if (v == nullptr)
        this->mActions.clear();
    else
        this->mActions.remove(v);
    return (*this);
}

APPViewSubActionController &APPViewSubActionController::disableObj(APPViewSubActionI *v)
{
    for (auto &action : this->mActions)
    {
        if (action == v)
            action->disable();
        else
            action->enable();
    }
    return (*this);
}

APPViewSubActionController &APPViewSubActionController::enableObj(APPViewSubActionI *v)
{
    for (auto &action : this->mActions)
    {
        if (action == v)
            action->enable();
        else
            action->disable();
    }
    return (*this);
}

}

}

#endif //XCHENGSIGNAPK_APPVIEWSUBACTIONCONTROLLER_HPP

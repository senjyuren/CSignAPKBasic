#pragma once

#ifndef XCHENGSIGNAPK_APPCONFIGMANIPULATOR_HPP
#define XCHENGSIGNAPK_APPCONFIGMANIPULATOR_HPP

namespace x
{

class APPConfigManipulator
{
private:
    std::list<APPConfigOperatingI *> mOperator;

    APPConfigManipulator();

public:
    static APPConfigManipulator &getInstance();

    static void add(APPConfigOperatingI *v);

    static void remove(APPConfigOperatingI *v);

    static Jbool check();

    static Jbool save();

    static Jbool read();

    APPConfigManipulator &addObj(APPConfigOperatingI *v);

    APPConfigManipulator &removeObj(APPConfigOperatingI *v);

    Jbool checkAllObj();

    Jbool saveAllObj();

    Jbool readAllObj();
};

APPConfigManipulator::APPConfigManipulator()
        : mOperator{}
{
}

APPConfigManipulator &APPConfigManipulator::getInstance()
{
    static APPConfigManipulator *obj = nullptr;
    if (obj == nullptr)
        obj = new APPConfigManipulator();
    return (*obj);
}

void APPConfigManipulator::add(APPConfigOperatingI *v)
{
    APPConfigManipulator::getInstance().addObj(v);
}

void APPConfigManipulator::remove(APPConfigOperatingI *v)
{
    APPConfigManipulator::getInstance().removeObj(v);
}

Jbool APPConfigManipulator::check()
{
    return APPConfigManipulator::getInstance().checkAllObj();
}

Jbool APPConfigManipulator::save()
{
    return APPConfigManipulator::getInstance().saveAllObj();
}

Jbool APPConfigManipulator::read()
{
    return APPConfigManipulator::getInstance().readAllObj();
}

APPConfigManipulator &APPConfigManipulator::addObj(APPConfigOperatingI *v)
{
    this->mOperator.push_back(v);
    return (*this);
}

APPConfigManipulator &APPConfigManipulator::removeObj(APPConfigOperatingI *v)
{
    if (v == nullptr)
        this->mOperator.clear();
    else
        this->mOperator.remove(v);
    return (*this);
}

Jbool APPConfigManipulator::checkAllObj()
{
    Jbool state = true;

    for (auto &v : this->mOperator)
    {
        if (!v->check())
            state = false;
    }
    return state;
}

Jbool APPConfigManipulator::saveAllObj()
{
    Jbool state = true;

    for (auto &v : this->mOperator)
    {
        if (!v->save())
            state = false;
    }
    return state;
}

Jbool APPConfigManipulator::readAllObj()
{
    Jbool state = true;

    for (auto &v : this->mOperator)
    {
        if (!v->read())
            state = false;
    }
    return state;
}

}

#endif //XCHENGSIGNAPK_APPCONFIGMANIPULATOR_HPP

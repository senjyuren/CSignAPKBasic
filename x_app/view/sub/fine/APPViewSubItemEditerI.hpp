#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWSUBITEMEDITERI_HPP
#define XCHENGSIGNAPK_APPVIEWSUBITEMEDITERI_HPP

namespace x
{

inline namespace xcheng
{

class APPViewSubItemEditer;

class APPViewSubItemEditerI
{
public:
    virtual ~APPViewSubItemEditerI();

    virtual void notifyEdited(APPViewSubItemEditer *v) = 0;
};

APPViewSubItemEditerI::~APPViewSubItemEditerI() = default;

}

}

#endif //XCHENGSIGNAPK_APPVIEWSUBITEMEDITERI_HPP

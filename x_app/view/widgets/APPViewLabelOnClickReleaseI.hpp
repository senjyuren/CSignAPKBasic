#pragma once

#ifndef XCHENGSIGNAPK_APPVIEWLABELONCLICKRELEASEI_HPP
#define XCHENGSIGNAPK_APPVIEWLABELONCLICKRELEASEI_HPP

namespace x
{

inline namespace xcheng
{

class APPViewLabel;

class APPViewLabelOnClickReleaseI
{
public:
    virtual ~APPViewLabelOnClickReleaseI();

    virtual void clickRelease(APPViewLabel *ctx) = 0;
};

APPViewLabelOnClickReleaseI::~APPViewLabelOnClickReleaseI() = default;

}

}

#endif //XCHENGSIGNAPK_APPVIEWLABELONCLICKRELEASEI_HPP

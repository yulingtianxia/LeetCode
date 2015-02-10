//
//  29	Divide Two Integers.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int divide(int64_t dividend, int64_t divisor) {
        bool positive=dividend<0^divisor<0?false:true;
        dividend=abs(dividend);
        divisor=abs(divisor);
        int64_t res=0;
        int64_t factor=divisor;
        int64_t time=1;
        while (dividend>=factor) {
            factor<<=1;
            time<<=1;
            if (dividend<factor) {
                dividend-=factor>>1;
                time>>=1;
                factor=divisor;
                res+=time;
                time=1;
            }
        }
        if (!positive) {
            res=-res;
        }
        res=res>INT_MAX?INT_MAX:res<INT_MIN?INT_MIN:res;
        return res;
    }
};
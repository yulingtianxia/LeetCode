//
//  190	Reverse Bits.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/19.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int i=0;
        while (i<32) {
            result<<=1;
            result+=n&1;
            n>>=1;
            i++;
        }
        return result;
    }
};

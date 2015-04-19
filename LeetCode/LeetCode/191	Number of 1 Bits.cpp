//
//  191	Number of 1 Bits.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/19.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            n&=n-1;
            count++;
        }
        return count;
    }
};

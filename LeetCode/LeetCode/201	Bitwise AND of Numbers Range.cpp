//
//  201	Bitwise AND of Numbers Range.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/21.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int range = n-m+1;
        if (range==1) {
            return n;
        }
        int bitsize = ceil(log2(n));
        int result=0;
        for (int i=0; i<bitsize; i++) {
            if (range<=pow(2, i)&&(m&(1<<i))!=0&&(n&(1<<i))!=0) {
                result|=1<<i;
            }
        }
        return result;
    }
};

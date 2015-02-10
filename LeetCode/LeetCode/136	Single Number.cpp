//
//  136	Single Number.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int singleNumber(int A[], int n) {
        int bit = 0;
        for (int i=0; i<n; i++) {
            bit^=A[i];
        }
        return bit;
    }
};
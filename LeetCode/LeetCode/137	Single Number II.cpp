//
//  137	Single Number II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones=0,twos=0;
        for(int i=0;i<n;i++){
            ones=(ones^A[i])&~twos;
            twos=(twos^A[i])&~ones;
        }
        return ones;
    }
};
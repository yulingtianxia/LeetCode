//
//  172	Factorial Trailing Zeroes.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int trailingZeroes(int n) {
        if (n==0) {
            return 0;
        }
        int count=0;
        int i=0;
        while (++i) {
            int temp=n/pow(5, i);
            if (temp>0) {
                count+=temp;
            }
            else{
                break;
            }
        }
        return count;
    }
};
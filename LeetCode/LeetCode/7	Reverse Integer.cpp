//
//  7	Reverse Integer.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int reverse(int x) {
        short flag = x>0? 1:-1;
        int X = abs(x);
        int res = 0;
        while(X){
            if((flag && (INT_MAX-X%10)/10 < res) || (!flag && (INT_MIN-X%10)/10 < res)){
                return 0;
            }
            res = res*10 + X%10;
            X /= 10;
        }
        return flag * res;
    }
};
//
//  55	Jump Game.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool canJump(int A[], int n) {
        if (n<=1) {
            return true;
        }
        int end=n-1;
        int start=end-1;
        while (start>=0) {
            if (A[start]>=end-start) {
                end=start;
            }
            start--;
        }
        if (end==0) {
            return true;
        }
        return false;
    }
};
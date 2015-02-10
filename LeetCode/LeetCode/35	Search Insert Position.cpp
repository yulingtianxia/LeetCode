//
//  35	Search Insert Position.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n==0) {
            return 0;
        }
        int divide = (n-1)/2;
        if (A[divide]==target) {
            return divide;
        }
        else if(A[divide]<target) {
            return divide+1+searchInsert(A+divide+1, n-divide-1, target);
        }
        else{
            return searchInsert(A, divide, target);
        }
    }
};
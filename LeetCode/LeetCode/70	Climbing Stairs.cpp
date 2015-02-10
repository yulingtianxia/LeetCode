//
//  70	Climbing Stairs.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int climbStairs(int n) {
        int way[n+1];
        way[0]=1;
        way[1]=1;
        for (int i=2; i<=n; i++) {
            way[i] = way[i-1]+way[i-2];
        }
        return way[n];
    }
};
//
//  96	Unique Binary Search Trees.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int numTrees(int n) {
        if (n<=0) {
            return 0;
        }
        vector<int> a(n+1,0);
        a[0]=1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                a[i]+=a[j]*a[i-1-j];
            }
        }
        return a[n];
    }
};
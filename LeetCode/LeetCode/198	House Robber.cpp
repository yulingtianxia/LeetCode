//
//  198	House Robber.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/19.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int rob(vector<int> &num) {
        int size=num.size();
        if (size==0) {
            return 0;
        }
        vector<int> money(size,0);
        money[0]=num[0];
        money[1]=max(num[0],num[1]);
        for (int i=2; i<size; i++) {
            money[i]=max(money[i-1],money[i-2]+num[i]);
        }
        return money[size-1];
    }
};
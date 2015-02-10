//
//  122	Best Time to Buy and Sell Stock II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int>::iterator iter = prices.begin();
        int result = 0;
        if (prices.size()<2) {
            return result;
        }
        for (; iter!=prices.end()-1; iter++) {
            int delta = *(iter+1)-*iter;
            if (delta>0) {
                result+=delta;
            }
        }
        return result;
    }
};
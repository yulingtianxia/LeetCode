//
//  123	Best Time to Buy and Sell Stock III.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size=(int)prices.size();
        int buy1=INT_MIN;
        int sell1=0;
        int buy2=INT_MIN;
        int sell2=0;
        for (int i=0; i<size; i++) {
            sell2=max(sell2,buy2+prices[i]);
            buy2=max(buy2,sell1-prices[i]);
            sell1=max(sell1,buy1+prices[i]);
            buy1=max(buy1,-prices[i]);
        }
        return sell2;
    }
};
//
//  188	Best Time to Buy and Sell Stock IV.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/21.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int size = (int)prices.size();
        if (k==0||size<2) {
            return 0;
        }
        if (k>size/2) {
            int sum = 0;
            for(int i = 1;i < size;i++){
                if(prices[i] > prices[i-1]){
                    sum += prices[i] - prices[i-1];
                }
            }
            return sum;
        }
        vector<int> buy(k,INT_MIN);
        vector<int> sell(k,0);
        for (int i=0; i<size; i++) {
            for (int j=k-1; j>=0; j--) {
                sell[j]=max(sell[j],buy[j]+prices[i]);
                buy[j]=max(buy[j],(j>0?sell[j-1]:0)-prices[i]);
            }
        }
        return sell[k-1];
    }
};
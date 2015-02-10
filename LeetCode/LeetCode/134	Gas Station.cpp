//
//  134	Gas Station.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int rest=0;
        int start=0;
        int i=0;
        long size=gas.size();
        bool arrive=false;
        do {
            rest+=gas[i%size]-cost[i%size];
            if (rest<0) {
                rest=0;
                start=i+1;
                arrive=false;
            }
            else{
                arrive=true;
            }
            i++;
        } while ((i%size!=start||!arrive)&&start<size);
        if (start>=size) {
            return -1;
        }
        return start;
    }
};
//
//  169	Majority Element.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int , int> count;
        for (int i=0; i<num.size(); i++) {
            count[num[i]]++;
        }
        map<int, int>::iterator iter=count.begin();
        int majority=0;
        int maxCount=0;
        for (; iter!=count.end(); iter++) {
            if (iter->second>maxCount) {
                maxCount=iter->second;
                majority=iter->first;
            }
        }
        return majority;
    }
};

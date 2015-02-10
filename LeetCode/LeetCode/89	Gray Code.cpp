//
//  89	Gray Code.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result={0};
        for (int i=0; i<n; i++) {
            vector<int>::reverse_iterator ri = result.rbegin();
            vector<int> temp=result;
            for (; ri!=result.rend(); ri++) {
                temp.push_back(*ri+pow(2, i));
            }
            result=temp;
        }
        return result;
    }
};
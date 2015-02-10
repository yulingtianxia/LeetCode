//
//  119	Pascal's Triangle II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        for (int i=0; i<=rowIndex; i++) {
            vec.push_back(1);
            if (i==0||i==1) {
                continue;
            }
            for (int j = i/2; j>0; j--) {
                vec[j] += vec[j-1];
                vec[i-j] = vec[j];
            }
        }
        return vec;
    }
};

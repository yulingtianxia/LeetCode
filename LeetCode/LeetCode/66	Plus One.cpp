//
//  66	Plus One.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool up = true;
        vector<int>::reverse_iterator i = digits.rbegin();
        for (;up&&i!=digits.rend(); i++) {
            *i= (*i)+1;
            up = *i>9;
            if (up) {
                *i = *i-10;
            }
        }
        if (up) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
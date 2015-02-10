//
//  162	Find Peak Element.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int left=0;
    int right=0;
    int findPeakElement(const vector<int> &num) {
        right=num.size()-1;
        peak(num);
        return left;
    }
    void peak(const vector<int> &num) {
        if (right==left) {
            return;
        }
        int divide = (left+right)/2;
        if (num[divide]<num[divide+1]) {
            left=divide+1;
            peak(num);
        }
        else{
            right=divide;
            peak(num);
        }
    }
};
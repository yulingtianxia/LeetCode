//
//  11	Container With Most Water.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int maxArea(vector<int> &height) {
        int res=0;
        int left=0;
        int right=(int)height.size()-1;
        while (left<right) {
            res=max(res,min(height[left],height[right])*(right-left));
            if (height[left]<height[right]) {
                left++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};
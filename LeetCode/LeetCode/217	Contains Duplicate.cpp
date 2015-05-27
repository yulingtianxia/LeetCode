//
//  217	Contains Duplicate.cpp
//  LeetCode
//
//  Created by 孙芳媛 on 15/5/27.
//  Copyright (c) 2015年 孙芳媛. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> tag;
        for (int i = 0; i < nums.size(); ++i) {
            if(tag.find(nums[i])!= tag.end())
                return true;
            else
                tag.insert(nums[i]);
        }
        return false;
    }
};

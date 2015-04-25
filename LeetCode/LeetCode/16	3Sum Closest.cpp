//
//  16	3Sum Closest.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/25.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int closest = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            if (i!=0&&nums[i]==nums[i-1]) {
                continue;
            }
            int result=INT_MAX;
            int newTarget = target-nums[i];
            int left = i+1;
            int right = size-1;
            while (left<right) {
                int sum = nums[left]+nums[right];
                if (sum==newTarget) {
                    return target;
                }
                if (sum<newTarget) {
                    result = abs(result)>newTarget-sum?sum-newTarget:result;
                    left++;
                }
                else{
                    result = abs(result)>sum-newTarget?sum-newTarget:result;
                    right--;
                }
            }
            int temp = result+newTarget+nums[i];
            if (closest==INT_MAX) {
                closest=temp;
            }
            else{
                closest = abs(temp-target)<abs(closest-target)?temp:closest;
            }
        }
        return closest;
    }
};
//
//  154	Find Minimum in Rotated Sorted Array II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0;
        int high = num.size()-1;
        while (low<high) {
            int middle = (high+low+1)/2-1;
            if (num[middle]>num[high]) {
                low = middle+1;
            }
            else if(num[middle]<num[high]){
                high = middle;
            }
            else{
                if (num[low]==num[high]) {
                    high--;
                }
                else{
                    high = middle;
                }
            }
        }
        return num[high];
    }
};
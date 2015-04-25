//
//  31	Next Permutation.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/25.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int biggestIndex=num.size()-1;
        for (int i=num.size()-2; i>=0; i--) {
            if (num[i]>=num[biggestIndex]) {
                biggestIndex=i;
            }
            else{
                int smallestBiggerThanIndex=i+1;
                for (int j=i+2; j<num.size(); j++) {
                    if (num[j]>num[i]&&num[j]<num[smallestBiggerThanIndex]) {
                        smallestBiggerThanIndex=j;
                    }
                }
                int temp=num[i];
                num[i]=num[smallestBiggerThanIndex];
                num[smallestBiggerThanIndex]=temp;
                sort(num.begin()+i+1, num.end());
                return;
            }
        }
        sort(num.begin(), num.end());
    }
};
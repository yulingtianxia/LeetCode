//
//  26	Remove Duplicates from Sorted Array.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<2) {
            return n;
        }
        int id=1;
        for (int i=1; i<n; i++) {
            if (A[i]!=A[i-1]) {
                A[id++]=A[i];
            }
        }
        return id;
    }
};
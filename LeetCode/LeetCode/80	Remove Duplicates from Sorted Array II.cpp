//
//  80	Remove Duplicates from Sorted Array II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<3) {
            return n;
        }
        int id=1;
        bool twice=false;
        for (int i=1; i<n&&id<n; i++) {
            if (A[i]!=A[i-1]) {
                A[id++]=A[i];
                twice=false;
            }
            else if(!twice){
                A[id++]=A[i];
                twice=true;
            }
        }
        return id;
    }
};
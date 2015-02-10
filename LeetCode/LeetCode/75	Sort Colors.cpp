//
//  75	Sort Colors.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    void sortColors(int A[], int n) {
        int red=-1,white=-1,blue=-1;
        for (int i=0; i<n; i++) {
            if (A[i]==2) {
                A[++blue]=2;
            }
            if (A[i]==1) {
                A[++blue]=2;
                A[++white]=1;
            }
            if (A[i]==0) {
                A[++blue]=2;
                A[++white]=1;
                A[++red]=0;
            }
        }
    }
};
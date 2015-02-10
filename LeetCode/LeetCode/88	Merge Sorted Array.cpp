//
//  88	Merge Sorted Array.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int a=m-1;
        int b=n-1;
        for (int i=m+n-1; i>=0; i--) {
            if (a>=0&&b>=0) {
                A[i] = A[a]>B[b]?A[a--]:B[b--];
            }
            else if(b>=0){
                A[i] = B[b--];
            }
        }
    }
};
//
//  27	Remove Element.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for (int i=0; i<n; i++) {
            if (A[i]==elem) {
                for (int j=i; j<n-1; j++) {
                    A[j]=A[j+1];
                }
                A[n-1]=elem;
                n--;
                i--;
            }
        }
        return n;
    }
};
//
//  152	Maximum Product Subarray.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n==1) {
            return A[0];
        }
        int result=A[0];
        int f=A[0];
        int g=A[0];
        for (int i=1; i<n; i++) {
            int a=max(f*A[i],max(A[i],g*A[i]));
            int b=min(f*A[i],min(A[i],g*A[i]));
            f=a;
            g=b;
            result = max(result,f);
        }
        return result;
    }
};
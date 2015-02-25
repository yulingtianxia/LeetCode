//
//  189	Rotate Array.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/25.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k=k%n;
        if (k<=n-k) {
            while (k>0) {
                int temp=nums[n-1];
                for (int i=n-1; i>0; i--) {
                    nums[i]=nums[i-1];
                }
                nums[0]=temp;
                k--;
            }
        }
        else{
            k=n-k;
            while (k>0) {
                int temp=nums[0];
                for (int i=0; i<n; i++) {
                    nums[i]=nums[i+1];
                }
                nums[n-1]=temp;
                k--;
            }
        }
    }
};
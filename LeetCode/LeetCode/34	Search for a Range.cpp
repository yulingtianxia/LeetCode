//
//  34	Search for a Range.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int low=0;
        int high=n-1;
        vector<int> result;
        while (low<=high) {
            int mid=(low+high)/2;
            if (A[mid]==target) {
                int l=mid-1;
                int r=mid+1;
                while (l>=0&&A[l]==target) {
                    l--;
                }
                while (r<=n-1&&A[r]==target) {
                    r++;
                }
                l++;
                r--;
                result.push_back(l);
                result.push_back(r);
                return result;
            }
            if(A[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        result=vector<int>(2,-1);
        return result;
    }
};
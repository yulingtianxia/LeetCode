//
//  81	Search in Rotated Sorted Array II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/23.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool search(int A[], int n, int target) {
        return binarySearch(A, 0, n-1, target);
    }
    bool binarySearch(int A[],int low,int high,int target){
        if (low>high) {
            return false;
        }
        int middle = (low+high)/2;
        if (target==A[middle]) {
            return true;
        }
        bool searchLeft;
        if (A[high]<A[middle]) {//旋转点在右侧
            if (target>A[middle]) {
                searchLeft=false;
            }
            else{
                if (target==A[high]) {
                    return true;
                }
                searchLeft=target>A[high]?true:false;
            }
        }
        else if(A[low]>A[middle]){//旋转点在左侧
            if (target<A[middle]) {
                searchLeft=true;
            }
            else{
                if (target==A[low]) {
                    return true;
                }
                searchLeft=target>A[low]?true:false;
            }
        }
        else{
            return binarySearch(A, low, middle-1, target)||binarySearch(A, middle+1, high, target);
        }
        if (searchLeft) {
            return binarySearch(A, low, middle-1, target);
        }
        else{
            return binarySearch(A, middle+1, high, target);
        }
    }
};
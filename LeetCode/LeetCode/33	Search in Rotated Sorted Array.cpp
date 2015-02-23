//
//  33	Search in Rotated Sorted Array.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/23.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int search(int A[], int n, int target) {
        int low=0;
        int high=n-1;
        return binarySearch(A, low, high, target);
    }
    int binarySearch(int A[],int low,int high,int target){
        if (low>high) {
            return -1;
        }
        int middle = (low+high)/2;
        if (A[middle]==target) {
            return middle;
        }
        else{
            bool searchLeft;
            if (A[high]<A[middle]) {//旋转点在右侧
                if (target>A[middle]) {
                    searchLeft=false;
                }
                else{
                    if (A[high]==target) {
                        return high;
                    }
                    searchLeft=A[high]>target?false:true;
                }
            }
            else if (A[low]>A[middle]) {//旋转点在左侧
                if (target>A[middle]) {
                    if (A[low]==target) {
                        return low;
                    }
                    searchLeft=A[low]>target?false:true;
                }
                else{
                    searchLeft=true;
                }
            }
            else{//无旋转
                searchLeft=A[middle]>target?true:false;
            }
            if (searchLeft) {
                return binarySearch(A, low, middle-1, target);
            }
            else{
                return binarySearch(A, middle+1, high, target);
            }
        }
    }
};
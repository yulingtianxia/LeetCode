//
//  77	Combinations.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int>> result;
    vector<int> A;
    vector<bool> isTracked;
    vector<vector<int>> combine(int n, int k) {
        for (int i=0; i<n; i++) {
            A.push_back(i+1);
            isTracked.push_back(false);
        }
        backtrack(0,k);
        return result;
    }
    void backtrack(int t,int k){//t为解空间数的层数，k为子集的大小
        if (t>A.size()) {
            return ;//搜索到叶子节点依然无解
        }
        else{
            isTracked[t]=true;
            if (trackSum()<k) {
                backtrack(t+1, k);
            }
            else{
                add2Result();
            }
            isTracked[t]=false;
            if (trackSum()<k) {
                backtrack(t+1, k);
            }
            else{
                add2Result();
            }
        }
    }
    int trackSum(){
        int sum=0;
        for (int i=0; i<isTracked.size(); i++) {
            sum+=isTracked[i];
        }
        return sum;
    }
    void add2Result(){
        vector<int> temp;
        for (int i=0; i<A.size(); i++) {
            if (isTracked[i]) {
                temp.push_back(A[i]);
            }
        }
        result.push_back(temp);
    }
};
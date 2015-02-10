//
//  78	Subsets.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int>> result;
    vector<bool> isTracked;
    vector<vector<int> > subsets(vector<int> &S) {
        isTracked=vector<bool>(S.size(),false);
        backtrack(S,0);
        return result;
    }
    void backtrack(vector<int> &S,int t){//t为解空间数的层数
        if (t>S.size()-1) {
            add2Result(S);
            return ;//搜索到叶子节点
        }
        else{
            isTracked[t]=false;
            backtrack(S,t+1);
            isTracked[t]=true;
            backtrack(S,t+1);
        }
    }
    void add2Result(vector<int> &S){
        vector<int> temp;
        for (int i=0; i<S.size(); i++) {
            if (isTracked[i]) {
                temp.push_back(S[i]);
            }
        }
        sort(temp.begin(), temp.end());
        result.push_back(temp);
    }
};
//
//  39	Combination Sum.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int>> result;
    vector<int> combination;
    int sum=0;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates,0,target);
        return result;
    }
    void backtrack(vector<int> &candidates,int index,int target){
        for (int i=index; i<candidates.size(); i++) {//index用于剪枝
            sum+=candidates[i];
            if (sum>target) {
                sum-=candidates[i];
                continue;
            }
            else if (sum==target) {//成功搜索
                sum-=candidates[i];
                combination.push_back(candidates[i]);
                result.push_back(combination);
                combination.pop_back();
                continue;
            }
            combination.push_back(candidates[i]);
            backtrack(candidates, i, target);
        }
        if (combination.size()>0) {
            sum-=combination.back();//返回上一个活动点前将数据恢复
            combination.pop_back();
        }
    }
};
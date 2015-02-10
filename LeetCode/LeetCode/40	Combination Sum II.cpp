//
//  40	Combination Sum II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> resset;
    vector<int> combination;
    int sum=0;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates,-1,target);
        set<vector<int>>::iterator iter = resset.begin();
        for (; iter!=resset.end(); iter++) {
            result.push_back(*iter);
        }
        return result;
    }
    void backtrack(vector<int> &candidates,int index,int target){
        for (int i=index+1; i<candidates.size(); i++) {//index用于剪枝
            sum+=candidates[i];
            if (sum>target) {//死结点
                sum-=candidates[i];
                continue;
            }
            else if (sum==target) {//成功搜索
                sum-=candidates[i];
                combination.push_back(candidates[i]);
                resset.insert(combination);
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
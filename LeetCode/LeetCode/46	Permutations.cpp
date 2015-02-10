//
//  46	Permutations.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int>> result;
    vector<int> stack;
    vector<vector<int> > permute(vector<int> &num) {
        backtrack(num);
        return result;
    }
    void backtrack(vector<int> num){
        if (stack.size()==num.size()) {
            result.push_back(stack);
        }
        else{
            vector<int>::iterator iter = num.begin();
            for (; iter!=num.end(); iter++) {
                if (!check(*iter)) {
                    stack.push_back(*iter);
                    backtrack(num);
                }
            }
        }
        if (stack.size()>0) {
            stack.pop_back();
        }
    }
    bool check(int n){
        vector<int>::iterator iter = stack.begin();
        for (; iter!=stack.end(); iter++) {
            if (*iter==n) {
                return true;
            }
        }
        return false;
    }
};
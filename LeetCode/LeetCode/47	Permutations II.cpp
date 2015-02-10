//
//  47	Permutations II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/11.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int>> result;
    vector<int> stack;
    int size=0;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        size = num.size();
        backtrack(num,num.begin());
        return result;
    }
    void backtrack(vector<int> &num,vector<int>::iterator iterator){
        if (stack.size()==size) {
            result.push_back(stack);
        }
        else{
            vector<int>::iterator iter = num.begin();
            for (; iter!=num.end(); iter++) {
                if (*(iter-1)==*iter) {
                    continue;
                }
                stack.push_back(*iter);
                num.erase(iter);
                backtrack(num,iter);
            }
        }
        if (stack.size()>0) {
            num.insert(iterator, stack.back());
            stack.pop_back();
        }
    }
};
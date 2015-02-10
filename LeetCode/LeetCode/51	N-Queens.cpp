//
//  51	N-Queens.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    set<pair<int, int>> stack;
    vector<vector<string>> result;
    int size=0;
    vector<vector<string>> solveNQueens(int n) {
        size=n;
        backtrack(0);
        return result;
    }
    void backtrack(int i){
        if (i==size) {
            generateResult();
            return;
        }
        for (int j=0; j<size; j++) {
            if (check(i, j)) {
                stack.insert(pair<int, int>(i,j));
                backtrack(i+1);
                stack.erase(pair<int, int>(i,j));
            }
        }
    }
    void generateResult(){
        vector<string> temp(size,string(size,'.'));
        set<pair<int, int>>::iterator iter = stack.begin();
        for (; iter!=stack.end(); iter++) {
            temp[iter->first].replace(iter->second, 1, "Q");
        }
        result.push_back(temp);
    }
    bool check(int i,int j){
        set<pair<int, int>>::iterator iter = stack.begin();
        for (; iter!=stack.end(); iter++) {
            if (iter->first==i||iter->second==j||(abs(iter->first-i)==abs(iter->second-j))) {
                return false;
            }
        }
        return true;
    }
};
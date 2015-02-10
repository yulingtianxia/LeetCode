//
//  60	Permutation Sequence.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> stack;
    int size=0;
    vector<int> select;
    string getPermutation(int n, int k) {
        size=n;
        for (int i=1; i<=n; i++) {
            select.push_back(i);
        }
        track(k);
        string result;
        for (int i=0; i<stack.size(); i++) {
            stringstream ss;
            ss<<stack[i];
            result+=ss.str();
        }
        return result;
    }
    void track(int k){
        int big = jiecheng(size-(int)stack.size()-1);
        int cut = k/big;
        int rest = k%big;
        if (rest==0) {
            stack.push_back(select[cut-1]);
            select.erase(select.begin()+cut-1);
            for (int i=select.size()-1; i>=0; i--) {
                stack.push_back(select[i]);
            }
            return;
        }
        else{
            stack.push_back(select[cut]);
            select.erase(select.begin()+cut);
            track(rest);
        }
    }
    int jiecheng(int n){
        if (n<=1) {
            return 1;
        }
        return n*jiecheng(n-1);
    }
};
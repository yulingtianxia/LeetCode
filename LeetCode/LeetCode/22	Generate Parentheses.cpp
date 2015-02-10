//
//  22	Generate Parentheses.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    set<string> result;
    vector<string> generateParenthesis(int n) {
        long size=0;
        queue<string> resQueue;
        resQueue.push("()");
        while (resQueue.front().size()<2*n) {
            string front = resQueue.front();
            resQueue.pop();
            if (size<front.size()) {
                result.clear();
                size=front.size();
            }
            for (int i=0; i<=front.size(); i++) {
                string temp=front;
                temp.insert(i, "()");
                if (result.find(temp)==result.end()) {
                    resQueue.push(temp);
                    result.insert(temp);
                }
            }
        }
        vector<string> res;
        while (resQueue.size()>0) {
            res.push_back(resQueue.front());
            resQueue.pop();
        }
        return res;
    }
};
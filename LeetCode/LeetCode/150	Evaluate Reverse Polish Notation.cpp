//
//  150	Evaluate Reverse Polish Notation.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> expression;
        vector<string>::iterator iter = tokens.begin();
        for (; iter!=tokens.end(); iter++) {
            if (!isOperator(*iter)) {
                expression.push(atoi((*iter).c_str()));
            }
            else{
                int b = expression.top();
                expression.pop();
                int a = expression.top();
                expression.pop();
                if (*iter=="+") {
                    expression.push(a+b);
                }
                else if (*iter=="-") {
                    expression.push(a-b);
                }
                else if (*iter=="*") {
                    expression.push(a*b);
                }
                else if (*iter=="/") {
                    expression.push(a/b);
                }
            }
        }
        return expression.top();
    }
    bool isOperator(string s){
        if (s=="+"||s=="-"||s=="*"||s=="/") {
            return true;
        }
        else{
            return false;
        }
    }
};
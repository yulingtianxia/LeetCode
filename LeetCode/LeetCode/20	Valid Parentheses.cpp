//
//  20	Valid Parentheses.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    stack<int> brackets;
    bool isValid(string s) {
        if (s.length()%2!=0) {
            return false;
        }
        for (int i=0; i<s.length(); i++) {
            switch (s[i]) {
                case '(':
                    brackets.push(1);
                    break;
                case ')':
                    if (brackets.empty()) {
                        return false;
                    }
                    if (brackets.top()==1) {
                        brackets.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                case '[':
                    brackets.push(2);
                    break;
                case ']':
                    if (brackets.empty()) {
                        return false;
                    }
                    if (brackets.top()==2) {
                        brackets.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                case '{':
                    brackets.push(3);
                    break;
                case '}':
                    if (brackets.empty()) {
                        return false;
                    }
                    if (brackets.top()==3) {
                        brackets.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        if (!brackets.empty()) {
            return false;
        }
        return true;
    }
};
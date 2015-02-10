//
//  131	Palindrome Partitioning.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<string>> result;
    vector<string> stack;
    vector<vector<string>> partition(string s) {
        backtrace(s);
        return result;
    }
    void backtrace(string s){
        if (s=="") {
            result.push_back(stack);
        }
        else{
            for (int i=1; i<=s.length(); i++) {
                string temp = s.substr(0,i);
                if (checkPalindrome(temp)) {
                    stack.push_back(temp);
                    if (i<s.length()) {
                        backtrace(s.substr(i,s.length()-i));
                    }
                    else{
                        backtrace("");
                    }
                }
            }
        }
        if (stack.size()>0) {
            stack.pop_back();
        }
    }
    bool checkPalindrome(string s){
        for (int i=0; i<s.length(); i++) {
            if (s[i]!=s[s.length()-1-i]) {
                return false;
            }
        }
        return true;
    }
};
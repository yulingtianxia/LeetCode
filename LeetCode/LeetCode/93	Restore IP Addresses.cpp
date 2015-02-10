//
//  93	Restore IP Addresses.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<string> result;
    vector<string> stack;
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 1);
        return result;
    }
    void backtrack(string s,int index){
        if (index==4) {
            if (check(s)) {
                stack.push_back(s);
                string temp;
                for (int i=0; i<stack.size()-1; i++) {
                    temp+=stack[i]+".";
                }
                temp+=stack.back();
                result.push_back(temp);
                stack.pop_back();
            }
        }
        else{
            for (int i=1;i<=min(3,(int)(s.length()-(4-index)));i++) {
                string temp=s.substr(0,i);
                if (check(temp)) {
                    stack.push_back(temp);
                    if (i<s.length()) {
                        backtrack(s.substr(i,s.length()-i), index+1);
                    }
                }
            }
        }
        if (stack.size()>0) {
            stack.pop_back();
        }
    }
    bool check(string num){
        if (num[0]=='0'&&num.size()>1) {
            return false;
        }
        if (atoi(num.c_str())>255) {
            return false;
        }
        return true;
    }
};
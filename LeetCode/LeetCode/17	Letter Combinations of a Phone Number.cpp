//
//  17	Letter Combinations of a Phone Number.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    map<char, vector<string>> button;
    vector<string> result;
    string stack;
    vector<string> letterCombinations(string digits) {
        button['2']={"a","b","c"};
        button['3']={"d","e","f"};
        button['4']={"g","h","i"};
        button['5']={"j","k","l"};
        button['6']={"m","n","o"};
        button['7']={"p","q","r","s"};
        button['8']={"t","u","v"};
        button['9']={"w","x","y","z"};
        button['0']={" "};
        backtrack(digits, 0);
        return result;
    }
    void backtrack(string digits,int index){
        if (index==digits.length()) {
            result.push_back(stack);
        }
        vector<string> chars = button[digits[index]];
        vector<string>::iterator iter = chars.begin();
        for (; iter!=chars.end(); iter++) {
            stack.append(*iter);
            backtrack(digits, index+1);
        }
        if (stack.length()>0) {
            stack.erase(--stack.end());
        }
    }
};
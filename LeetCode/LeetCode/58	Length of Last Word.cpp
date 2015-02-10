//
//  58	Length of Last Word.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        stack<char> word;
        bool last = true;
        while (*s!='\0') {
            if (*s==' ') {
                last=true;
            }
            else{
                while (last&&!word.empty()) {
                    word.pop();
                }
                last = false;
                word.push(*s);
            }
            s++;
        }
        return word.size();
    }
};
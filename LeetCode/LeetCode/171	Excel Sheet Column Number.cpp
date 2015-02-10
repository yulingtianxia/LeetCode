//
//  171	Excel Sheet Column Number.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int titleToNumber(string s) {
        int size=(int)s.length()-1;
        int result=0;
        int i=0;
        while (i<=size) {
            result*=26;
            result+=char2int(s[i]);
            i++;
        }
        return result;
    }
    int char2int(char c){
        return (int)c-'A'+1;
    }
};
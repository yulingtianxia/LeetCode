//
//  13	Roman to Integer.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    map<char, int> R2I;
    int romanToInt(string s) {
        R2I['I']=1;
        R2I['V']=5;
        R2I['X']=10;
        R2I['L']=50;
        R2I['C']=100;
        R2I['D']=500;
        R2I['M']=1000;
        int size=(int)s.length();
        int res=0;
        for (int i=0; i<size; i++) {
            if (i<size-1&&R2I[s[i]]<R2I[s[i+1]]) {
                res-=R2I[s[i]];
            }
            else{
                res+=R2I[s[i]];
            }
        }
        return res;
    }
};
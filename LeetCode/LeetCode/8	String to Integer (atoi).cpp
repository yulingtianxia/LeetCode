//
//  8	String to Integer (atoi).cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int atoi(const char *str) {
        string s = str;
        int start=0;
        while (s[start]==' ') {
            start++;
        }
        bool positive=true;
        int end=start;
        if (s[start]=='-') {
            positive=false;
            end++;
        }
        else if(s[start]=='+') {
            start++;
            end++;
        }
        int result=0;
        if(!(s[end]>='0'&&s[end]<='9')){
            return 0;
        }
        bool firstNoZero=false;
        while (s[end]>='0'&&s[end]<='9') {
            if (s[end]=='0'&&!firstNoZero) {
                s.erase(s.begin()+end);
                continue;
            }
            else{
                firstNoZero=true;
            }
            result=result*10;
            result+=s[end]-'0';
            end++;
        }
        if (!firstNoZero) {
            return 0;
        }
        s=s.substr(start,end-start);
        if (!positive) {
            result=-result;
        }
        if (strcmp("", str)&&to_string(result)!=s) {
            if (positive) {
                return INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }
        return (int)result;
    }
};
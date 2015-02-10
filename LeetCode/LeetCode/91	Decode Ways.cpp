//
//  91	Decode Ways.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> ways;
    int numDecodings(string s) {
        if (s.length()<1||s[0]=='0') {
            return 0;
        }
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='0') {
                if (s[i-1]>'2') {
                    return 0;
                }
                s.erase(s.begin()+(--i));
                s.erase(s.begin()+i);
            }
        }
        int size=(int)s.length();
        if (size==0) {
            return 1;
        }
        for (int i=0; i<size; i++) {
            if (s[i]=='0') {
                return 0;
            }
        }
        ways=vector<int>(size,0);
        ways[0]=1;
        ways[1]=checkCode(s[0], s[1]);
        for (int i=2; i<size; i++) {
            ways[i]=ways[i-1];
            if (checkCode(s[i-1], s[i])==2) {
                ways[i]+=ways[i-2];
            }
        }
        return ways[size-1];
    }
    int checkCode(char a,char b){
        if(a>'2'||(a=='2'&&b>'6')){
            return 1;
        }
        else{
            return 2;
        }
    }
};
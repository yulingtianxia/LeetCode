//
//  6	ZigZag Conversion.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> zig(nRows,"");
        int zag=0;
        bool increase = true;
        if (nRows==1) {
            return s;
        }
        for (int i=0; i<s.length(); i++) {
            zig[zag]+=s[i];
            if (zag==nRows-1) {
                increase=false;
            }
            else if(zag==0){
                increase=true;
            }
            if (increase) {
                zag++;
            }
            else{
                zag--;
            }
        }
        string result="";
        for (int i=0; i<zig.size(); i++) {
            result+=zig[i];
        }
        return result;
    }
};
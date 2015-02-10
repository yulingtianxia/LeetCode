//
//  165	Compare Version Numbers.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int compareVersion(string version1, string version2) {
        string::size_type pos1=version1.find_first_of(".");
        string::size_type pos2=version2.find_first_of(".");
        int num1=0,num2=0;
        if (pos1!=version1.npos){
            num1=atoi(version1.substr(0,pos1).c_str());
        }
        else{
            num1=atoi(version1.c_str());
        }
        if (pos2!=version2.npos) {
            num2=atoi(version2.substr(0,pos2).c_str());
        }
        else{
            num2=atoi(version2.c_str());
        }
        
        
        if (num1>num2) {
            return 1;
        }
        else if(num1<num2){
            return -1;
        }
        else if(pos1!=version1.npos||pos2!=version2.npos){
            if (pos1!=version1.npos) {
                version1=version1.substr(pos1+1);
            }
            else{
                version1="0";
            }
            if (pos2!=version2.npos) {
                version2=version2.substr(pos2+1);
            }
            else{
                version2="0";
            }
            return compareVersion(version1, version2);
        }
        return 0;
    }
};
//
//  14	Longest Common Prefix.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result="";
        if (&strs==NULL||strs.empty()) {
            return "";
        }
        for (int i=0; i<strs[0].length(); i++) {
            if(checkString(i, strs)){
                result += strs[0][i];
            }
            else{
                break;
            }
        }
        return result;
    }
    bool checkString(int i,vector<string> &strs) {
        char x = strs[0][i];
        vector<string>::iterator iter = strs.begin();
        for (; iter!=strs.end(); iter++) {
            if ((*iter).length()<i+1) {
                return false;
            }
            if (x!=(*iter)[i]) {
                return false;
            }
        }
        return true;
    }
};
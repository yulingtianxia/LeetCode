//
//  139	Word Break.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> success(s.length()+1,false);
        success[0]=true;
        for (int i=0; i<s.length(); i++) {
            if (!success[i]) {
                continue;
            }
            unordered_set<string>::iterator iter=dict.begin();
            for (; iter!=dict.end(); iter++) {
                int end=i+(int)(*iter).length();
                if (end>s.length()||success[end]) {
                    continue;
                }
                if (s.substr(i,(int)(*iter).length())==*iter) {
                    success[end]=true;
                }
            }
        }
        return success[s.length()];
    }
};
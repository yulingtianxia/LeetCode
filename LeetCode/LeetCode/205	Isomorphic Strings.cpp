//
//  205	Isomorphic Strings.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/5/20.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    unordered_map<char, char> SreplaceT;
    unordered_map<char, char> TreplaceS;
    bool isIsomorphic(string s, string t) {
        for (int i=0; i<s.length(); i++) {
            if (SreplaceT.find(s[i])==SreplaceT.end()&&TreplaceS.find(t[i])==TreplaceS.end()) {
                SreplaceT[s[i]]=t[i];
                TreplaceS[t[i]]=s[i];
            }
            else if (SreplaceT[s[i]]!=t[i]||TreplaceS[t[i]]!=s[i]) {
                return false;
            }
        }
        return true;
    }
};
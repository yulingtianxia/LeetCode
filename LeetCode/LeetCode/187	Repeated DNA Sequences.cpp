//
//  187	Repeated DNA Sequences.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/16.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    unordered_set<int> substrings;
    vector<string> result;
    hash<string> mapping;
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length()<11) {
            return result;
        }
        for (int i=0; i<s.length()-9; i++) {
            string substr = s.substr(i,10);
            int sub = mapping(substr);
            if (substrings.find(sub)==substrings.end()) {
                substrings.insert(sub);
            }
            else {
                if(find(result.begin(), result.end(), substr)==result.end()) {
                    result.push_back(substr);
                }
            }
        }
        return result;
    }
};
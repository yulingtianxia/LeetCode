//
//  49	Anagrams.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/26.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    unordered_map<string, vector<string>> groups;
    vector<string> result;
    vector<string> anagrams(vector<string>& strs) {
        for (auto s:strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            groups[temp].push_back(s);
        }
        for (auto pair:groups) {
            if (pair.second.size()>1) {
                for (auto str:pair.second) {
                    result.push_back(str);
                }
            }
        }
        return result;
    }
};
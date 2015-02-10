//
//  3	Longest Substring Without Repeating Characters.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,maxL=0;
        map<char, int> position;
        for (int i=0; i<s.length(); i++) {
            if (position.find(s[i])!=position.end()) {
                maxL=max(maxL,i-l);
                for (int j=l; j<position[s[i]]; j++) {
                    position.erase(s[j]);
                }
                l=position[s[i]]+1;
            }
            position[s[i]]=i;
        }
        maxL=max(maxL,(int)s.length()-l);
        return maxL;
    }
};
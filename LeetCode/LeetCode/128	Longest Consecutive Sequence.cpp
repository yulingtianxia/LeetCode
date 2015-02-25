//
//  128	Longest Consecutive Sequence.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/25.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> sequences;//begin->length:序列两端记录着序列长度
        int result=0;
        for(auto i:num){
            if (!sequences[i]) {
                result = max(result, sequences[i-sequences[i-1]]=sequences[i+sequences[i+1]]=sequences[i]=sequences[i+1]+sequences[i-1]+1);//让sequences[i]沿着两侧拓展并更新序列两端长度值，同时使sequences[i]不为0，避免重复进入
            }
        }
        return result;
    }
};
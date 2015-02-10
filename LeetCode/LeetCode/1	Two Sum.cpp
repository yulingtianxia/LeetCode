//
//  1	Two Sum.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, vector<int>> numberMap;
        for (int i=0; i<numbers.size(); ++i) {
            map<int,vector<int>>::iterator found = numberMap.find(numbers[i]);
            if (found!=numberMap.end()) {
                found->second.push_back(i);
            }
            else {
                numberMap.insert(pair<int,vector<int>>(numbers[i] ,{i}));
            }
        }
        map<int,vector<int>>::iterator a=numberMap.begin();
        map<int,vector<int>>::reverse_iterator b=numberMap.rbegin();
        int c = a->first+b->first;
        for (; (a!=numberMap.end())&&(b!=numberMap.rend())&&c!=target;c = a->first+b->first) {
            if (c>target) {
                b++;
            }
            else {
                a++;
            }
        }
        vector<int> result;
        result.push_back(++(b->second[b->second.size()-1]));
        b->second.pop_back();
        result.push_back(++(a->second[0]));
        sort(result.begin(), result.end());
        return result;
    }
};
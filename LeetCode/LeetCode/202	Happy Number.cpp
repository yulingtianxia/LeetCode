//
//  202	Happy Number.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/22.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    unordered_map<int, int> path;
    bool isHappy(int n) {
        int value=0;
        int key=n;
        while (n) {
            int temp = n%10;
            value+=temp*temp;
            n/=10;
        }
        if (value==1) {
            return true;
        }
        if (path.find(value)!=path.end()) {
            return false;
        }
        path[key]=value;
        return isHappy(value);
    }
};
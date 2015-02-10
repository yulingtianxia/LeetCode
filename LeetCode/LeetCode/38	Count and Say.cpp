//
//  38	Count and Say.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    string countAndSay(int n) {
        string input = "1";
        for (int i=1; i<n; i++) {
            string result = "";
            char forward = 'x';
            int count = 0;
            for (int j=0; j<input.length(); j++) {
                if (input[j]==forward) {
                    count++;
                }
                else{
                    if (count>0) {
                        result += to_string(count);
                        result += forward;
                    }
                    forward = input[j];
                    count=1;
                }
            }
            if (count>0) {
                result += to_string(count);
                result += forward;
            }
            input = result;
        }
        return input;
    }
};
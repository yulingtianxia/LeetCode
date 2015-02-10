//
//  28	Implement strStr().cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        char *head1 = haystack;
        char *head2 = needle;
        int position = 0;
        while (*needle!='\0'&&*haystack!='\0') {
            if (*haystack==*needle) {
                haystack++;
                needle++;
            }
            else{
                position++;
                haystack = head1+position;
                needle = head2;
            }
        }
        if (*needle=='\0') {
            return position;
        }
        else{
            return -1;
        }
    }
};
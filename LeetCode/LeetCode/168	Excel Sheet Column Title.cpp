//
//  168	Excel Sheet Column Title.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        do {
            int remainder=n%26;
            if (remainder==0) {
                remainder=26;
                n--;
            }
            res=(char)('A'+remainder-1)+res;
            if (n<=26) {
                break;
            }
            n/=26;
        } while (true);
        return res;
    }
};

//
//  9	Palindrome Number.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool isPalindrome(int x) {
        bool isIn = false;
        if (x<0) {
            return false;
        }
        for (int i=10; i>=0; i--) {
            if (x/(int)pow(10, i)!=0) {
                isIn=true;
            }
            if(isIn&&x/(int)pow(10, i)==x%10){
                x-=x/(int)pow(10, i)*(int)pow(10, i);
                x/=10;
                i--;
            }
            else if(isIn){
                return false;
            }
        }
        if (x==0) {
            return true;
        }
        else{
            return false;
        }
    }
};
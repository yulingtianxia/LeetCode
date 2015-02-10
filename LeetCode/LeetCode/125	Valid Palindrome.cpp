//
//  125	Valid Palindrome.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool isPalindrome(string s) {
        if (!s.size()) {
            return true;
        }
        int left = 0;
        int right = s.size()-1;
        while (left<right) {
            while (left<s.size()&&!isAlphanumeric(s[left])) {
                left++;
            }
            while (right>0&&!isAlphanumeric(s[right])) {
                right--;
            }
            if (left>=right) {
                return true;
            }
            int diff = abs(s[left]-s[right]);
            if (diff==0||diff==32) {
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isAlphanumeric(char x){
        if ((x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x>='0'&&x<='9')) {
            return true;
        }
        else{
            return false;
        }
    }
    
};
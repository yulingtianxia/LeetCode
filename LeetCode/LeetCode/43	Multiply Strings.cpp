//
//  43	Multiply Strings.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=(int)num1.length();
        int len2=(int)num2.length();
        if (len1>len2) {
            int tempLen=len1;
            len1=len2;
            len2=tempLen;
            string tempStr=num1;
            num1=num2;
            num2=tempStr;
        }
        string res="";
        for (int i=len1-1; i>=0; i--) {
            int carry=0;
            string current="";
            for (int j=len2-1; j>=0; j--) {
                int temp=(num1[i]-'0')*(num2[j]-'0')+carry;
                carry=temp/10;
                current=to_string(temp%10)+current;
            }
            if (carry>0) {
                current=to_string(carry)+current;
                carry=0;
            }
            int k=(int)current.length()-1;
            if (res.length()==0) {
                res=current;
                continue;
            }
            for (int j=(int)res.length()-len1+i; k>=0; j--,k--) {
                if (j>=0) {
                    int temp=(current[k]-'0')+(res[j]-'0')+carry;
                    carry=temp/10;
                    res.replace(j, 1, to_string(temp%10));
                }
                else{
                    int temp=(current[k]-'0')+carry;
                    carry=temp/10;
                    res=to_string(temp%10)+res;
                }
            }
            if (carry>0) {
                res=to_string(carry)+res;
                carry=0;
            }
        }
        while (res[0]=='0'&&res.length()>1) {
            res.erase(res.begin());
        }
        return res;
    }
};
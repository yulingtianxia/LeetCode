//
//  67	Add Binary.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool up = false;
    long l = 0;
    long m = 0;
    long n = 0;
    string result;
    string addBinary(string a, string b) {
        l = max(a.length(), b.length());
        m = a.length()-1;
        n = b.length()-1;
        while (l-->=0) {
            if (m>=0&&n>=0) {
                checkBinary(a, b);
                m--;
                n--;
            }
            else if(m>=0) {
                if (a[m]=='1') {
                    if (up) {
                        result.insert(0, "0");
                        up = true;
                    }
                    else{
                        result.insert(0, "1");
                        up = false;
                    }
                }
                else{
                    if (up) {
                        result.insert(0, "1");
                    }
                    else{
                        result.insert(0, "0");
                    }
                    up = false;
                }
                m--;
            }
            else if(n>=0) {
                if (b[n]=='1') {
                    if (up) {
                        result.insert(0, "0");
                        up = true;
                    }
                    else{
                        result.insert(0, "1");
                        up = false;
                    }
                }
                else{
                    if (up) {
                        result.insert(0, "1");
                    }
                    else{
                        result.insert(0, "0");
                    }
                    up = false;
                }
                n--;
            }
            else{
                if (up) {
                    result.insert(0, "1");
                }
            }
        }
        return result;
    }
    void checkBinary(string a, string b){
        if (a[m]=='1'&&b[n]=='1') {
            if (up) {
                result.insert(0, "1");
            }
            else{
                result.insert(0, "0");
            }
            up = true;
            
        }
        else{
            if (a[m]=='0'&&b[n]=='0') {
                if (up) {
                    result.insert(0, "1");
                }
                else{
                    result.insert(0, "0");
                }
                up = false;
            }
            else{
                if (up) {
                    result.insert(0, "0");
                    up = true;
                }
                else{
                    result.insert(0, "1");
                    up = false;
                }
            }
        }
    }
    void checkBinary(string a){
        
    }
};
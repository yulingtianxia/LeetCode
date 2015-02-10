//
//  12	Integer to Roman.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    map<int, char> R2I;
    string intToRoman(int num) {
        R2I[1]='I';//V 和X 左边的小数字只能用Ⅰ
        R2I[5]='V';
        R2I[10]='X';//L 和C 左边的小数字只能用X
        R2I[50]='L';
        R2I[100]='C';//D 和M 左边的小数字只能用C
        R2I[500]='D';
        R2I[1000]='M';
        map<int, char>::reverse_iterator iter = R2I.rbegin();
        string result="";
        result+=string(num/1000,'M');
        num%=1000;
        result+=lessthanThousand(num/100);
        num%=100;
        result+=lessthanHundred(num/10);
        num%=10;
        result+=lessthanTen(num);
        return result;
    }
    string lessthanTen(int num){
        if (num<4) {
            return string(num,'I');
        }
        if (num==4) {
            return "IV";
        }
        if (num>=5&&num<9) {
            return "V"+string(num-5,'I');
        }
        return "IX";
    }
    string lessthanHundred(int num){
        if (num<4) {
            return string(num,'X');
        }
        if (num==4) {
            return "XL";
        }
        if (num>=5&&num<9) {
            return "L"+string(num-5,'X');
        }
        return "XC";
    }
    string lessthanThousand(int num){
        if (num<4) {
            return string(num,'C');
        }
        if (num==4) {
            return "CD";
        }
        if (num>=5&&num<9) {
            return "D"+string(num-5,'C');
        }
        return "CM";
    }
};
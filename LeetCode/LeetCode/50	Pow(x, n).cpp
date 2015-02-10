//
//  50	Pow(x, n).cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    double pow(double x, int n) {
        if (x==1) {
            return 1;
        }
        if (n==0) {
            return 1;
        }
        if (n==INT_MIN) {
            int temp=pow(x, -(n/2));
            return 1/(temp*temp);
        }
        if (n<0) {
            return 1.0/pow(x, -n);
        }
        if (n==1) {
            return x;
        }
        if (n==2) {
            return x*x;
        }
        if (n%2==0) {
            double temp=pow(x, n/2);
            return temp*temp;
        }
        else{
            double temp=pow(x, n/2);
            return temp*temp*x;
        }
    }
};
//
//  204	Count Primes.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/28.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
        int count=0;
        int ceil=sqrt(n);
        for (int i=2; i<n; i++) {
            if (isPrime[i]) {
                count++;
                if (i>ceil) {
                    continue;
                }
                for (int j=2*i; j<n; j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        return count;
    }
};
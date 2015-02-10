//
//  69	Sqrt(x).cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int sqrt(int64_t x) {
        if (x==0) {
            return 0;
        }
        int size=0;
        int comp=0x1;
        for (int i=0; i<=40; i++) {
            if (x&comp) {
                size=i;
            }
            comp<<=1;
        }
        size=size/2;
        int maxSize=size;
        int res=0x1<<size;
        while (size>=0) {
            res=min(46340,res);
            int64_t pow2=res*res;
            if (pow2==x||(pow2<x&&(res+1)*(res+1)>x)) {
                break;
            }
            else if(pow2>x){
                res-=0x1<<size;
            }
            else if(res==46340){
                break;
            }
            else{
                res+=0x1<<size;
            }
            //            if (size==0&&!(pow2<x&&(res+1)*(res+1)>x)) {
            //                size=maxSize+1;
            //            }
            size--;
        }
        return res;
    }
};
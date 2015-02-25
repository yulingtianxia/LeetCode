//
//  42	Trapping Rain Water.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/25.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"

class Solution {
public:
    int result=0;
    int trap(int A[], int n) {
        vector<int> channels;
        int leftHill=0,rightHill=n-1;
        while (leftHill<rightHill) {
            if (A[leftHill]<=A[rightHill]) {//左侧向右推进
                do {
                    channels.push_back(A[leftHill++]);
                } while (leftHill<rightHill&&channels[0]>=A[leftHill]);
                trapHelper(channels);
            }
            else{//右侧向左推进
                do {
                    channels.push_back(A[rightHill--]);
                } while (leftHill<rightHill&&channels[0]>=A[rightHill]);
                trapHelper(channels);
            }
        }
        return result;
    }
    void trapHelper(vector<int> &channels){
        for (int i=0; i<channels.size(); i++) {
            result+=channels[0]-channels[i];
        }
        channels.clear();
    }
};
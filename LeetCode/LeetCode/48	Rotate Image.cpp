//
//  48	Rotate Image.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/23.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=(int)matrix.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);//对角线对称变换
            }
        }
        reverse(matrix.begin(), matrix.end());//上下颠倒
    }
};
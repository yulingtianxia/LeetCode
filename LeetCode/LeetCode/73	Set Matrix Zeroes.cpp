//
//  73	Set Matrix Zeroes.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int m=0;
    int n=0;
    void setZeroes(vector<vector<int> > &matrix) {
        m=(int)matrix.size();
        n=(int)matrix[0].size();
        bool lastRow=false;
        for (int i=0; i<m; i++) {
            bool thisRow=false;
            for (int j=0; j<n; j++) {
                if (matrix[i][j]==0) {
                    thisRow=true;
                    for (int k=0; k<i; k++) {
                        matrix[k][j]=0;
                    }
                }
                else if(i>0&&matrix[i-1][j]==0){
                    matrix[i][j]=0;
                }
            }
            if (lastRow) {
                for (int j=0; j<n; j++) {
                    matrix[i-1][j]=0;
                }
            }
            lastRow=thisRow;
        }
        if (lastRow) {
            for (int j=0; j<n; j++) {
                matrix[m-1][j]=0;
            }
        }
    }
};
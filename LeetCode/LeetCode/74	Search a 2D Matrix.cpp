//
//  74	Search a 2D Matrix.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int i=0;
        while (i<matrix.size()) {
            if (matrix[i][0]==target) {
                return true;
            }
            if (matrix[i][0]>target) {
                i--;
                break;
            }
            i++;
        }
        if (i>matrix.size()-1) {
            i=matrix.size()-1;
        }
        for (int j=0; j<matrix[i].size(); j++) {
            if (matrix[i][j]==target) {
                return true;
            }
            if (matrix[i][j]>target) {
                return false;
            }
        }
        return false;
    }
};
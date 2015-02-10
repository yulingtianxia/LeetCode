//
//  64	Minimum Path Sum.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        vector<vector<int>> path(m,vector<int>(n,0));
        path[0][0]=grid[0][0];
        for (int i=1; i<m; i++) {
            path[i][0]=path[i-1][0]+grid[i][0];
        }
        for (int i=1; i<n; i++) {
            path[0][i]=path[0][i-1]+grid[0][i];
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                path[i][j]=min(path[i-1][j],path[i][j-1])+grid[i][j];
            }
        }
        return path[m-1][n-1];
    }
};
//
//  63	Unique Paths II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=(int)obstacleGrid.size();
        int n=(int)obstacleGrid[0].size();
        vector<vector<int>> path(m,vector<int>(n,0));
        int num=1;
        for (int i=0; i<m; i++) {
            if (obstacleGrid[i][0]==1) {
                num=0;
            }
            path[i][0]=num;
        }
        num=1;
        for (int i=0; i<n; i++) {
            if (obstacleGrid[0][i]==1) {
                num=0;
            }
            path[0][i]=num;
        }
        if (m<2) {
            return path[0][n-1];
        }
        if (n<2) {
            return path[m-1][0];
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j]==1) {
                    continue;
                }
                else{
                    path[i][j]=path[i-1][j]+path[i][j-1];
                }
            }
        }
        return path[m-1][n-1];
    }
};

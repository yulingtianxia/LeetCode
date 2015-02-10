//
//  120	Triangle.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> levelmin(triangle.size(),INT_MAX);
        levelmin[0]=triangle[0][0];
        int result=INT_MAX;
        for (int i=1; i<triangle.size(); i++) {
            for (int j=(int)triangle[i].size()-1; j>0; j--) {
                levelmin[j]=min(levelmin[j-1],levelmin[j])+triangle[i][j];
                if (i==triangle.size()-1) {
                    result=min(result,levelmin[j]);
                }
            }
            levelmin[0]+=triangle[i][0];
        }
        return result<levelmin[0]?result:levelmin[0];
    }
};
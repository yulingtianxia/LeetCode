//
//  200	Number of Islands.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/19.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    set<pair<int , int>> lands;
    int numIslands(vector<vector<char>> &grid) {
        int result=0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]=='1'&&lands.find(pair<int, int>(i,j))==lands.end()) {
                    searchAround(i, j, grid);
                    result++;
                }
            }
        }
        return result;
    }
    void searchAround(int i,int j,vector<vector<char>> &grid) {
        if (lands.find(pair<int, int>(i,j))==lands.end()) {
            lands.insert(pair<int, int>(i,j));
            if (i-1>=0&&grid[i-1][j]=='1') {
                searchAround(i-1, j, grid);
            }
            if (i+1<grid.size()&&grid[i+1][j]=='1') {
                searchAround(i+1, j, grid);
            }
            if (j-1>=0&&grid[i][j-1]=='1') {
                searchAround(i, j-1, grid);
            }
            if (j+1<grid[0].size()&&grid[i][j+1]=='1') {
                searchAround(i, j+1, grid);
            }
        }
    }
};
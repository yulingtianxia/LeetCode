//
//  130	Surrounded Regions.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<bool>> traced;
    void solve(vector<vector<char>> &board) {
        if (board.size()<=0) {
            return;
        }
        traced=vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
        for (int i=0; i<board.size(); i++) {
            if (board[i][0]=='O'&&!traced[i][0]) {
                BFS(board, pair<int, int>(i,0));
            }
            if (board[i][board[0].size()-1]=='O'&&!traced[i][board[0].size()-1]) {
                BFS(board, pair<int, int>(i,board[0].size()-1));
            }
        }
        for (int j=0; j<board[0].size(); j++) {
            if (board[0][j]=='O'&&!traced[0][j]) {
                BFS(board, pair<int, int>(0,j));
            }
            if (board[board.size()-1][j]=='O'&&!traced[board.size()-1][j]) {
                BFS(board, pair<int, int>(board.size()-1,j));
            }
        }
        for (int i=1; i<board.size()-1; i++) {
            for (int j=1; j<board[0].size()-1; j++) {
                if (board[i][j]=='O'&&!traced[i][j]) {
                    board[i][j]='X';
                }
            }
        }
    }
    void BFS(vector<vector<char>> &board,pair<int, int> node){
        queue<pair<int , int>> region;
        traced[node.first][node.second]=true;
        region.push(node);
        while (region.size()>0) {
            int i=region.front().first;
            int j=region.front().second;
            region.pop();
            if (i-1>=0&&board[i-1][j]=='O'&&!traced[i-1][j]) {
                region.push(pair<int, int>(i-1, j));
                traced[i-1][j]=true;
            }
            if (i+1<board.size()&&board[i+1][j]=='O'&&!traced[i+1][j]) {
                region.push(pair<int, int>(i+1,j));
                traced[i+1][j]=true;
            }
            if (j-1>=0&&board[i][j-1]=='O'&&!traced[i][j-1]) {
                region.push(pair<int, int>(i, j-1));
                traced[i][j-1]=true;
            }
            if (j+1<board[0].size()&&board[i][j+1]=='O'&&!traced[i][j+1]) {
                region.push(pair<int, int>(i, j+1));
                traced[i][j+1]=true;
            }
        }
    }
};
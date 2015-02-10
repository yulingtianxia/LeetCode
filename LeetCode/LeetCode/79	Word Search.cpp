//
//  79	Word Search.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    set<pair<int, int>> stack;
    bool exist(vector<vector<char> > &board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j]==word[0]) {
                    stack.insert(pair<int, int>(i,j));
                    if(backtrack(board, word, 1, i, j)){
                        return true;
                    }
                    stack.erase(pair<int, int>(i,j));
                }
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>> &board, string word,int index,int i,int j){
        if (index==word.size()) {
            return true;
        }
        vector<pair<int, int>> found = findAround(board, i, j, word[index]);
        if (found.size()>0) {
            vector<pair<int, int>>::iterator iter = found.begin();
            for (; iter!=found.end(); iter++) {
                stack.insert(pair<int, int>(i,j));
                if(backtrack(board, word, index+1, iter->first, iter->second)){
                    return true;
                }
                stack.erase(pair<int, int>(i,j));
            }
        }
        else{
            return false;
        }
        return false;
    }
    vector<pair<int, int>> findAround(vector<vector<char>> &board,int i,int j,char x){
        vector<pair<int, int>> result;
        if (i-1>=0&&board[i-1][j]==x) {
            if (stack.find(pair<int, int>(i-1,j))==stack.end()) {
                result.push_back(pair<int, int>(i-1,j));
            }
        }
        if (i+1<board.size()&&board[i+1][j]==x) {
            if (stack.find(pair<int, int>(i+1,j))==stack.end()){
                result.push_back(pair<int, int>(i+1,j));
            }
        }
        if (j-1>=0&&board[i][j-1]==x) {
            if (stack.find(pair<int, int>(i,j-1))==stack.end()){
                result.push_back(pair<int, int>(i,j-1));
            }
        }
        if (j+1<board[0].size()&&board[i][j+1]==x) {
            if (stack.find(pair<int, int>(i,j+1))==stack.end()){
                result.push_back(pair<int, int>(i,j+1));
            }
        }
        return result;
    }
};
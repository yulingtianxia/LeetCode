//
//  36	Valid Sudoku.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        set<char> rowSet;
        set<char> columnSet;
        set<char> nines[3];
        for (int i=0; i<9; i++) {
            rowSet.clear();
            columnSet.clear();
            if (i%3==0) {
                nines[0].clear();
                nines[1].clear();
                nines[2].clear();
            }
            for (int j=0; j<9; j++) {
                if (board[i][j]!='.') {
                    if (rowSet.find(board[i][j])!=rowSet.end()) {
                        return false;
                    }
                    else{
                        rowSet.insert(board[i][j]);
                    }
                    if (nines[j/3].find(board[i][j])!=nines[j/3].end()) {
                        return false;
                    }
                    else{
                        nines[j/3].insert(board[i][j]);
                    }
                }
                if (board[j][i]!='.') {
                    if (columnSet.find(board[j][i])!=columnSet.end()) {
                        return false;
                    }
                    else{
                        columnSet.insert(board[j][i]);
                    }
                }
            }
        }
        return true;
    }
};
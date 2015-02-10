//
//  54	Spiral Matrix.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.size()<1) {
            return vector<int>();
        }
        int minRow=0,maxRow=(int)matrix.size()-1,minColumn=0,maxColumn=(int)matrix[0].size()-1;
        int i=0,j=0;
        vector<int> result;
        result.push_back(matrix[0][0]);
        if (minRow==maxRow&&minColumn==maxColumn) {
            return result;
        }
        while (minRow<=maxRow||minColumn<=maxColumn) {
            while (j<maxColumn) {
                j++;
                result.push_back(matrix[i][j]);
                if (j==maxColumn) {
                    minRow++;
                    break;
                }
            }
            if (minRow==maxRow) {
                while (j>=minColumn) {
                    result.push_back(matrix[maxRow][j]);
                    if (j==minColumn) {
                        return result;
                    }
                    j--;
                }
            }
            else if(minRow>maxRow){
                return result;
            }
            while (i<maxRow) {
                i++;
                result.push_back(matrix[i][j]);
                if (i==maxRow) {
                    maxColumn--;
                    break;
                }
            }
            if (minColumn==maxColumn) {
                while (i>=minRow) {
                    result.push_back(matrix[i][minColumn]);
                    if (i==minRow) {
                        return result;
                    }
                    i--;
                }
            }
            else if(minColumn>maxColumn){
                return result;
            }
            while (j>minColumn) {
                j--;
                result.push_back(matrix[i][j]);
                if (j==minColumn) {
                    maxRow--;
                    break;
                }
            }
            if (minRow==maxRow) {
                while (j<=maxColumn) {
                    result.push_back(matrix[maxRow][j]);
                    if (j==maxColumn) {
                        return result;
                    }
                    j++;
                }
            }
            else if(minRow>maxRow){
                return result;
            }
            while (i>minRow) {
                i--;
                result.push_back(matrix[i][j]);
                if (i==minRow) {
                    minColumn++;
                    break;
                }
            }
            if (minColumn==maxColumn) {
                while (i<=maxRow) {
                    result.push_back(matrix[i][minColumn]);
                    if (i==maxRow) {
                        return result;
                    }
                    i++;
                }
            }
            else if(minColumn>maxColumn){
                return result;
            }
        }
        return result;
    }
};
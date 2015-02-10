//
//  59	Spiral Matrix II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n==0) {
            return vector<vector<int>>();
        }
        int minRow=0,maxRow=n-1,minColumn=0,maxColumn=n-1;
        int count=0;
        int i=0,j=0;
        vector<vector<int>> result(n,vector<int>(n,0));
        result[0][0]=++count;
        if (minRow==maxRow&&minColumn==maxColumn) {
            return result;
        }
        while (minRow<=maxRow||minColumn<=maxColumn) {
            while (j<maxColumn) {
                j++;
                result[i][j]=++count;
                if (j==maxColumn) {
                    minRow++;
                    break;
                }
            }
            if (minRow==maxRow) {
                while (j>=minColumn) {
                    result[maxRow][j]=++count;
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
                result[i][j]=++count;
                if (i==maxRow) {
                    maxColumn--;
                    break;
                }
            }
            if (minColumn==maxColumn) {
                while (i>=minRow) {
                    result[i][minColumn]=++count;
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
                result[i][j]=++count;
                if (j==minColumn) {
                    maxRow--;
                    break;
                }
            }
            if (minRow==maxRow) {
                while (j<=maxColumn) {
                    result[maxRow][j]=++count;
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
                result[i][j]=++count;
                if (i==minRow) {
                    minColumn++;
                    break;
                }
            }
            if (minColumn==maxColumn) {
                while (i<=maxRow) {
                    result[i][minColumn]=++count;
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
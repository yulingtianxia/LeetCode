//
//  118	Pascal's Triangle.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> vec;
        for (int i=0; i<numRows; i++) {
            vec.push_back(1);
            if (i==0||i==1) {
                result.push_back(vec);
                continue;
            }
            for (int j = i/2; j>0; j--) {
                vec[j] += vec[j-1];
                vec[i-j] = vec[j];
            }
            result.push_back(vec);
        }
        return result;
    }
};
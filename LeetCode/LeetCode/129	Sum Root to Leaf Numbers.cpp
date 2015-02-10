//
//  129	Sum Root to Leaf Numbers.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    int sum=0;
    vector<TreeNode *> num;
    vector<int> track;//0x00:nothing 0x01:left 0x10:right 0x11 both
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        DFS(root);
        return sum;
    }
    void DFS(TreeNode *root){
        num.push_back(root);
        track.push_back(0);
        while (num.size()>0) {
            if (num.back()->left&&!(track.back()&0x01)) {
                num.push_back(num.back()->left);
                track.back()|=0x01;
                track.push_back(0);
                continue;
            }
            if(num.back()->right&&!(track.back()&0x10)){
                num.push_back(num.back()->right);
                track.back()|=0x10;
                track.push_back(0);
                continue;
            }
            if (!num.back()->left&&!num.back()->right) {
                int temp=0;
                for (int i=0; i<num.size(); i++) {
                    temp*=10;
                    temp+=num[i]->val;
                }
                sum+=temp;
            }
            num.pop_back();
            track.pop_back();
        }
    }
};
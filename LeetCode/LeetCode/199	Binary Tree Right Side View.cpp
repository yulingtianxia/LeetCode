//
//  199	Binary Tree Right Side View.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/19.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<int> result;
    vector<int> rightSideView(TreeNode *root) {
        if (!root) {
            return result;
        }
        DFS(root,1);
        return result;
    }
    void DFS(TreeNode *root,int layer) {
        if (layer>result.size()) {
            result.push_back(root->val);
        }
        if (root->right) {
            DFS(root->right,layer+1);
        }
        if (root->left) {
            DFS(root->left,layer+1);
        }
    }
};
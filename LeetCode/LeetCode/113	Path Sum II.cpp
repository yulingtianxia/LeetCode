//
//  113	Path Sum II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> stack;
    vector<vector<int>> result;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root) {
            DFS(root, sum);
        }
        return result;
    }
    void DFS(TreeNode *root,int sum){
        stack.push_back(root->val);
        if (!root->left&&!root->right) {
            if (sum==root->val) {
                result.push_back(stack);
            }
        }
        else{
            if (root->left) {
                pathSum(root->left, sum-root->val);
            }
            if (root->right) {
                pathSum(root->right, sum-root->val);
            }
        }
        stack.pop_back();
    }
};
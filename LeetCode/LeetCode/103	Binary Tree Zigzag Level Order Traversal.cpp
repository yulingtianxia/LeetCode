//
//  103	Binary Tree Zigzag Level Order Traversal.cpp
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        stack<TreeNode *> reverse;
        queue<TreeNode *> level;
        bool l2r=true;
        level.push(root);
        while (!level.empty()) {
            while (!level.empty()) {
                reverse.push(level.front());
                level.pop();
            }
            vector<int> temp;
            while (!reverse.empty()) {
                TreeNode *node=reverse.top();
                temp.push_back(node->val);
                if (l2r) {
                    if (node->left) {
                        level.push(node->left);
                    }
                    if (node->right) {
                        level.push(node->right);
                    }
                }
                else{
                    if (node->right) {
                        level.push(node->right);
                    }
                    if (node->left) {
                        level.push(node->left);
                    }
                }
                reverse.pop();
            }
            l2r^=true;
            result.push_back(temp);
        }
        return result;
    }
};
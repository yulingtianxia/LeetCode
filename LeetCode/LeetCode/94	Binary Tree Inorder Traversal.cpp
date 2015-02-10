//
//  94	Binary Tree Inorder Traversal.cpp
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> treeStack;
        bool newPush = false;
        if (!root) {
            return result;
        }
        treeStack.push(root);
        newPush = true;
        while (!treeStack.empty()) {
            TreeNode *top = treeStack.top();
            if (newPush&&top->left) {
                treeStack.push(top->left);
                newPush = true;
                continue;
            }
            else{
                treeStack.pop();
                newPush = false;
                result.push_back(top->val);
            }
            if (top->right) {
                treeStack.push(top->right);
                newPush = true;
            }
        }
        return result;
    }
};
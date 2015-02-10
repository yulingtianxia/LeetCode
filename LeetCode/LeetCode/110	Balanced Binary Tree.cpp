//
//  110	Balanced Binary Tree.cpp
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
    bool balance = true;
    bool isBalanced(TreeNode *root) {
        maxDepth(root);
        return balance;
    }
    int maxDepth(TreeNode *root) {
        int left = 0;
        int right = 0;
        if (root==NULL) {
            return 0;
        }
        left = maxDepth(root->left)+1;
        right = maxDepth(root->right)+1;
        if (root->left==NULL&&root->right==NULL) {
            return 1;
        }
        if (abs(left-right)>1) {
            balance = false;
        }
        return left>right?left:right;
    }
};
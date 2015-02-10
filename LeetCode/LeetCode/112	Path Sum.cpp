//
//  112	Path Sum.cpp
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
    bool hasPathSum(TreeNode *root, int sum) {
        bool has = false;
        if (root==NULL) {
            return has;
        }
        if (root->left!=NULL) {
            has = has||hasPathSum(root->left, sum-root->val);
        }
        if (root->right!=NULL) {
            has = has||hasPathSum(root->right, sum-root->val);
        }
        if (root->right==NULL&&root->left==NULL) {
            if (root->val==sum) {
                return true;
            }
            else{
                return false;
            }
        }
        return has;
    }
};
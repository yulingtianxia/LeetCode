//
//  114	Flatten Binary Tree to Linked List.cpp
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
    vector<TreeNode *> preOrder;
    void flatten(TreeNode *root) {
        if (root) {
            preSearch(root);
        }
        else{
            return;
        }
        for (int i=0; i<preOrder.size()-1; i++) {
            preOrder[i]->left=NULL;
            preOrder[i]->right=preOrder[i+1];
        }
        preOrder.back()->left=NULL;
    }
    void preSearch(TreeNode *root){
        preOrder.push_back(root);
        if (root->left) {
            preSearch(root->left);
        }
        if (root->right) {
            preSearch(root->right);
        }
    }
};
//
//  101	Symmetric Tree.cpp
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
    vector<int> nodes;
    int count=0;
    bool symmetric=true;
    bool isSymmetric(TreeNode *root) {
        
        BFSL(root);
        BFSR(root);
        return symmetric;
    }
    void BFSL(TreeNode *root) {
        if (root==NULL) {
            nodes.push_back(-1);
            return;
        }
        if (root->left==NULL&&root->right==NULL) {
            nodes.push_back(root->val);
            return;
        }
        nodes.push_back(root->val);
        BFSL(root->left);
        BFSL(root->right);
    }
    void BFSR(TreeNode *root) {
        if (root==NULL) {
            if (nodes[count]!=-1) {
                symmetric=false;
            }
            count++;
            return;
        }
        if (nodes[count]!=root->val) {
            symmetric=false;
        }
        count++;
        if (root->left==NULL&&root->right==NULL) {
            return;
        }
        BFSR(root->right);
        BFSR(root->left);
    }
};
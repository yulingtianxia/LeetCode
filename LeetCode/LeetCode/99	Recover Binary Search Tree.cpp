//
//  99	Recover Binary Search Tree.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    TreeNode *mistake1;
    TreeNode *mistake2;
    TreeNode *last;
    void recoverTree(TreeNode *root) {
        if (root) {
            inorderMorrisTraversal(root);
        }
    }
    void inorderMorrisTraversal(TreeNode *root) {
        TreeNode *current=root,*previous;
        while (current) {
            if (!current->left) {
                output(current);
                current=current->right;
                continue;
            }
            previous=current->left;
            while (previous->right&&previous->right!=current) {
                previous=previous->right;
            }
            if (!previous->right) {
                previous->right=current;
                current=current->left;
            }
            else{
                previous->right=NULL;
                output(current);
                current=current->right;
            }
        }
        swap(mistake1->val, mistake2->val);
    }
    void output(TreeNode *root){
        if (!last) {
            last=root;
            return;
        }
        if (root->val<last->val) {
            if (!mistake1) {
                mistake1=last;
            }
            mistake2=root;
        }
        last=root;
    }
};
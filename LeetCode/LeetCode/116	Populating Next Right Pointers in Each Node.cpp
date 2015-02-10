//
//  116	Populating Next Right Pointers in Each Node.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (root->left) {
            root->left->next=root->right;
            if (root->next) {
                root->right->next=root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        else{
            return;
        }
    }
};
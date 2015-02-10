//
//  117	Populating Next Right Pointers in Each Node II.cpp
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
        TreeLinkNode *p=root;
        if (root->left&&root->right) {
            root->left->next=root->right;
            while (root->next) {
                if(root->next->left){
                    p->right->next=root->next->left;
                    break;
                }
                else if(root->next->right){
                    p->right->next=root->next->right;
                    break;
                }
                else{
                    root=root->next;
                }
            }
            connect(p->right);
            connect(p->left);
        }
        else if(root->left){
            while (root->next) {
                if(root->next->left){
                    p->left->next=root->next->left;
                    break;
                }
                else if(root->next->right){
                    p->left->next=root->next->right;
                    break;
                }
                else{
                    root=root->next;
                }
            }
            connect(p->left);
        }
        else if(root->right){
            while (root->next) {
                if(root->next->left){
                    p->right->next=root->next->left;
                    break;
                }
                else if(root->next->right){
                    p->right->next=root->next->right;
                    break;
                }
                else{
                    root=root->next;
                }
            }
            connect(p->right);
        }
        else{
            return;
        }
    }
};
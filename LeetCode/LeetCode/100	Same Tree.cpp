//
//  100	Same Tree.cpp
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p==NULL&&q==NULL) {
            return true;
        }
        else if (p==NULL||q==NULL||(p->val!=q->val)) {
            return false;
        }
        else if(p->val==q->val){
            return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
        }
        return false;
    }
};
//
//  95	Unique Binary Search Trees II.cpp
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
    int count=0;
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *>result;
        if (n==0) {
            result.push_back(NULL);
            return result;
        }
        for (int i=0; i<n; i++) {
            vector<TreeNode *>left=generateTrees(i);
            vector<TreeNode *>right=generateTrees(n-1-i);
            for (int m=0; m<left.size(); m++) {
                for (int n=0; n<right.size(); n++) {
                    TreeNode *root = new TreeNode(1);
                    root->left=left[m];
                    root->right=right[n];
                    result.push_back(root);
                }
            }
        }
        for (int i=0; i<result.size(); i++) {
            count=0;
            preorder(result[i]);
        }
        return result;
    }
    void preorder(TreeNode *root){
        if (root) {
            preorder(root->left);
            root->val=++count;
            preorder(root->right);
        }
    }
};
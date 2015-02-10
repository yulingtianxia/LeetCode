//
//  98	Validate Binary Search Tree.cpp
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
    vector<int> array;
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }
        midOrderDFS(root);
        for (int i=0; i<array.size()-1; i++) {
            if (array[i]>=array[i+1]) {
                return false;
            }
        }
        return true;
    }
    void midOrderDFS(TreeNode *root){
        if (root->left) {
            midOrderDFS(root->left);
        }
        array.push_back(root->val);
        if (root->right) {
            midOrderDFS(root->right);
        }
    }
};
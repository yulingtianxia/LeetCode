//
//  108	Convert Sorted Array to Binary Search Tree.cpp
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size()<1) {
            return NULL;
        }
        if (num.size()==1) {
            return new TreeNode(num[0]);
        }
        int divide = (num.size()-1)/2;
        TreeNode *root = new TreeNode(num[divide]);
        vector<int> left;
        vector<int> right;
        copy(num.begin(), num.begin()+divide, back_inserter(left));
        copy(num.begin()+divide+1, num.end(), back_inserter(right));
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
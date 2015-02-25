//
//  105	Construct Binary Tree from Preorder and Inorder Traversal.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/25.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelper(preorder, inorder, 0, (int)inorder.size()-1);
    }
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder,int left, int right) {
        if (left==right) {
            return new TreeNode(inorder[left]);
        }
        for (int j=0; j<(int)preorder.size(); j++) {
            for (int i=left; i<=right; i++) {
                if (inorder[i]==preorder[j]) {
                    TreeNode *leftTree=NULL,*rightTree=NULL;
                    preorder.erase(preorder.begin()+j);
                    if (left!=i) {
                        leftTree = buildTreeHelper(preorder, inorder, left, i-1);
                    }
                    if (right!=i) {
                        rightTree = buildTreeHelper(preorder, inorder, i+1, right);
                    }
                    auto root = new TreeNode(inorder[i]);
                    root->left=leftTree;
                    root->right=rightTree;
                    return root;
                }
            }
        }
        return NULL;
    }
};
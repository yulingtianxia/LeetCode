//
//  106	Construct Binary Tree from Inorder and Postorder Traversal.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/25.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper(inorder, postorder, 0, (int)inorder.size()-1);
    }
    TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder,int left, int right) {
        if (left==right) {
            return new TreeNode(inorder[left]);
        }
        for (int j=(int)postorder.size()-1; j>=0; j--) {
            for (int i=left; i<=right; i++) {
                if (inorder[i]==postorder[j]) {
                    TreeNode *leftTree=NULL,*rightTree=NULL;
                    postorder.erase(postorder.begin()+j);
                    if (left!=i) {
                        leftTree = buildTreeHelper(inorder, postorder, left, i-1);
                    }
                    if (right!=i) {
                        rightTree = buildTreeHelper(inorder, postorder, i+1, right);
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
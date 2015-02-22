//
//  145	Binary Tree Postorder Traversal.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/22.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root) {
            stack<TreeNode *> nodes;
            nodes.push(root);
            while (!nodes.empty()) {
                TreeNode *top = nodes.top();
                if ((!top->left)&&(!top->right)) {
                    result.push_back(top->val);
                    nodes.pop();
                }
                if (top->right) {
                    nodes.push(top->right);
                    top->right=NULL;
                }
                if (top->left) {
                    nodes.push(top->left);
                    top->left=NULL;
                }
            }
        }
        return result;
    }
};
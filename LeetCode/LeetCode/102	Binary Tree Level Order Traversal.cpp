//
//  102	Binary Tree Level Order Traversal.cpp
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
    vector<vector<int> > result;
    vector<vector<int> > levelOrder(TreeNode *root) {
        BFS(root);
        return result;
    }
    void BFS(TreeNode *root) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (nodes.size()>0&&nodes.front()!=NULL) {
            queue<TreeNode *> temp;
            vector<int> level;
            while (nodes.size()>0) {
                if (nodes.front()->left!=NULL) {
                    temp.push(nodes.front()->left);
                }
                if (nodes.front()->right!=NULL) {
                    temp.push(nodes.front()->right);
                }
                level.push_back(nodes.front()->val);
                nodes.pop();
            }
            result.push_back(level);
            nodes = temp;
        }
    }
};
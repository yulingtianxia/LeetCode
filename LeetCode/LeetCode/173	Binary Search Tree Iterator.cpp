//
//  173	Binary Search Tree Iterator.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/21.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class BSTIterator {
public:
    vector<TreeNode *> path;
    BSTIterator(TreeNode *root) {
        findSmallest(root);
    }
    
    void findSmallest(TreeNode *root) {
        while (root) {
            path.push_back(root);
            root=root->left;
        }
    }
    
    void cleanRightSide() {
        while (path.size()>1&&path.back()==path[path.size()-2]->right) {
            path.pop_back();
        }
        path.pop_back();
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (path.size()==0) {
            return false;
        }
        return true;
    }
    
    /** @return the next smallest number */
    int next() {
        auto back = path.back();
        int result = back->val;
        if (!back->left&&!back->right) {
            if (path.size()>1&&back==path[path.size()-2]->left) {
                path.pop_back();
            }
            else if (path.size()>1&&back==path[path.size()-2]->right) {
                cleanRightSide();
            }
            else{
                path.pop_back();
            }
        }
        else if (back->right) {
            findSmallest(back->right);
        }
        else{
            cleanRightSide();
        }
        return result;
    }
};
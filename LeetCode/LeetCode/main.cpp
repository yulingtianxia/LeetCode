//
//  main.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 14/11/27.
//  Copyright (c) 2014年 杨萧玉. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <numeric>
#include <limits>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


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

int main(int argc, const char * argv[]) {
    // insert code here...
    auto a = new TreeNode(8);
    a->left = new TreeNode(3);
    a->right = new TreeNode(10);
    a->left->left = new TreeNode(1);
    a->left->right = new TreeNode(6);
    a->left->right->left = new TreeNode(4);
    a->left->right->right = new TreeNode(7);
    a->right->right = new TreeNode(14);
    a->right->right->left = new TreeNode(13);
    BSTIterator i = BSTIterator(a);
    while (i.hasNext()) {
        auto result = i.next();
        cout<<result<<endl;
    }
    return 0;
}
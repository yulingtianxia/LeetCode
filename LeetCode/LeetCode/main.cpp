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

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    TreeNode *a=new TreeNode(1);
    TreeNode *b=new TreeNode(2);
    TreeNode *c=new TreeNode(3);
    a->right = b;
    b->left = c;
    vector<int> result = s.postorderTraversal(a);
    return 0;
}
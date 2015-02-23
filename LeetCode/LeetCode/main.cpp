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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper(inorder, postorder, 0, (int)inorder.size()-1);
    }
    TreeNode *buildTreeHelper(vector<int> inorder, vector<int> postorder,int left, int right) {
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

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
//    vector<int> inorder(3000);
//    vector<int> postorder(3000);
//    iota(inorder.begin(), inorder.end(), -999);
//    iota(postorder.begin(), postorder.end(), -999);
    vector<int> inorder = {1,2};
    vector<int> postorder = {2,1};
    auto result = s.buildTree(inorder, postorder);
    return 0;
}
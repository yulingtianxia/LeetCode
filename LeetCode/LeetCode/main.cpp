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
    unordered_map<int, int> path;
    bool isHappy(int n) {
        int value=0;
        int key=n;
        while (n) {
            int temp = n%10;
            value+=temp*temp;
            n/=10;
        }
        if (value==1) {
            return true;
        }
        if (path.find(value)!=path.end()) {
            return false;
        }
        path[key]=value;
        return isHappy(value);
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
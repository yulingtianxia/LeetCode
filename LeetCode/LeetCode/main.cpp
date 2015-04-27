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
    stack<string> dirs;
    string dir;
    string result="";
    string simplifyPath(string path) {
        if (path.back()!='/') {
            path+="/";
        }
        for (auto ch:path) {
            if (ch=='/') {
                if (dir.length()>0) {
                    if (dir=="..") {
                        if (!dirs.empty()) {
                            dirs.pop();
                        }
                    }
                    else if (dir!=".") {
                        dirs.push(dir);
                    }
                    dir.clear();
                }
                continue;
            }
            dir.push_back(ch);
        }
        if (dirs.empty()) {
            return "/";
        }
        while (!dirs.empty()) {
            result.insert(0, "/"+dirs.top());
            dirs.pop();
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    string result = s.simplifyPath("/..");
    cout<<result;
    return 0;
}
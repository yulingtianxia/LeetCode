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
    unordered_set<int> substrings;
    vector<string> result;
    hash<string> mapping;
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length()<11) {
            return result;
        }
        for (int i=0; i<s.length()-9; i++) {
            string substr = s.substr(i,10);
            int sub = mapping(substr);
            if (substrings.find(sub)==substrings.end()) {
                substrings.insert(sub);
            }
            else {
                if(find(result.begin(), result.end(), substr)==result.end()) {
                    result.push_back(substr);
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    hash<string> mapping;
    long res1 = mapping("adkajfkdlajfkdljfklddsajkflkdsajfalksdjfkldasjfkladjsklfjaslkfjdslkj");
    long res2 = mapping("adkajfkdlajfkdljfklddsajkflkdsajfalksdjfkldasjfkladjsklfjaslkfjdslka");
    return 0;
}
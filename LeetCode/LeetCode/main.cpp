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
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
        int count=0;
        int ceil=sqrt(n);
        for (int i=2; i<n; i++) {
            if (isPrime[i]) {
                count++;
                if (i>ceil) {
                    continue;
                }
                for (int j=2*i; j<n; j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    s.countPrimes(120);
    return 0;
}
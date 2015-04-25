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
    void nextPermutation(vector<int> &num) {
        int biggestIndex=num.size()-1;
        for (int i=num.size()-2; i>=0; i--) {
            if (num[i]>=num[biggestIndex]) {
                biggestIndex=i;
            }
            else{
                int smallestBiggerThanIndex=i+1;
                for (int j=i+2; j<num.size(); j++) {
                    if (num[j]>num[i]&&num[j]<num[smallestBiggerThanIndex]) {
                        smallestBiggerThanIndex=j;
                    }
                }
                int temp=num[i];
                num[i]=num[smallestBiggerThanIndex];
                num[smallestBiggerThanIndex]=temp;
                sort(num.begin()+i+1, num.end());
                return;
            }
        }
        sort(num.begin(), num.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    vector<int> nums = {5,1,1};
    s.nextPermutation(nums);
    return 0;
}
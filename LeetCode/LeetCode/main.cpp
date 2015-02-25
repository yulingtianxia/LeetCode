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
    int result=0;
    int trap(int A[], int n) {
        vector<int> channels;
        int leftHill=0,rightHill=n-1;
        while (leftHill<rightHill) {
            if (A[leftHill]<=A[rightHill]) {//左侧向右推进
                do {
                    channels.push_back(A[leftHill++]);
                } while (leftHill<rightHill&&channels[0]>=A[leftHill]);
                trapHelper(channels);
            }
            else{//右侧向左推进
                do {
                    channels.push_back(A[rightHill--]);
                } while (leftHill<rightHill&&channels[0]>=A[rightHill]);
                trapHelper(channels);
            }
        }
        return result;
    }
    void trapHelper(vector<int> &channels){
        for (int i=0; i<channels.size(); i++) {
            result+=channels[0]-channels[i];
        }
        channels.clear();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    int A[] = {2,0,2};
    int result=s.trap(A, 3);
    return 0;
}
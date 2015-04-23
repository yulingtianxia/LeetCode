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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *last=head;
        ListNode *result=head;
        while (head) {
            if (head->val==val) {
                if (last!=head) {
                    head=head->next;
                    last->next=head;
                }
                else{
                    result=last=head=head->next;
                }
            }
            else{
                if (last!=head) {
                    last=last->next;
                }
                head=head->next;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    a->next=b;
    Solution s = Solution();
    s.removeElements(a, 2);
    return 0;
}
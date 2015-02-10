//
//  109	Convert Sorted List to Binary Search Tree.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *x = head;
        while (fast&&fast->next) {
            x=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        x->next=NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
//
//  2	Add Two Numbers.cpp
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
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1==NULL||l2==NULL) {
            return NULL;
        }
        ListNode *result = new ListNode(0);
        ListNode *root = result;
        while (l1!=NULL&&l2!=NULL) {
            result->val+=l1->val+l2->val;
            if (result->val>=10) {
                result->val-=10;
                result->next = new ListNode(1);
            }
            else{
                result->next = new ListNode(0);
            }
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1!=NULL) {
            result->val+=l1->val;
            if (result->val>=10) {
                result->val-=10;
                result->next = new ListNode(1);
            }
            else{
                result->next = new ListNode(0);
            }
            result = result->next;
            l1 = l1->next;
        }
        while (l2!=NULL) {
            result->val+=l2->val;
            if (result->val>=10) {
                result->val-=10;
                result->next = new ListNode(1);
            }
            else{
                result->next = new ListNode(0);
            }
            result = result->next;
            l2 = l2->next;
        }
        result = root;
        while (result->next->next!=NULL) {
            result = result->next;
        }
        if (result->next->val==0) {
            result->next = NULL;
        }
        return root;
    }
};
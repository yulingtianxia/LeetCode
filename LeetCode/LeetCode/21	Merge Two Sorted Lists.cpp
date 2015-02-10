//
//  21	Merge Two Sorted Lists.cpp
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1==NULL&&l2==NULL) {
            return NULL;
        }
        if (l1==NULL) {
            return l2;
        }
        if (l2==NULL) {
            return l1;
        }
        ListNode *result = l1->val<l2->val?l1:l2;
        ListNode *temp;
        ListNode *before = nullptr;
        while (l1!=NULL&&l2!=NULL) {
            if (l1->val<l2->val) {
                temp = l1;
                l1 = l1->next;
                temp->next = l2;
                if (before!=NULL) {
                    before->next = temp;
                }
                before = temp;
            }
            else{
                temp = l2;
                l2 = l2->next;
                temp->next = l1;
                if (before!=NULL) {
                    before->next = temp;
                }
                before = temp;
            }
        }
        return result;
    }
};
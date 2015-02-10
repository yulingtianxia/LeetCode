//
//  24	Swap Nodes in Pairs.cpp
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
    ListNode *swapPairs(ListNode *head) {
        if (!head||!head->next) {
            return head;
        }
        ListNode *p = NULL;
        ListNode *fast=head->next;
        ListNode *slow=head;
        head=head->next;
        while (fast) {
            slow->next=fast->next;
            fast->next=slow;
            if (p) {
                p->next=fast;
            }
            p=slow;
            if (slow->next) {
                fast=slow->next->next;
                slow=slow->next;
            }
            else{
                break;
            }
        }
        return head;
    }
};
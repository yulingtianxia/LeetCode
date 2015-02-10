//
//  141	Linked List Cycle.cpp
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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *l=head;
        ListNode *r=head;
        while (l->next) {
            if (l->next!=head) {
                r=l->next;
                l->next=head;
                l=r;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
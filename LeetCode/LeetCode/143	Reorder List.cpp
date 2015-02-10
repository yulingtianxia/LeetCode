//
//  143	Reorder List.cpp
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
    void reorderList(ListNode *head) {
        if (!head||!head->next) {
            return;
        }
        ListNode *s = head;
        ListNode *f = head;
        while (f&&f->next) {
            s=s->next;
            f=f->next->next;
        }
        f=s->next;
        s->next=NULL;
        while (f) {
            ListNode *temp = f->next;
            f->next=s;
            s=f;
            f=temp;
        }
        ListNode *needle=head;
        while (s->next) {
            ListNode *temp=needle->next;
            needle->next=s;
            needle=temp;
            temp=s->next;
            s->next=needle;
            s=temp;
        }
    }
};
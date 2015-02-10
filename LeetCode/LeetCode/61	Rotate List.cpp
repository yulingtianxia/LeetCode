//
//  61	Rotate List.cpp
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return NULL;
        }
        ListNode *s=head;
        ListNode *f=head;
        int length=1;
        while (f->next) {
            f=f->next;
            length++;
        }
        int rest=k%length;
        f=head;
        if (rest==0) {
            return head;
        }
        while (f->next&&rest>0) {
            f=f->next;
            rest--;
        }
        while (f->next) {
            s=s->next;
            f=f->next;
        }
        f->next=head;
        head=s->next;
        s->next=NULL;
        return head;
    }
};
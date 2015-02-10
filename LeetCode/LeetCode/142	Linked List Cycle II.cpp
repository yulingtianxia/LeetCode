//
//  142	Linked List Cycle II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *s=head;
        ListNode *f=head;
        while (f&&f->next) {
            f=f->next->next;
            s=s->next;
            if (s==f) {
                break;
            }
        }
        if (f&&f->next) {
            f=head;
            while (s!=f) {
                s=s->next;
                f=f->next;
            }
            return s;
        }
        return NULL;
    }
};
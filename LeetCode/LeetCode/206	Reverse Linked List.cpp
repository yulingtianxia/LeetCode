//
//  206	Reverse Linked List.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/5/20.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode *last=NULL;
        ListNode *current=head;
        ListNode *next=head->next;
        while (current) {
            current->next=last;
            last=current;
            current=next;
            if (next) {
                next=next->next;
            }
        }
        return last;
    }
};
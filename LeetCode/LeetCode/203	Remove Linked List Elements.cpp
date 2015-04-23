//
//  203	Remove Linked List Elements.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/23.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
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
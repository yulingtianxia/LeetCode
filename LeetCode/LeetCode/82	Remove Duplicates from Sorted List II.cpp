//
//  82	Remove Duplicates from Sorted List II.cpp
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
    set<int> link;
    set<int> duplicates;
    ListNode *temp;
    ListNode *deleteDuplicates(ListNode *head) {
        temp = head;
        ListNode *result = head;
        if (!head) {
            return NULL;
        }
        while (head) {
            if (link.find(head->val)==link.end()) {
                link.insert(head->val);
            }
            else{
                duplicates.insert(head->val);
                temp->next = temp->next->next;
                head = temp;
            }
            temp = head;
            head=head->next;
        }
        head=result;
        while (head->next) {
            if (duplicates.find(head->next->val)!=duplicates.end()) {
                head->next=head->next->next;
            }
            else{
                head=head->next;
            }
        }
        if (duplicates.find(result->val)!=duplicates.end()) {
            result=result->next;
        }
        return result;
    }
};
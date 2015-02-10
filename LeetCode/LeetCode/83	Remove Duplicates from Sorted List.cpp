//
//  83	Remove Duplicates from Sorted List.cpp
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
    ListNode *temp;
    ListNode *deleteDuplicates(ListNode *head) {
        temp = head;
        ListNode *result = head;
        while (head!=NULL) {
            if (link.find(head->val)==link.end()) {
                link.insert(head->val);
            }
            else{
                temp->next = temp->next->next;
                head = temp;
            }
            temp = head;
            head=head->next;
        }
        return result;
    }
};
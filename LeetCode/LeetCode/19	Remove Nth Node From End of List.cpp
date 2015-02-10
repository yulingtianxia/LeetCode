//
//  19	Remove Nth Node From End of List.cpp
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        ListNode *cache = head;
        ListNode *first = head;
        for (int i=0; i<n; i++) {
            first=first->next;
        }
        if (first==NULL) {
            return head->next;
        }
        while (first->next!=NULL) {
            cache=cache->next;
            first=first->next;
        }
        cache->next=cache->next->next;
        return head;
    }
};
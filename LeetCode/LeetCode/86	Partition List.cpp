//
//  86	Partition List.cpp
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
    ListNode *partition(ListNode *head, int x) {
        if (!head||!head->next) {
            return head;
        }
        ListNode *low=NULL;
        ListNode *high=NULL;
        ListNode *needle=head;
        ListNode *highhead=NULL;
        while (needle) {
            if (needle->val<x) {
                if (low) {
                    low->next=needle;
                    low=low->next;
                }
                else{
                    low=needle;
                    head=low;
                }
            }
            else{
                if (high) {
                    high->next=needle;
                    high=high->next;
                }
                else{
                    high=needle;
                    highhead=needle;
                }
            }
            needle=needle->next;
        }
        if (high) {
            high->next=NULL;
        }
        if (low) {
            low->next=highhead;
        }
        return head;
    }
};
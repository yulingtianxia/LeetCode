//
//  148	Sort List.cpp
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
    ListNode *high;
    ListNode *low;
    ListNode *k1;
    ListNode *k2;
    ListNode *sortList(ListNode *head) {
        low=head;
        high=head;
        return partitionSort(head, NULL);
    }
    ListNode *partitionSort(ListNode *head,ListNode *foot){
        if (head==foot||!head->next) {
            return head;
        }
        if (head->next==foot&&head->val<=foot->val) {
            return head;
        }
        partition(head, foot);
        ListNode *l=low;
        ListNode *h=high;
        ListNode *kk1=k1;
        ListNode *kk2=k2;
        ListNode *result=partitionSort(l, kk1);
        if (kk2->next) {
            kk2->next=partitionSort(kk2->next, h);
        }
        
        return result;
    }
    void partition(ListNode *head,ListNode *foot){
        low=head;
        high=head;
        k1=head;
        k2=head;
        if (head==foot||!head->next) {
            return;
        }
        while (high!=foot) {
            if (high->next&&high->next->val<head->val) {
                ListNode *temp = high->next;
                high->next=temp->next;
                temp->next=low;
                low=temp;
            }
            else if(high!=k1&&high->next&&high->next->val==head->val){
                ListNode *temp = k2->next;
                k2->next=high->next;
                high->next=high->next->next;
                k2=k2->next;
                k2->next=temp;
            }
            else{
                high=high->next;
            }
        }
    }
};
//
//  147	Insertion Sort List.cpp
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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *p = head->next;
        ListNode *pf = head;
        ListNode *q = head;
        ListNode *qf = NULL;
        while (p) {
            if (q->val>p->val) {
                q=head;
                qf=NULL;
            }
            while (q!=p) {
                if (q->val<=p->val) {
                    qf=q;
                    q=q->next;
                }
                else{
                    pf->next=p->next;
                    p->next=q;
                    if (qf) {
                        qf->next=p;
                    }
                    else{
                        head=p;
                    }
                    break;
                }
            }
            pf=p;
            p=p->next;
        }
        return head;
    }
};
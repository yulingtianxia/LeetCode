//
//  160	Intersection of Two Linked Lists.cpp
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
 **/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL||headB==NULL) {
            return NULL;
        }
        ListNode *la;
        ListNode *lb;
        int lengthA = 1;
        int lengthB = 1;
        la = headA;
        while (la->next!=NULL) {
            la = la->next;
            lengthA++;
        }
        lb = headB;
        while (lb->next!=NULL) {
            lb = lb->next;
            lengthB++;
        }
        la = headA;
        lb = headB;
        if (lengthA >= lengthB) {
            for (int i = 0; i<lengthA-lengthB; i++) {
                la = la->next;
            }
        }
        else{
            for (int i = 0; i<lengthB-lengthA; i++) {
                lb = lb->next;
            }
        }
        if (la->val==lb->val) {
            return la;
        }
        while (la->next!=NULL) {
            if (la->next->val!=lb->next->val) {
                la = la->next;
                lb = lb->next;
            }
            else{
                return la->next;
            }
        }
        return NULL;
    }
};

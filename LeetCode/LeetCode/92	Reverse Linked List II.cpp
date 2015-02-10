//
//  92	Reverse Linked List II.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m==n) {
            return head;
        }
        ListNode *myHead = new ListNode(0);
        myHead->next=head;
        head=myHead;
        ListNode *s=head;
        ListNode *f=head;
        ListNode *pref=head;
        ListNode *pres=head;
        int count=0;
        while (count<=n) {
            if (count<m) {
                pres=s;
                s=s->next;
                pref=s;
                f=f->next;
            }
            else if(count>m){
                ListNode *temp=f->next;
                f->next=pref;
                pref=f;
                f=temp;
            }
            else{
                f=f->next;
            }
            count++;
        }
        s->next=f;
        pres->next=pref;
        return head->next;
    }
};
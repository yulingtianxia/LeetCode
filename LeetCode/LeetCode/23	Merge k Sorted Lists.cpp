//
//  23	Merge k Sorted Lists.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/11.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *listA = nullptr;
        ListNode *listB = nullptr;
        ListNode *res = nullptr;
        if (lists.size()>2) {
            vector<ListNode *> left=vector<ListNode *>(lists.size()/2);
            vector<ListNode *> right=vector<ListNode *>(lists.size()-lists.size()/2);
            copy(lists.begin(), lists.begin()+lists.size()/2, left.begin());
            copy(lists.begin()+lists.size()/2, lists.end(), right.begin());
            listA=mergeKLists(left);
            listB=mergeKLists(right);
        }
        else if(lists.size()==2){
            listA=lists[0];
            listB=lists[1];
        }
        else if(lists.size()==1){
            return lists[0];
        }
        else if(lists.size()==0){
            return NULL;
        }
        ListNode *needle = nullptr;
        while (listA&&listB) {
            if (listA->val<=listB->val) {
                if (needle) {
                    needle->next=listA;
                    needle=needle->next;
                }
                else{
                    needle=listA;
                    res=needle;
                }
                listA=listA->next;
            }
            else{
                if (needle) {
                    needle->next=listB;
                    needle=needle->next;
                }
                else{
                    needle=listB;
                    res=needle;
                }
                listB=listB->next;
            }
        }
        if (listA) {
            if (!res) {
                res=listA;
            }
            else{
                needle->next=listA;
            }
        }
        if (listB) {
            if (!res) {
                res=listB;
            }
            else{
                needle->next=listB;
            }
        }
        return res;
    }
};
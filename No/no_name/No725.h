//
// Created by 黄嘉强 on 2021/10/6.
//

#ifndef LEETCODERECORD_NO725_H
#define LEETCODERECORD_NO725_H

#include "stdc++.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector < ListNode * > res(k);
        if (!head) return res;
        vector<int> count(k, 0);
        int len = 0;
        ListNode *temp = head, *pre;


        while (temp) {
            len++;
            temp = temp->next;
        }
        int i = len, j = 0;
        while (i-- > 0) {
            j %= k;
            count[j++]++;
        }

        temp = head;
        for (i = 0; i < min(k, len); i++) {
            j = 0;
            pre = temp;
            res[i] = temp;
            while (j++ < count[i]) {
                pre = temp;
              //  cout << temp->val << ' ';
                temp = temp->next;
            }
            //cout << endl;
            pre->next = nullptr;
        }
        return res;
    }
};


void test() {
    ListNode *head = new ListNode(1);
    ListNode *head1 = new ListNode(2);
    head->next = head1;
    ListNode *head2 = new ListNode(3);
    head1->next = head2;
    ListNode *head3 = new ListNode(4);
    head2->next = head3;
    ListNode *head4 = new ListNode(5);
    head3->next = head4;
    ListNode *head5 = new ListNode(6);
    head4->next = head5;
    ListNode *head6 = new ListNode(7);
    head5->next = head6;
    ListNode *head7 = new ListNode(8);
    head6->next = head7;
    ListNode *head8 = new ListNode(9);
    head7->next = head8;
    ListNode *head9 = new ListNode(10);
    head8->next = head9;
    Solution solution;
    solution.splitListToParts(head, 3);
}

#endif //LEETCODERECORD_NO725_H

//
// Created by 黄嘉强 on 2021/10/6.
//

#ifndef LEETCODERECORD_NO430_H
#define LEETCODERECORD_NO430_H

#include "stdc++.h"

using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};


class Solution {
public:
    Node *flatten(Node *head) {
        Node* dummy;dummy->next = head;

        Node* pre = nullptr, *mid = head, *temp;
        while(mid != nullptr){
            if(mid.child != nullptr){
                temp = flatten(mid->child);
                pre = mid;
                mid = mid->next;
                pre->next = temp;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = mid;
            }else{
                mid = mid->next;
            }
        }
        return dummy->next;
    }
};

#endif //LEETCODERECORD_NO430_H

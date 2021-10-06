//
// Created by 黄嘉强 on 2021/10/6.
//

#ifndef LEETCODERECORD_NO_414_H
#define LEETCODERECORD_NO_414_H

#include "../bits/stdc++.h"

using  namespace  std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums){
            pq.push(num);
        }
        int res;
        int i = 0;
        while(!pq.empty()){
            res = pq.top();
            pq.pop();
            if(i == 3) break;
        }
        return res;
    }
};

#endif //LEETCODERECORD_NO_414_H

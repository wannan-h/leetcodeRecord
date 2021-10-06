//
// Created by 黄嘉强 on 2021/10/6.
//

#ifndef LEETCODERECORD_NO_650_H
#define LEETCODERECORD_NO_650_H
//
// Created by 黄嘉强 on 2021/10/6.
//
//
// Created by 黄嘉强 on 2021/10/6.
//
#include "../bits/stdc++.h"
using  namespace  std;
class Solution {
public:
    int INF = INT_MAX;
    int minSteps(int n) {
        return dfs(n, 1, 0);
    }

    long dfs(int n, int cur, int cb){
        if(cur > n){
            return INF;
        }
        if(cur == n){
            return 0;
        }
        cout << cur << ' '<<cb<<endl;
        long res = INF;
        //paste
        if(cb > 0){
            res = dfs(n, cur + cb, cb);
        }

        //
        if(cb != cur){
            res = min(res, dfs(n, cur, cur));
        }
        return res + 1;
    }
};

#endif //LEETCODERECORD_NO_650_H

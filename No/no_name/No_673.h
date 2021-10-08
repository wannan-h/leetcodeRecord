//
// Created by 黄嘉强 on 2021/10/6.
//

#ifndef LEETCODERECORD_NO_673_H
#define LEETCODERECORD_NO_673_H

/*
 * 满足 f[i] < f[j] + 1
 * 说明 f[i]f[i] 会被 f[j] + 1f[j]+1 直接更新，此时同步直接更新 g[i] = g[j] 即可；
 *
 * 满足 f[i] = f[j] + 1
 * 说明找到了一个新的符合条件的前驱，此时将值继续累加到方案数当中，即有 g[i] += g[j]。
 * */

#include "./bits/stdc++.h"
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> dpLen(n, 1);
        int maxLen = 0;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        dpLen[i] = dpLen[j];
                    }else if(dp[i] == dp[j] + 1){
                        dpLen[i] += dpLen[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxLen){
                res += dpLen[i];
            }
        }
        return res;
    }
};
//10,9,2,5,3,7,101,18
class Solution30 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = INT_MIN;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] > nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

#endif //LEETCODERECORD_NO_673_H

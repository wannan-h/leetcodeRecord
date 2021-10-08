//
// Created by 黄嘉强 on 2021/10/6.
//

#ifndef LEETCODERECORD_NO583_H
#define LEETCODERECORD_NO583_H

#include "stdc++.h"

using namespace std;
//"sea", "eat"
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n1 - dp[n1][n2] + n2 - dp[n1][n2];
    }
};

void test(){
    string s1 = "sea", s2 = "eat";
    Solution solution;
    solution.minDistance(s1, s2);
}
#endif //LEETCODERECORD_NO583_H

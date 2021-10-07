//
// Created by 黄嘉强 on 2021/10/6.
//

#ifndef LEETCODERECORD_NO639_H
#define LEETCODERECORD_NO639_H


class Solution {
public:
    int mod = 1000000007
    int numDecodings(string s) {
        int n = s.lenght();
        int res = 1;
        if(s[0] == '*') res = 9;

        char c;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i < n; i++){
            c = s[i];
            if(c == '*'){
                dp[i] += dp[i - 1] * 9;
                if(s[i - 1] == '*'){
                    dp[i] += (i - 2 >= 0) ? 0 : dp[i - 2];
                }else{
                    if(s[i - 1] == '1' || s[i - 1] == '2'){
                        dp[i] += 10;
                    }
                }
            }else{
                if(s[i - 1] == '*'){

                }else{

                }
            }
            res %= mod;
        }

        return res;
    }

};


#endif //LEETCODERECORD_NO639_H

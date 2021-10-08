//
// Created by 黄嘉强 on 2021/10/8.
//

#ifndef LEETCODERECORD_NO_187_REPEAT_DNA_H
#define LEETCODERECORD_NO_187_REPEAT_DNA_H

#include "../bits/stdc++.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> map;
        //cout << "len="<<s.length()<<endl;
        string temp;
        for(int i = 0; i < s.length() - 9; i++){
            temp = s.substr(i, 10);
            if(map.find(temp) == map.end()){

            }
        }

        return res;
    }
};

void test(){
    unordered_map<string, int> map;
    map.insert({"123", 1});
    cout << map["123"]<< endl;
}


#endif //LEETCODERECORD_NO_187_REPEAT_DNA_H

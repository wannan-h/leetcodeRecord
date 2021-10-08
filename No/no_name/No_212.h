//
// Created by 黄嘉强 on 2021/10/5.
//

#ifndef LEETCODERECORD_NO_212_H
#define LEETCODERECORD_NO_212_H

#include "stdc++.h"

using namespace std;

class Solution111 {
public:
    class TrieNode {
    public:
        string s;
        TrieNode *tns[26];

    };

    void insert(string s) {
        int u;
        TrieNode *temp = root;
        for (int i = 0; i < s.length(); i++) {
            u = s[i] - 'a';
            if (temp->tns[u] == nullptr) {
                temp->tns[u] = new TrieNode();
            }
            temp = temp->tns[u];
        }
        temp->s = s;
    }

public:
    TrieNode *root = new TrieNode();
    unordered_set<string> set;
    vector<vector<int>> dirs = {{0,  1},
                                {1,  0},
                                {0,  -1},
                                {-1, 0}};
    vector<vector<bool>> vis;
    int m, n;
public:
    vector<string> findWords(vector<vector<char>> &b, vector<string> &ws) {
        m = b.size(), n = b[0].size();
        vis.resize(m, vector<bool>(n, false));
        for (string w : ws) {
            insert(w);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (root->tns[b[i][j] - 'a'] == nullptr) continue;
                vis[i][j] = true;
                backtrace(b, i, j, root);
                vis[i][j] = false;
            }
        }

        vector<string> res;
        for (auto a : set) {
            res.push_back(a);
        }
        return res;
    }

    void backtrace(vector<vector<char>> &b, int i, int j, TrieNode *root) {
        if (!root->s.empty()) {
            set.insert(root->s);
            return;
        }
        int x, y;
        for (int i = 0; i < 4; i++) {
            x = i + dirs[i][0], y = j + dirs[i][1];
            if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y] == false && root->tns[b[x][y]] != nullptr) {
                vis[x][y] = true;
                backtrace(b, x, y, root->tns[b[x][y]]);
                vis[x][y] = false;
            }
        }
    }

};


#endif //LEETCODERECORD_NO_212_H

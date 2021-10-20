#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include "unordered_map"
#include "sys/socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>


using namespace std;

class Trie {
public:
    struct TrieNode{
        bool end;
        TrieNode* tns[26];
        TrieNode(){end = false;}
    };
    TrieNode* tn;
public:
    Trie() {
        tn = new TrieNode();
    }

    void insert(string w) {
        TrieNode* temp = tn;
        int i;
        for(char c : w){
            i = c - 'a';
            if(temp->tns[i] == nullptr) temp->tns[i] = new TrieNode();
            temp = temp->tns[i];
        }
        temp->end = true;
    }

    bool search(string w) {
        TrieNode* temp = tn;
        int i;
        for(char c : w){
            i = c - 'a';
            if(temp->tns[i] == nullptr) return false;
            temp = temp->tns[i];
        }
        return temp->end == true;
    }

    bool startsWith(string w) {
        TrieNode* temp = tn;
        int i;
        for(char c : w){
            i = c - 'a';
            if(temp->tns[i] == nullptr) return false;
            temp = temp->tns[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;
//第一个只出现一次的字符
char firstUniqChar(string s) {
    int* array = new int[26];

    for (char temp : s) {
        array[temp - 'a']++;
    }
    for (char res : s) {
        if (array[res - 'a'] == 1)
            return res;
    }
    return ' ';
}

int main(){
    string s;
    cin >> s;
    cout << firstUniqChar(s) << endl;
}
//用例：leetcode

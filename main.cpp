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
#include <sys/socket.h>

using namespace std;

struct Node{
    int k, v;
    Node* pre;
    Node* next;
    Node():k(0),v(0),pre(nullptr),next(nullptr){}
    Node(int _k, int _v):k(_k),v(_v),pre(nullptr),next(nullptr){}
};

class LRU{
public:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int size;//当前大小
    int capacity;//容量
public:
    int get(int objKey){
        if(cache.find(objKey) != cache.end()){
            Node* temp = cache[objKey];
            moveHead(temp);
            return temp->v;
        }else{
            return -1;
        }
    }

    void set(int k, int v){
        if(cache.find(k) == cache.end()){//当前key不存在当前缓冲中，则创建缓冲并放到链表头部
            Node* node = new Node(k, v);
            cache[k] = node;
            addHead(node);
            size++;
            if(size > capacity){//超出容量，删除链表最后一个元素
                Node* temp = deleteTail();
                cache.erase(temp->k);
                delete temp;
                size--;
            }
        }else{//key已经存在，更新value，然后将key放到链表头部
            Node* temp = cache[k];
            temp->v = v;
            moveHead(temp);//2^32 - 1024
        }
    }

    void addHead(Node* node){//新的key加到头部
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    Node* deleteTail(){
        Node* temp = tail->pre;
        removeNode(temp);
        return temp;
    }

    void removeNode(Node* node){//当前节点前后指针修改
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveHead(Node* node){//已经存在的key加到头部
        removeNode(node);
        addHead(node);
    }

    LRU(int _capacity){
        capacity = _capacity;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
};

int main(){
    LRU lru(3);
    cout << lru.get(1) << endl;

    lru.set(1, 11);
    cout << lru.get(1) << endl;
    lru.set(2, 22);
    cout << lru.get(2) << endl;
    lru.set(3, 33);
    cout << lru.get(3) << endl;

    lru.set(4, 44);
    cout << lru.get(1) << endl;
    cout << lru.get(4) << endl;

    lru.set(4, 444);
    cout << lru.get(4) << endl;

}
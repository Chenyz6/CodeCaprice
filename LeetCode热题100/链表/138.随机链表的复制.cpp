// https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-100-liked
#include <unordered_map>
#include <iostream>
#include <stddef.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 哈希表
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        Node* newNode = new Node(-1);
        Node* newCur = newNode;
        while(cur != nullptr){
            Node* temp = new Node(-1);
            temp->val = cur->val;
            newCur->next = temp;
            map.insert(make_pair(cur, temp));
            newCur = newCur->next;
            cur = cur->next;
        }
        cur = head;
        newCur = newNode->next;
        while(cur != nullptr){
            newCur->random = map[cur->random];
            cur = cur->next;
            newCur = newCur->next;
        }
        return newNode->next;
    }
};
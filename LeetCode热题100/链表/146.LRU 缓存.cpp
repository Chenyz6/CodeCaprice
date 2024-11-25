// https://leetcode.cn/problems/lru-cache/description/?envType=study-plan-v2&envId=top-100-liked
#include <unordered_map>
using namespace std;

class LRUCache {
    struct DLinkedNode{
        int key, val;
        DLinkedNode* pre;
        DLinkedNode* next;
        DLinkedNode(): key(0), val(0), pre(nullptr), next(nullptr) {}
        DLinkedNode(int _key, int _value): key(_key), val(_value), pre(nullptr), next(nullptr) {}
    };
public:
    LRUCache(int capacity): capacity(capacity), size(0){
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkedNode* cur = cache[key];
        MoveToHead(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            AddToHead(node);
            size++;
            if(size > capacity){
                DLinkedNode* removed = RemoveTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }else{
            DLinkedNode* node = cache[key];
            node->val = value;
            MoveToHead(node);
        }
    }

    void MoveToHead(DLinkedNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        DLinkedNode* next = head->next;
        head->next = node;
        node->next = next;
        next->pre = node;
        node->pre = head;
    }

    DLinkedNode* RemoveTail(){
        DLinkedNode* node = tail->pre;
        node->pre->next = tail;
        tail->pre = node->pre;
        return node;
    }

    void AddToHead(DLinkedNode* node){
        DLinkedNode* next = head->next;
        head->next = node;
        node->next = next;
        next->pre = node;
        node->pre = head;
    }
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
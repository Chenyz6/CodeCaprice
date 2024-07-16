#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
 
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if(n < 1 || m < 1) return -1;
        list<int> numbers;
        for(int i = 0; i < n; i++){
            numbers.push_back(i);
        }
        list<int>::iterator cur = numbers.begin();
        while(numbers.size() > 1){
            for(int i = 1; i < m; i++){
                cur++;
                if(cur == numbers.end()) cur = numbers.begin();
            }
            list<int>::iterator next = ++cur;
            if(next == numbers.end()) next = numbers.begin();
            numbers.erase(--cur);
            cur = next;
        }
        return *cur;
    }
};

int main()
{
    return 0;
}
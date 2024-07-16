#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
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

#include <unordered_map>
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        unordered_map<char, int> map;
        for(int i = 0; i < str.size(); i++){
            map[str[i]]++;
        }
        for(int i = 0; i < str.size(); i++){
            if(map[str[i]] == 1) return i;
        }
        return -1;
    }
};

int main()
{
    return 0;
}
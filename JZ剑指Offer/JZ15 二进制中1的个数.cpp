#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
    int NumberOf1(int n) {
        int result = 0;
        unsigned int flag = 1;
        while (flag) {
            if(n & flag) result++;
            flag = flag << 1;
        }
        return result;
    }
};

// 优化解法
class Solution {
public:
    int NumberOf1(int n) {
        int result = 0;
        while (n)
        {
            result++;
            n = (n - 1) & n;
        }
        return result;
    }
};

int main()
{
    return 0;
}
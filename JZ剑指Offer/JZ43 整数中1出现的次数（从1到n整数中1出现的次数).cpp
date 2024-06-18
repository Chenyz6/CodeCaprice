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

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int res = 0;
        //MulBase = 10^i
        long long MulBase = 1;
        //每位数按照公式计算
        for(int i = 0; MulBase <= n; i++){ 
            //根据公式添加
            res += (n / (MulBase * 10)) * MulBase + min(max(n % (MulBase * 10) - MulBase + 1, (long long)0), MulBase);
            //扩大一位数
            MulBase *= 10; 
        }
        return res;
    }
};

int main()
{
    return 0;
}
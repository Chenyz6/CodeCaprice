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
    vector<int> multiply(const vector<int>& A) {
        //初始化数组B
        vector<int> B(A.size(), 1);
        //先乘左边，从左到右
        for(int i = 1; i < A.size(); i++)
            //每多一位由数组B左边的元素多乘一个前面A的元素
            B[i] = B[i - 1] * A[i - 1];
        int temp = 1;
        //再乘右边，从右到左
        for(int i = A.size() - 1; i >= 0; i--){
            //temp为右边的累乘
            B[i] *= temp;
            temp *= A[i];
        }
        return B;
    }
};


int main()
{
    return 0;
}
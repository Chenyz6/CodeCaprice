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

#include <string>
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() == 0) return {};
        int num = n % str.size();
        string result(str.begin() + num, str.end());
        string end(str.begin(), str.begin() + num);
        result += end;
        return result;
    }
};

int main()
{
    return 0;
}
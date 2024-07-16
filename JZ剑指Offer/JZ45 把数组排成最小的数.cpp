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
    //重载排序比较方式
    static bool cmp(string& x, string& y) {
        //叠加
        return x + y < y + x;
    }
    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        //空数组的情况
        if (numbers.size() == 0)
            return res;
        vector<string> nums;
        //将数字转成字符
        for (int i = 0; i < numbers.size(); i++)
            nums.push_back(to_string(numbers[i]));
        //排序
        sort(nums.begin(), nums.end(), cmp);
        //字符串叠加
        for (int i = 0; i < nums.size(); i++)
            res += nums[i];
        return res;
    }
};


int main()
{
    return 0;
}
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
    int solve(string nums) {
        if(nums == "0" || nums.size() == 0) return 0;
        if(nums == "10" || nums == "20") return 1;
        if(nums.size() == 1) return 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == '0' && nums[i - 1] != '1' && nums[i - 1] != '2') return 0;
        }
        vector<int> dp(nums.size() + 1, 1);
        for(int i = 2; i <= nums.size(); i++){
            if((nums[i - 2] == '1' && nums[i - 1] != '0') || 
                (nums[i - 2] == '2' && nums[i - 1] <= '6' && nums[i - 1] >= '1'))
                dp[i] = dp[i - 2] + dp[i - 1];
            else{
                dp[i] = dp[i - 1];
            }
        }
        return dp[nums.size()];    // "31717126241541717"
    }
};

int main()
{
    return 0;
}
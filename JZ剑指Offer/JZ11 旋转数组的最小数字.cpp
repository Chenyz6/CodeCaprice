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
    int MinInOrder(vector<int>& nums, int left, int right){
        for(int i = left + 1; i <= right; i++){
            if(nums[i] < nums[i - 1]) return nums[i];
        }
        return nums[left];
    }

    int minNumberInRotateArray(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int left = 0; int right = nums.size() - 1;
        int mid = left;
        while (nums[left] >= nums[right])
        {
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                return MinInOrder(nums, left, right);
            }
            if(right - left == 1) return nums[right];
            mid = (left + right) / 2;
            if(nums[mid] >= nums[left]){
                left = mid;
            }else if(nums[mid] <= nums[right]){
                right = mid;
            }
        }
        return nums[mid];
    }
};

int main()
{
    return 0;
}
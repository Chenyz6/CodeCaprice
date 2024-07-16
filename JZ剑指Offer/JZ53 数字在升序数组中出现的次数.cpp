#include <climits>
#include <vector>

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

// 优化版本
#include <climits>
#include <vector>
class Solution {
    int BinarySearch(vector<int>& nums, int k, bool bo){
        int left = 0, right = nums.size() - 1;
        int mid = INT_MIN;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(k < nums[mid]){
                right = mid - 1;
            }else if(k > nums[mid]){
                left = mid + 1;
            }else{
                if(bo && mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
                    right = mid - 1;
                }else if(!bo && mid + 1 < nums.size() && nums[mid] == nums[mid + 1]){
                    left = mid + 1;
                }else{
                    return mid;    
                }
                
            }
        }
        return -1;
    }
public:
    int GetNumberOfK(vector<int>& nums, int k) {
        int leftRet = BinarySearch(nums, k, true);
        int rightRet = BinarySearch(nums, k, false);
        if(leftRet == -1 || rightRet == -1) return 0;  // 注意返回判断
        int result = rightRet - leftRet + 1;
        if(result < 0 || nums.size() == 0) return 0;
        else return result;
    }
};


class Solution {
    int BinarySearch(vector<int>& nums, int k){
        int left = 0, right = nums.size() - 1;
        int mid = INT_MIN;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(k < nums[mid]){
                right = mid - 1;
            }else if(k > nums[mid]){
                left = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
public:
    int GetNumberOfK(vector<int>& nums, int k) {
        int ret = BinarySearch(nums, k);
        if(ret == -1) return 0;
        int result = 1;
        int index = ret;
        while(index + 1 < nums.size() && nums[++index] == nums[ret]){
            result++;
        }
        index = ret;
        while(index - 1 >= 0 && nums[--index] == nums[ret]){
            result++;
        }
        return result;
    }
};

int main()
{
    return 0;
}
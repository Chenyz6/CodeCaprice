// https://leetcode.cn/problems/maximum-binary-tree/description/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int max = INT32_MIN;
    int maxIndex = INT32_MIN;
    
public:
    TreeNode* traversal(vector<int>& nums){
        TreeNode * node = new TreeNode;
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                maxIndex = i;
            }
        }
        node->val = max;       
        if(maxIndex >= 0){
            vector<int> left(nums.begin(), nums.begin() + maxIndex);  
            node->left = traversal(left);
        }
        if(maxIndex < nums.size()){
            vector<int> right(nums.begin() + maxIndex + 1, nums.end());  
            node->right = traversal(right);
        }
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums);
    }
};

int main()
{
    Solution s;vector<int> v{3,2,1,6,0,5};
    s.constructMaximumBinaryTree(v);
}

#include <iostream>
#include <vector>
#include <algorithm>
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

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        if(preOrder.size() == 0 || vinOrder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preOrder[0]);
        int index = 0;
        for(int i = 0; i < vinOrder.size(); i++){
            if(vinOrder[i] == preOrder[0]){
                index = i; break;
            }
        }
        vector<int> left_preOrder(preOrder.begin() + 1, preOrder.begin() + index + 1);
        vector<int> right_preOrder(preOrder.begin() + index + 1, preOrder.end());

        vector<int> left_vinOrder(vinOrder.begin(), vinOrder.begin() + index);
        vector<int> right_vinOrder(vinOrder.begin() + index + 1, vinOrder.end());

        root->left = reConstructBinaryTree(left_preOrder, left_vinOrder);
        root->right = reConstructBinaryTree(right_preOrder, right_vinOrder);
        return root;
    }
};

int main()
{
    return 0;
}
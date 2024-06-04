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

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
private:
    vector<TreeLinkNode*> inorder_v;
    int index;
public:
    void inorder(TreeLinkNode* node, TreeLinkNode* find){
        if(node == nullptr) return;
        inorder(node->left, find);
        if(find == node) index = inorder_v.size();
        inorder_v.push_back(node);
        inorder(node->right, find);
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* root = pNode;
        // 获取根节点
        while(root->next) root = root->next; 

        inorder(root, pNode);
        if(index + 1 >= inorder_v.size()) return nullptr;
        return inorder_v[index + 1];
    }
};

// 官方题解   直接寻找 !!!!
class Solution1 {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == nullptr) return nullptr;
        TreeLinkNode* temp = pNode;
        if(temp->right != nullptr){
            temp = temp->right;
            while (temp->left != nullptr){
                temp = temp->left;
            }
            return temp;
        }else if(temp->next != nullptr){
            TreeLinkNode* pParent = temp->next;
            while(pParent != nullptr && pParent->right == temp){
                temp = pParent;
                pParent = pParent->next;
            }
            return pParent;
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}
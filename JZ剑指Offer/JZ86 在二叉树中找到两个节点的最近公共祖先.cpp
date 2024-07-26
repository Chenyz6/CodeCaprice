#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
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
    //记录是否找到到o的路径
    bool flag = false; 
    //求得根节点到目标节点的路径
    void dfs(TreeNode* root, vector<int>& path, int o){ 
        if(flag || root == NULL)
            return;
        path.push_back(root->val);
        //节点值都不同，可以直接用值比较
        if(root->val == o){ 
            flag = true;
            return;
        }
        //dfs遍历查找
        dfs(root->left, path, o); 
        dfs(root->right, path, o);
        //找到
        if(flag)
            return;
        //该子树没有，回溯
        path.pop_back(); 
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        vector<int> path1, path2; 
        //求根节点到两个节点的路径
        dfs(root, path1, o1); 
        //重置flag，查找下一个
        flag = false; 
        dfs(root, path2, o2);
        int res; 
        //比较两个路径，找到第一个不同的点
        for(int i = 0; i < path1.size() && i < path2.size(); i++){ 
            if(path1[i] == path2[i]) 
                //最后一个相同的节点就是最近公共祖先
                res = path1[i]; 
            else
                break;
        }
        return res;
    }
};


int main()
{
    return 0;
}
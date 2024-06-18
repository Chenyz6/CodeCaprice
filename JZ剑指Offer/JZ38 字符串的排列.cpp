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

int main()
{
    return 0;
}

class Solution {
public:
    vector<string> result;
    string path; 
    void backtracking(string str, vector<bool>& used)
    {
        if(path.size() == str.size()) {
            result.push_back(path);
            return;
        };
        for(int i = 0; i < str.size(); i++){
            if(used[i]) continue;
            if(i > 0 && used[i - 1] == true && str[i] == str[i -1]) continue;
            path += str[i];
            used[i] = true;
            backtracking(str, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<string> Permutation(string str) {
        if(str.empty()) return {};
        sort(str.begin(), str.end());
        vector<bool> used(str.size(), false);
        backtracking(str, used);
        return result;
    }
};
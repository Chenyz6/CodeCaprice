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

#include <vector>
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum <= 1) return {};
        vector<vector<int>> result;
        vector<int> path;
        int left = 1, right = 1;
        int m_sum = 1;
        while(left <= right && left <= sum){
            if(m_sum < sum){
                right++;
                m_sum += right;
            }else if(m_sum > sum){
                m_sum -= left;
                left++;
            }else {
                if(left == right) break;
                for(int i = left; i <= right; i++){
                    path.push_back(i);
                }
                result.push_back(path); path.clear();
                right++;
                m_sum += right;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
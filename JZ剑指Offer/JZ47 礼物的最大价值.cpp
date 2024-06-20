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

#include <algorithm>
class Solution {
public:
    int maxValue(vector<vector<int> >& grid) {
        if(grid.size() == 0) return 0;
        int end_x = grid.size() - 1, end_y = grid[0].size() - 1;
        for(int i = 1; i <= end_x; i++){
            grid[i][0] += grid[i - 1][0]; 
        }
        for(int i = 1; i <= end_y; i++){
            grid[0][i] += grid[0][i - 1];
        }
        for(int i = 1; i <= end_x; i++){
            for(int j = 1; j <= end_y; j++){
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[end_x][end_y];
    }
};

int main()
{
    return 0;
}
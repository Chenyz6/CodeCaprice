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

// 官方题解
class Solution {
  public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int n = matrix.size();
        //先排除特殊情况
        if (n == 0)
            return res;
        //左边界
        int left = 0;
        //右边界
        int right = matrix[0].size() - 1;
        //上边界
        int up = 0;
        //下边界
        int down = n - 1;
        //直到边界重合
        while (left <= right && up <= down) {
            //上边界的从左到右
            for (int i = left; i <= right; i++)
                res.push_back(matrix[up][i]);
            //上边界向下
            up++;
            if (up > down)
                break;
            //右边界的从上到下
            for (int i = up; i <= down; i++)
                res.push_back(matrix[i][right]);
            //右边界向左
            right--;
            if (left > right)
                break;
            //下边界的从右到左
            for (int i = right; i >= left; i--)
                res.push_back(matrix[down][i]);
            //下边界向上
            down--;
            if (up > down)
                break;
            //左边界的从下到上
            for (int i = down; i >= up; i--)
                res.push_back(matrix[i][left]);
            //左边界向右
            left++;
            if (left > right)
                break;
        }
        return res;
    }
};


// n*n矩阵方式
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.size() == 0) return {};
        vector<int> result;
        int begin = 0, end = matrix.size() - 1, step = end;
        for(int i = 0; i < matrix.size() / 2; i++){
            for(int i = begin; i < begin + step; i++){
                result.push_back(matrix[begin][i]);
            }
            for(int i = begin; i < begin + step; i++){
                result.push_back(matrix[i][end]);
            }
            for(int i = end; i > end - step; i--){
                result.push_back(matrix[end][i]);
            }
            for(int i = end; i > end - step; i--){
                result.push_back(matrix[i][begin]);
            }
            begin += 1; end -= 1; step -= 2;
        }
        if(matrix.size() % 2 == 1) 
            result.push_back(matrix[matrix.size() / 2][matrix.size() / 2]);
        return result;
    }
};

int main()
{
    return 0;
}
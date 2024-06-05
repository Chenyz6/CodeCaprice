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
    bool isEnter(int threshold, int row, int col){
        int sum = 0;
        while(row > 0){
            sum += row % 10;
            row /= 10;
        }
        while(col > 0){
            sum += col % 10;
            col /= 10;
        }
        if(sum > threshold) return false;
        else return true;
    }

    int backtracking(int threshold, int rows, int cols, int row, int col
                                    , vector<vector <bool> > & visited){
        if(rows < 0 || cols < 0 || visited[row][col] == true || row < 0
            || col < 0 || row >= rows || col >= cols) return 0;
        int nums = 0;    
        if(isEnter(threshold, row, col)){
            visited[row][col] = true;
            nums++;
            nums += backtracking(threshold, rows, cols, row + 1, col, visited);
            nums += backtracking(threshold, rows, cols, row, col + 1, visited);
            nums += backtracking(threshold, rows, cols, row - 1, col, visited);
            nums += backtracking(threshold, rows, cols, row , col - 1, visited);
        }
        return nums;
    }

    int movingCount(int threshold, int rows, int cols) {
        if(rows < 0 || cols < 0 || threshold < 0) return 0;
        int result = 0; 
        vector<vector <bool> > visited (rows, vector<bool> (cols, false));
        return backtracking(threshold, rows, cols, 0, 0, visited);
    }
};

int main()
{
    return 0;
}
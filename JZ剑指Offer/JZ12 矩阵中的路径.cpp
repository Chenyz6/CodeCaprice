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

// 官方题解
class Solution {
public:
    bool dfs(vector<vector<char> >& matrix, int n, int m, int i, int j, string word, int k, vector<vector<bool> >& flag){
        if(i < 0 || i >= n || j < 0 || j >= m || (matrix[i][j] != word[k]) || (flag[i][j] == true))
            //下标越界、字符不匹配、已经遍历过不能重复
            return false;
        //k为记录当前第几个字符
        if(k == word.length() - 1) 
            return true;
        flag[i][j] = true;
        //该结点任意方向可行就可
        if(dfs(matrix, n, m, i - 1, j, word, k + 1, flag)
          ||dfs(matrix, n, m, i + 1, j, word, k + 1, flag)
          ||dfs(matrix, n, m, i, j - 1, word, k + 1, flag)
          ||dfs(matrix, n, m, i , j + 1, word, k + 1, flag))
            return true; 
        //没找到经过此格的，此格未被占用
        flag[i][j] = false; 
        return false;
    }
    bool hasPath(vector<vector<char> >& matrix, string word) {
        //优先处理特殊情况
        if(matrix.size() == 0)
            return false;
        int n = matrix.size(); // 行
        int m = matrix[0].size();  // 列
        //初始化flag矩阵记录是否走过
        vector<vector<bool> > flag(n, vector<bool>(m, false)); 
        //遍历矩阵找起点
        for(int i = 0; i < n; i++){  
            for(int j = 0; j < m; j++){
                //通过dfs找到路径
                if(dfs(matrix, n, m, i, j, word, 0, flag))
                    return true;
            }
        }
        return false;
    }
};

// 错误
class Solution1 {
public:
    bool hasPath(vector<vector<char> >& matrix, string word) {
        int last_row = 0, last_column = 0;
        vector<vector<char> > visited (matrix.size(), vector<char>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); i++){
                if(matrix[i][j] == word[0]){
                    last_row = i, last_column = j;
                    if(word.size() == 1) return true;
                    for(int z = 1; z < word.size(); z++){
                        if(last_row - 1 >= 0 && matrix[last_row - 1][last_column] == word[z]){
                            if(visited[last_row - 1][last_column] == 0){
                                visited[last_row - 1][last_column] = 1;
                            }else{
                                return false;
                            }
                        }else if(last_column - 1 >= 0 && matrix[last_row][last_column - 1] == word[z]){
                            if(visited[last_row][last_column - 1] == 0){
                                visited[last_row][last_column - 1] = 1;
                            }else{
                                return false;
                            }
                        }else if(last_row + 1 < matrix.size() && matrix[last_row + 1][last_column]){
                            if(visited[last_row + 1][last_column] == 0){
                                visited[last_row + 1][last_column] = 1;
                            }else{
                                return false;
                            }
                        }else if(last_column + 1 < matrix[0].size() && matrix[last_row][last_column + 1]){
                            if(visited[last_row][last_column + 1] == 0){
                                visited[last_row][last_column + 1] = 1;
                            }else{
                                return false;
                            }
                        }
                    }
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
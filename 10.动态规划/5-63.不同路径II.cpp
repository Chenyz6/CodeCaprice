// https://leetcode.cn/problems/unique-paths-ii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int result = INT32_MIN;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector <vector <int>> dp(m, vector <int> (n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){  // column
            for(int j = 0; j < n; j++){   // row
                if(obstacleGrid[i][j] == 1) continue;
                if(i == 0 && j == 0) continue;
                int top = 0, left = 0;
                if(i - 1 >= 0) top = dp[i - 1][j];
                if(j - 1 >= 0) left = dp[i][j - 1];
                dp[i][j] = top + left;
            }
        }
        return dp[m - 1][n -1];
    }
};

int main()
{
    vector<vector<int>> v{{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    s.uniquePathsWithObstacles(v);
}
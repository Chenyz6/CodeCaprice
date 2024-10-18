// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> vec{1,2,3,4,5};
    cout << s.maxProfit(vec) << endl;
}
// https://leetcode.cn/problems/assign-cookies/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        for(int i = 0, j = 0; i < s.size() && j < g.size(); ){
            if(s[i] >= g[j]) {
                result++;
                j++;
                i++;
            }else{
                j++;
            }
        }
        return result;
    }
};


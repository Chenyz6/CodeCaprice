// https://leetcode.cn/problems/palindrome-partitioning/submissions/516246647/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
public:
    void backtracking(string s, int startIndex){
        if(startIndex == s.size()){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if (isPalindrome(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
                backtracking(s, i + 1);
            }else{
                continue;
            }
            path.pop_back();
        }
    }
    bool isPalindrome(string s, int startIndex, int i){
        for(int j = startIndex, k = i; j < k; j++, k--){
            if(s[j] != s[k]){
                return false;
            }
        }return true;
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};

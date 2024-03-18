// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const string map[10]{
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> result;
    string str;
    void backtracking(string digits, int startIndex){
        if(digits.size() == str.size()){
            result.push_back(str);
            return;
        }
        int digit = digits[startIndex] - '0'; 
        string s = map[digit];
        for(int i = 0; i < s.size(); i++){
            str.push_back(s[i]);
            backtracking(digits, startIndex + 1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};

int main(){
    Solution s;
    s.letterCombinations("23");
}
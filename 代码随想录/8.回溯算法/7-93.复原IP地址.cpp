// https://leetcode.cn/problems/restore-ip-addresses/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
private:
    vector<unsigned int> path;
    vector<string> result;
public:
    bool isValid(string& s, int begin, int end){
        if (begin > end) {   // 注意到到最后的位置会越过数组下标的位置
            return false;
        }
        if (s[begin] == '0' && begin != end) { 
            return false;
        }
        int num = 0;
        for(int i = begin; i <= end; i++){
            if(s[i] < '0' || s[i] > '9') return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }
    void backtracking(string& s, int startIndex, int pointNum){  
        if(pointNum == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                result.push_back(s);
            }
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};

int main()
{
    Solution s;
    s.restoreIpAddresses("101023");
}
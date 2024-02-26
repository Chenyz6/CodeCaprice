// https://leetcode.cn/problems/repeated-substring-pattern/description/
#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s + s;
        str.erase(str.begin());
        str.erase(str.end() - 1);
        cout << str.find(s) << endl;
        if(str.find(s) == string::npos) 
            return false;    
        else
            return true;
    }
};

int main()
{
    Solution s;
    string str = "acpcd";
    s.repeatedSubstringPattern(str);
    string temp = "cd";
    cout << str.find(temp);
    return 0;
}
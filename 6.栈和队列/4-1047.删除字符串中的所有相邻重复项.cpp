// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && s[i] != st.top()){
                st.push(s[i]);
            }else if (!st.empty() && s[i] == st.top()){
                st.pop();
            }else if (st.empty()){
                st.push(s[i]);
            }
        }
        s = "";
        while (!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    return 0;
}
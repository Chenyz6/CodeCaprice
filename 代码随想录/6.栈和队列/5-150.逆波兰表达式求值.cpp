// https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <long long> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(num2 + num1);
                else if(tokens[i] == "-") st.push(num2  - num1);
                else if(tokens[i] == "*") st.push(num2 * num1);
                else if(tokens[i] == "/") st.push(num2 / num1);
            }else{
                st.push(stoll(tokens[i]));
            }
        }
        return st.top();
    }
};

int main() 
{
    return 0;
}
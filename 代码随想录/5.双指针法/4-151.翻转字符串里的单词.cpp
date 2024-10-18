// https://leetcode.cn/problems/reverse-words-in-a-string/description/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    // 反转字符串--左闭右闭
    void reverse(string & str, int begin, int end){
        for(int i = begin, j = end; i < j; i++, j--){
            swap(str[i], str[j]);
        }
    }

    // 删除多余空格--双指针法(快慢指针)
    void deleteSpace(string & s){
        int slow = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                if(slow != 0) s[slow++] = ' ';
                while(s[i] != ' ' && i < s.size()){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        deleteSpace(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for(int i = 0; i <= s.size(); i++){ // 要包含数组最后一个位置  因为反转的是闭区间 
            if(s[i] == ' ' || i == s.size()){
                reverse(s, start, i - 1); 
                start = i + 1;
            }
        }
        return s;
    }
};
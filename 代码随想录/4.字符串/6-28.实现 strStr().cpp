// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include<iostream>
using namespace std;

// 暴力解法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int need = 0;
        int num = 0;
        for(int i = 0; i < haystack.size(); i++){
            int result = i;
            int temp = i;
            while(haystack[temp++] == needle[need++]){
                num++;
                if(need == needle.size()) return result;
            }
            need = 0;
        }
        return -1;
    }
};

// 前缀表不减一
class Solution1 {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {  // j指向前缀末尾位置，i指向后缀末尾位置
            while (j > 0 && s[i] != s[j]) {  // 判断不相等的情况
                j = next[j - 1]; 
            }
            if (s[i] == s[j]) {  // 判断相等的情况
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}

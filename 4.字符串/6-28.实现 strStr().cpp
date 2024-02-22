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

int main()
{
    return 0;
}
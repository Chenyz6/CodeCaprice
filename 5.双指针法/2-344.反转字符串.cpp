// https://leetcode.cn/problems/reverse-string/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() -1; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
};

int main()
{
    return 0;
}
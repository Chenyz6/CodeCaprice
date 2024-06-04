#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int num = 0; int size = s.size();
        if(size == 0) return "";
        for(int i = 0; i < size; i++){
            if(s[i] == ' ') num++;
        }
        s.resize(size + num * 2);
        int begin = size - 1;
        int end = size + num  * 2 - 1;
        while(begin >= 0){
            if(s[begin] != ' '){
                s[end--] = s[begin--];
            }else{
                s[end--] = '0'; s[end--] = '2'; s[end--] = '%';
                begin--;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.replaceSpace("We Are Happy");
    return 0;
}
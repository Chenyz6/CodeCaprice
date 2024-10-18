// https://leetcode.cn/problems/reverse-words-in-a-string/description/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 反转字符串--左闭右闭
    void reverse(string & str, int begin, int end){   // & 别忘了
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

// 删除多余的空格  ---  快慢指针方法
void removeExtraSpaces1(string& s)  // 去除所有空格并在相邻单词之间添加空格, 快慢指针。
{
	int slow = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] != ' ') {  // 只对字母进行处理   跳过空格
			if(slow != 0) s[slow++] = ' ';  // 主要对第一个位置进行判断  不是第一个要加空格
			while (s[i] != ' ' && i < s.size()){
				s[slow++] = s[i++];
			}
		}
	}
	s.resize(slow);
}

int main()
{
	string s = "dfsd";
	s.erase(s.begin() + 2); // 迭代器方式 只删除指定位置的元素
	cout << s << endl;      // dfd

	string s1 = "dfsd";
	s1.erase(2);			// 元素坐标方式 删除指定位置（包含指定位置）之后的所有元素
	cout << s1 << endl;     // df 
	return 0;
}
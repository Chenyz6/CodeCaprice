// https://leetcode.cn/problems/reverse-words-in-a-string/description/
#include <iostream>
#include <string>
using namespace std;

class Solution { // s = "the sky is blue"
public:
	string reverseWords(string s) {
		auto it_end = s.end();
		auto it_first = s.begin();
		string result = "";
		auto i = s.begin();
		while (i != s.end()) {
			while (*i == ' ')
			{
				it_end = i - 1;
				i++;
			}
			it_first = i; 
			result += reverse(it_first, it_end);
		}
		return 
	}
};

int main()
{
	string s = "dfsd";
	auto it = --s.end();
	cout << *it;
	system("pause");
	return 0;
}
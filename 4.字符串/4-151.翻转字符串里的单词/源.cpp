// https://leetcode.cn/problems/reverse-words-in-a-string/description/
#include <iostream>
#include <string>
using namespace std;

class Solution { // s = "the sky is blue"
public:
	string reverseWords(string s) {
		auto it_end = --s.end();
		auto it_first = --s.end(); 
		string result = "";
		for (auto i = --s.end(); i != s.begin(); i--) {
			if (*i != ' ') {
				it_end = i;
				continue;
			}
			else { // *i == ' '
				it_first = i++;
			}
		}
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
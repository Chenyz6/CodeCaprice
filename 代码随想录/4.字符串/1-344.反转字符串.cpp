// https://leetcode.cn/problems/reverse-string/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		for (int i = 0; i < s.size() / 2; i++)
		{
			char temp = 0;
			temp = s[i]; s[i] = s[s.size() - i - 1]; s[s.size() - i - 1] = temp;
		}
	}
};

int main()
{
	string s = "abcdefg";
	vector<char> v(s.begin(),s.end());
	Solution so;
	so.reverseString(v);
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;
	return 0;
}
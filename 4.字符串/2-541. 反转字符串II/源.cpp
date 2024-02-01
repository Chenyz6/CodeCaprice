// https://leetcode.cn/problems/reverse-string-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2*k)
		{
			if (i + k <= s.size()) {
				//reverse(s[i], s[i + k]);
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else {
				reverse(s.begin() + i, s.end());
				//reverse(s[i], s[s.size() - 1]);
			}
		}
		return s;
	}
};

int main()
{
	auto at = (int)22 + (long long)44;
	decltype(at) a;
	cout << typeid(at).name();
	system("pause");
}
// https://leetcode.cn/problems/valid-anagram/

#include <iostream>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int hash[26] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			hash[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++) {
			hash[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (hash[i] != 0) return false;
		}
		return true;
	}
};

int main()
{
	string s = "anagram";
	string t = "nagaram";
	Solution sol;
	cout << sol.isAnagram(s, t);
	system("pause");
}
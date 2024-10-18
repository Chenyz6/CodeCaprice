// https://leetcode.cn/problems/ransom-note/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int c[26] = { 0 };
		for (int i = 0; i < magazine.size(); i++)
		{
			c[magazine[i] - 'a']++;
		}
		for (int i = 0; i < ransomNote.size(); i++)
		{
			c[ransomNote[i] - 'a']--;
			if (c[ransomNote[i] - 'a'] < 0) {
				return false;
			}
		}
		return true;
	}
};

int main()
{
	system("pause");
	return 0;
}
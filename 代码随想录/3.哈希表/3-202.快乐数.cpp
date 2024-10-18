// https://leetcode.cn/problems/happy-number/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> set;
		int temp = n;
		while (1)
		{
			temp = GetSun(temp);
			if (temp == 1) return true;
			if (set.find(temp) == set.end()) {
				set.insert(temp);
			}else
			{
				return false;
			}
		}
	}

	int GetSun(int n)
	{
		int sum = 0;
		while (n != 0)
		{
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.isHappy(19);
	system("pause");
}

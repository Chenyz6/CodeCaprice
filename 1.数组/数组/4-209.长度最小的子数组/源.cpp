// https://leetcode.cn/problems/minimum-size-subarray-sum/
#include <iostream>
#include <vector>
using namespace std;
/*
����һ������ n ���������������һ�������� target ��
�ҳ����������������ܺʹ��ڵ��� target �ĳ�����С�� ����������[numsl, numsl + 1, ..., numsr - 1, numsr]
���������䳤�ȡ���������ڷ��������������飬���� 0 ��
ʾ�� 1��

���룺target = 7, nums = [2, 3, 1, 2, 4, 3]
�����2
���ͣ�������[4, 3] �Ǹ������µĳ�����С�������顣
ʾ�� 2��

���룺target = 4, nums = [1, 4, 4]
�����1
ʾ�� 3��

���룺target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]
�����0
*/
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) { // 2, 3, 1, 2, 4, 3
		int length = 0, sum = 0, min = 0;
		for (int i = 0; i < nums.size(); i++){
			sum = 0;
			length = 0;
			for (int j = 0; j < nums.size(); j++) {
				sum += nums[j];
				length++;
				if (sum >= target) {
					if (length < min) {
						min = length;
					}
					break;
				}
			}
		}
		return min;
	}
};

int main()
{
	Solution s;
	vector <int> v = { 2,3,1,2,4,3 };
	cout << s.minSubArrayLen(7, v);
	system("pause");
}
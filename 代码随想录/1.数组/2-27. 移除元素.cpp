// https://leetcode.cn/problems/remove-element/
#include <iostream>
#include <vector>
using namespace std;

// 2022.11.14
class Solution1 {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		int size = nums.size();
		int result = size;
		int k = nums.size() - 1;
		for (int i = 0; i < size; i++)
		{
			if (nums[i] == val)
			{
				result--;

				while (nums[k] == val)
				{
					if (i == k)
					{
						break;
					}
					k--, size--;
					result--;
					if (k < 0)
					{
						return 0;
					}
				}
				nums[i] = nums[k];
				k--, size--;
			}
		}
		return result;
	}
};

// ����˫ָ�뷨
// ��ָ�룺Ѱ���������Ԫ�� ����������ǲ�����Ŀ��Ԫ�ص�����
// ��ָ�룺ָ����� �������±��λ��
class Solution2 {
public:
	int removeElement(vector<int>& nums, int val) {
		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			if (nums[fastIndex] != val) {
				nums[slowIndex++] = nums[fastIndex];
			}
		}
		return slowIndex;
	}
};

int main()
{
	vector<int> v = { 0,1,2,2,3,0,4,2 };
	Solution2 s;
	cout << s.removeElement(v, 2);
	system("pause");
}
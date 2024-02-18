// https://leetcode.cn/problems/spiral-matrix-ii/
#include <iostream>
#include <vector>
using namespace std;

/*����һ�������� n������һ������ 1 �� n^2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���
ʾ��:
����: 3 ���: [ [ 1, 2, 3 ], 
			   [ 8, 9, 4 ], 
			   [ 7, 6, 5 ] ]*/

class Solution1 {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));
		int startx = 0, starty = 0;
		int loop = n / 2; // Ȧ��ѭ���Ĵ���
		int offset = 1; // ÿ��ѭ���Ľ�βƫ����
		int num = 1; // ��¼���������
		for (int i = 0; i < loop; i++) {
			int x = startx;
			int y = starty;
			for (; x < n - offset; x++) {
				result[x][y] = num++;
			}
			for (; y < n - offset; y++) {
				result[x][y] = num++;
			}
			for (; y > starty; y--) {
				result[x][y] = num++;
			}
			for (; x > startx; x--) {
				result[x][y] = num++;
			}
			startx++;
			starty++;

			offset += 1;
		}
		if (n % 2 != 0) {
			result[loop][loop] = num;
		}
		return result;
	}
};



class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0)); // ʹ��vector����һ����ά����
		int startx = 0, starty = 0; // ����ÿѭ��һ��Ȧ����ʼλ��
		int loop = n / 2; // ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
		int mid = n / 2; // �����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
		int count = 1; // ������������ÿһ���ո�ֵ
		int offset = 1; // ��Ҫ����ÿһ���߱����ĳ��ȣ�ÿ��ѭ���ұ߽�����һλ
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;

			// ģ��������д�����(����ҿ�)
			for (j = starty; j < n - offset; j++) {
				res[i][j] = count++;
			}
			// ģ��������д��ϵ���(����ҿ�)
			for (i = startx; i < n - offset; i++) {
				res[i][j] = count++;
			}
			// ģ��������д��ҵ���(����ҿ�)
			for (; j > starty; j--) {
				res[i][j] = count++;
			}
			// ģ��������д��µ���(����ҿ�)
			for (; i > startx; i--) {
				res[i][j] = count++;
			}

			// �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
			startx++;
			starty++;

			// offset ����ÿһȦ��ÿһ���߱����ĳ���
			offset += 1;
		}

		// ���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
		if (n % 2) {
			res[mid][mid] = count;
		}
		return res;
	}
};
 
int main()
{

	system("pause");
}
// https://leetcode.cn/problems/spiral-matrix-ii/
#include <iostream>
#include <vector>
using namespace std;

/*给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
示例:
输入: 3 输出: [ [ 1, 2, 3 ], 
			   [ 8, 9, 4 ], 
			   [ 7, 6, 5 ] ]*/

class Solution1 {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));
		int startx = 0, starty = 0;
		int loop = n / 2; // 圈数循环的次数
		int offset = 1; // 每次循环的结尾偏移量
		int num = 1; // 记录填入的数字
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
		vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
		int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
		int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
		int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
		int count = 1; // 用来给矩阵中每一个空格赋值
		int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;

			// 模拟填充上行从左到右(左闭右开)
			for (j = starty; j < n - offset; j++) {
				res[i][j] = count++;
			}
			// 模拟填充右列从上到下(左闭右开)
			for (i = startx; i < n - offset; i++) {
				res[i][j] = count++;
			}
			// 模拟填充下行从右到左(左闭右开)
			for (; j > starty; j--) {
				res[i][j] = count++;
			}
			// 模拟填充左列从下到上(左闭右开)
			for (; i > startx; i--) {
				res[i][j] = count++;
			}

			// 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
			startx++;
			starty++;

			// offset 控制每一圈里每一条边遍历的长度
			offset += 1;
		}

		// 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
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
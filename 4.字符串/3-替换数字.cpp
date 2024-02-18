// https://kamacoder.com/problempage.php?pid=1064
#include <iostream>
#include <string>
using namespace std;

string reverse(string str)
{
	string result;
	for (int i = 0; i < str.size(); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			result += "number";
		}
		else {
			result += str[i];
		}
	}
	return result;
}

string reverse1(string str)
{
	string s;
	while (cin >> s) {
		int count = 0; // 统计数字的个数
		int sOldSize = s.size();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				count++;
			}
		}
		// 扩充字符串s的大小，也就是每个空格替换成"number"之后的大小
		s.resize(s.size() + count * 5);
		int sNewSize = s.size();
		// 从后先前将空格替换为"number"
		for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
			if (s[j] > '9' || s[j] < '0') {
				s[i] = s[j];
			}
			else {
				s[i] = 'r';
				s[i - 1] = 'e';
				s[i - 2] = 'b';
				s[i - 3] = 'm';
				s[i - 4] = 'u';
				s[i - 5] = 'n';
				i -= 5;
			}
		}
		cout << s << endl;
	}
}

int main()
{
	string s = "12sde1";
	cout << reverse(s);
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

int my_function(int x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	int temp = my_function(x, n / 2);
	if (n % 2 == 1) {
		return temp * temp * x;
	}
	return temp * temp;
}

int main()
{
	cout << my_function(2, 2);
	system("pause");
}
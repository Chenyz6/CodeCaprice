#include <iostream>
#include <vector>
using namespace std;

// 快速排序
int Partition(int* arrays, int left, int right)
{
    int pivot = arrays[left];
    while(left < right){
        while(left < right && arrays[right] > pivot) right--;
        if(left < right) swap(arrays[left++], arrays[right]);
        while (left < right && arrays[left] < pivot) left++;
        if(left < right) swap(arrays[right--], arrays[left]);
    }
    return left;
}


void Quicksort(int* arrays, int low, int hight)
{
	int mid;
	if (low < hight)
	{
		mid = Partition(arrays, low, hight);  // 返回基准元素位置
		Quicksort(arrays, low, mid - 1); // 左区间递归快速排序
		Quicksort(arrays, mid + 1, hight); // 右区间递归快速排序
	}
}

int main()
{
    // vector<int> vec = {5,8,9,6,3,2,1,4,7};
    int arrays[] = {5,8,9,6,3,2,1,4,7};
    Quicksort(arrays, 0, 9);
    return 0;
}
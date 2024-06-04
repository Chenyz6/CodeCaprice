#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int duplicate(vector<int>& numbers) {
        int size = numbers.size();
        vector<int> num(size, 0); // 定义的时候适当大一点 不要有- 1的情况
        for(int i = 0; i < size; i++){
            if(numbers[i] > size - 1 || numbers[i] < 0) return -1; // 注意范围
            num[numbers[i]]++;
            if(num[numbers[i]] == 2) return numbers[i];
        }
        return -1;
    }
};

// 排序
class Solution1 {
public:
    int duplicate(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        for(int i = 1; i < numbers.size(); i++){ // 数组大小为0的时候 就直接返回了
            if(numbers[i - 1] == numbers[i]) return numbers[i];
        }
        return -1;
    }
};

// 替换
class Solution2 {
public:
    int duplicate(vector<int>& numbers) {
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] >= numbers.size() || numbers[i] < 0)return -1;
            while (numbers[i] != i){
                if(numbers[i] == numbers[numbers[i]]) return numbers[i];
                int temp;
                temp = numbers[i]; 
                numbers[i] = numbers[numbers[i]]; 
                numbers[temp] = temp;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> temp{6,3,2,0,2,5,0};
    Solution2 s;
    cout << s.duplicate(temp) << endl;
    return 0;
}
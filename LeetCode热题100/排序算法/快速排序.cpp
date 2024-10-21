#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int Partition(vector<int>& vec, int left, int right){
        int index = vec[left];
        while(left < right){
            while(left < right && vec[right] >= index) right--;
            vec[left] = vec[right];
            while(left < right && vec[left] <= index) left++;
            vec[right] = vec[left];
        }
        vec[left] = index;
        return left;
    }

    void QuickSort(vector<int>& vec, int left, int right){
        if(left < right){
            int index = Partition(vec, left, right);
            QuickSort(vec, left, index - 1);
            QuickSort(vec, index + 1, right);
        }
    }
};

int main()
{
    vector<int> vec{3,8,5,9,1,7,8,4,0,2};
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl << "------------------------------" << endl;
    Solution s;
    s.QuickSort(vec, 0, vec.size() - 1);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return 0;
}
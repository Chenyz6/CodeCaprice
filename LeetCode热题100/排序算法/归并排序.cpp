#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void Merge(vector<int>& vec, vector<int>& temp, int left, int mid, int right){
        int i = left, j = mid + 1, k = left;
        while(i != mid + 1 && j != right + 1){
            if(vec[i] <= vec[j]){
                temp[k++] = vec[i++];
            }else{
                temp[k++] = vec[j++];
            }
        }
        while(i != mid + 1){
            temp[k++] = vec[i++];
        }
        while (j != right + 1)
        {
            temp[k++] = vec[j++];
        }
        for(int i = 0; i < vec.size(); i++){
            vec[i] = temp[i];
        }
    }

    void MergeSort(vector<int>& vec, vector<int>& temp, int left, int right){
        int mid = 0;
        if(left < right){
            mid = left + ((right - left) >> 1);
            MergeSort(vec, temp, left, mid);
            MergeSort(vec, temp, mid + 1, right);
            Merge(vec, temp, left, mid, right);
        }
    }
};

int main()
{
    vector<int> vec{3,8,5,9,1,7,8,4,0,2};
    vector<int> temp = vec;
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl << "------------------------------" << endl;
    Solution s;
    s.MergeSort(vec, temp, 0, vec.size() - 1);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return 0;
}
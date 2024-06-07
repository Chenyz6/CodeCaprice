#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        int num = 0; int size = array.size();
        for(int i = 0; i < array.size(); i++){
            if(array[i] % 2 == 0) num++;
        }
        array.resize(size + num);
        int ouend = size + num - 1;
        int jiend = size - 1;
        for(int i = size - 1; i >= 0; i--){
            if(array[i] % 2 == 0) {
                array[ouend--] = array[i];
            }else{
                array[jiend--] = array[i];
            }
        }
        vector<int> result(array.begin() + num, array.end());
        return result;
    }
};

// 基本解法不考虑相对位置
class Solution1 {
public:
    vector<int> reOrderArray(vector<int>& array) {
        if(array.size() == 0) return {};
        int left = 0, right = array.size() - 1;
        while (left < right){
            while(array[left] % 2 == 1){
                left++;
            }
            while(array[right] % 2 == 0){
                right--;
            }
            swap(array[left], array[right]);
            left++; right--;
        }
        return array;
    }
};

int main()
{
    return 0;
}
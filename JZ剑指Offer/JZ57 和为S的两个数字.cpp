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
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.empty() || array.size() == 1) return vector<int> {};
        int left = 0, right = array.size() - 1, my_sum = 0;
        vector<int> result(2, 0);
        while(left < right){
            my_sum = array[left] + array[right];
            if(my_sum == sum){
                result[0] = array[left]; result[1] = array[right];
                return result;
            }else if (my_sum < sum) {
                left++;
            }else{
                right--;
            }
        }
        return vector<int> {};
    }   
};

int main()
{
    return 0;
}
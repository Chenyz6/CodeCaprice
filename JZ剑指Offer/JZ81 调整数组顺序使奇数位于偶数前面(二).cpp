#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
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
    vector<int> reOrderArrayTwo(vector<int>& array) {
        if(array.size() == 0) return {};
        // write code here
        int left = 0, right = array.size() - 1;
        while(left < right){
            while(left < right && array[left] % 2 == 1){  
                left++;
            }                
            while(left < right && array[right] % 2 == 0){ 
                right--;
            }
            swap(array[left++], array[right--]);
        }
        return array;
    }
};

int main()
{
    return 0;
}
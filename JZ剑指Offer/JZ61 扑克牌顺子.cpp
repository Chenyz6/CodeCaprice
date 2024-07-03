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
    bool IsContinuous(vector<int>& numbers) {
        if(numbers.size() != 5) return false;
        sort(numbers.begin(), numbers.end());
        int zeroNum = 0; 
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == 0) {
                zeroNum++;
            }else{
                break;
            }
        }
        if(zeroNum == 4) return true;   // 00155
        int num = 0;
        for(int i = zeroNum + 1; i < numbers.size(); i++){
            int temp = numbers[i] - numbers[i - 1];
            if(temp == 0) return false;
            num += (temp - 1);
        }
        if(num <= zeroNum) return true;
        else return false;
    }
};

int main()
{
    return 0;
}
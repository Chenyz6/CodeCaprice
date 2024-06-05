#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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

// 优化解法
class Solution1 {
public:
    double Power(double base, unsigned int exponent) {
        if(exponent == 0) return 1;
        if(exponent == 1) return base;

        int result = 1.0;
        result = Power(base, exponent >> 1);
        result *= result;
        if(exponent & 1) result *= base;
        return result;
    }
};

class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0) return 0;
        double result = 1.0;
        for(int i = 1; i <= abs(exponent); i++){
            result *= base;
        }
        if(exponent < 0){
            result = 1.0 / result;
        }
        return result;
    }
};

int main()
{
    Solution1 s;
    cout << s.Power(2,5) << endl;
    cout << s.Power(2,4) << endl;
    return 0;
}
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
    int Add(int num1, int num2) {
        // add表示进位值
        int add = num2;         
        // sum表示总和       
        int sum = num1;                
        // 当不再有进位的时候终止循环
        while(add != 0) {              
            // 将每轮的无进位和与进位值做异或求和
            int temp = sum ^ add;      
            // 进位值是用与运算产生的
            add = (sum & add) << 1;    
            // 更新sum为新的和JZ66 构建乘积数组
            sum = temp;                
        }
        return sum;
    }
};

// 101
// 111

// 0010
// 1010

// 1000
// 0100

// 1110
// 0000



int main()
{
    return 0;
}
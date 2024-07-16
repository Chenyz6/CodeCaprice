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
    int GetUglyNumber_Solution(int index) {
        //1 2 3 4 5 6 8
        if(index <= 6)
            return index;   // 加快程序输出
 
        // 三个变量 后面有大作用！
        int i2 = 0,i3 = 0,i5 = 0;
        int* res = new int[index];
        res[0] = 1;  // 第一个丑数为 1
 
        for(int i = 1; i < index; i++){
            // 得到下一个丑数，三者中最小的
            res[i] = min(res[i2]*2,min(res[i3]*3,res[i5]*5));
            /*第一次是 2、3、5比较，得到最小的是2*/
            /*第二次是 4、3、5比较，为什么是4了呢？因为上次2已经乘了一次了，所以接下去可以放的丑数在4、3、5之间*/
            // 所以开头的三个指针就是来标记2 3 5 乘的次数的
            if(res[i] == res[i2]*2)
                i2++;
            if(res[i] == res[i3]*3)
                i3++;
            if(res[i] == res[i5]*5)
                i5++;
        }
        return res[index-1];
    }
};

// 
class Solution1 {
public:
    int GetUglyNumber_Solution(int index) {
        //1 2 3 4 5 6 8
        if(index <= 6)
            return index;   // 加快程序输出
 
        // 三个变量 后面有大作用！
        int i2 = 1,i3 = 1,i5 = 1;
        int* res = new int[index + 1];
        res[1] = 1;  // 第一个丑数为 1
 
        for(int i = 2; i <= index; i++){
            // 得到下一个丑数，三者中最小的
            res[i] = min(res[i2]*2,min(res[i3]*3,res[i5]*5));
            /*第一次是 2、3、5比较，得到最小的是2*/
            /*第二次是 4、3、5比较，为什么是4了呢？因为上次2已经乘了一次了，所以接下去可以放的丑数在4、3、5之间*/
            // 所以开头的三个指针就是来标记2 3 5 乘的次数的
            if(res[i] == res[i2]*2)
                i2++;
            if(res[i] == res[i3]*3)
                i3++;
            if(res[i] == res[i5]*5)
                i5++;
        }
        return res[index];
    }
};

int main()
{
    return 0;
}
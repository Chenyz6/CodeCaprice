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

// 无溢出方法
class Solution {
public:
    void recursive(vector<int>& vec,char* arrays, int n, int index){
        if(n - 1 == index) {
            vec.push_back(0);
            return;
        }
        for(int i = 0; i < 10; i++){
            arrays[index + 1] = '0' + i;
            recursive(vec, arrays, n, index + 1);
        }
    }

    vector<int> printNumbers(int n) {
        vector<int> result;
        char * arrays = new char[n + 1];
        arrays[n] = '\0';
        for(int i = 0; i < 10; i++){
            arrays[0] = '0' + i;
            recursive(result, arrays, n, 0);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        for(int i = 1; i <= pow(10, n) - 1; i++){
            result.push_back(i);
        }
        return result;
    }
};


int main()
{
    return 0;
}
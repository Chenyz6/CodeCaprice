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

// 优化解法
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        if(numbers.size() == 0) return -1;
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); i++){
            if(times == 0){
                result = numbers[i];
                times = 1;
            }else if(numbers[i] == result){
                times++;
            }else{
                times--;
            }
        }
        return result;
    }
};

class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        if(numbers.size() == 0) return -1;
        vector<int> num(10000, 0);
        for(int i = 0; i < numbers.size(); i++){
            num[numbers[i]]++;
            if(num[numbers[i]] > numbers.size() / 2) return numbers[i];
        }
        return -1;
    }
};

int main()
{
    return 0;
}
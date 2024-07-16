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
    bool VerifySquenceOfBST(vector<int>& sequence, int begin, int end){
        if(begin >= end) return true;
        int index = 0;
        while(index < end && sequence[index] < sequence[end]){
            index++;
        }
        for(int i = index; i < end; i++){
            if(sequence[i] <= sequence[end]) return false;
        }
        return VerifySquenceOfBST(sequence, begin, index - 1)    // 注意传递范围是begin开始而不是0
                && VerifySquenceOfBST(sequence, index, end - 1);        
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() <= 0) return false;
        return VerifySquenceOfBST(sequence, 0, sequence.size() - 1);
    }
};

int main()
{
    return 0;
}
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

#include <algorithm>
class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        for(int i = 0; i < str.size();){
            while(i < str.size() && str[i] == ' '){
                i++;
            }
            int begin = i;
            while(i < str.size() && str[i] != ' '){
                i++;
            }
            reverse(str.begin() + begin, str.begin() + i);
            i++;
        }
        return str;
    }
};

int main()
{
    return 0;
}
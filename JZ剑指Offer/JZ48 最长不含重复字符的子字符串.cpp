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

#include <unordered_map>
#include <utility>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 0) return 0;
        unordered_map<char, int> map;
        int left = 0, right = 0;
        int result = 0;
        for(right = 0; right < s.size(); right++){
            map[s[right]]++;
            while(map[s[right]] > 1){
                map[s[left++]]--;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    return 0;
}
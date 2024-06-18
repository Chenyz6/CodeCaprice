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

// 时间复杂度nlogk
#include <functional>
#include <set>
class Solution {
public:
    multiset<int, greater<int>> intSet;
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        if(k == 0 || input.size() == 0) return {};
        for(int i = 0; i < input.size(); i++){
            if(intSet.size() != k){
                intSet.insert(input[i]);
            }else{
                if(input[i] < *intSet.begin()){
                    intSet.erase(intSet.begin());
                    intSet.insert(input[i]);
                }
            }
        }
        return vector<int>(intSet.begin(), intSet.end());
    }
};

// partition方式
class Solution {
public:
    int Partition(vector<int>& input, int start, int end){
        while(start < end){
            int index = input[start];
            while(start < end && index < input[end]) end--;
            if(start < end) swap(input[start++], input[end]);
            while(start < end && input[start] < index) start++;
            if(start < end) swap(input[start], input[end--]);
        }
        return start;
    }
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        if(input.size() == 0) return {};
        if(k == 0) return {};
        int start = 0, end = input.size() - 1;
        int ret = Partition(input, start, end);
        while(ret != k - 1){
            if(ret < k - 1){
                start = ret + 1;
                ret = Partition(input, start, end);
            }else{
                end = ret - 1;
                ret = Partition(input, start, end);
            }
        }
        return vector<int> (input.begin(), input.begin() + k);
    }
};

int main()
{
    return 0;
}
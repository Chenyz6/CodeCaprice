#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
// #include <map>
#include <unordered_map>
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

class Solution
{
private:
    unordered_map<char, int> un_map;
    vector<char> path;
public:
  //Insert one char from stringstream
    void Insert(char ch) {
         path.push_back(ch);
         un_map[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for(int i = 0; i < path.size(); i++){
            if(un_map[path[i]] == 1){
                return path[i];
            }
        }
        return '#';
    }

};


int main()
{
    return 0;
}
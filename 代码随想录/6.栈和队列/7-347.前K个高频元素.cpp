// https://leetcode.cn/problems/top-k-frequent-elements/description/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        class mycomparison {
        public:
            bool operator () (const pair<int, int> & pair1, const pair<int, int> & pair2){
                return pair1.second > pair2.second;
            } 
        };
        priority_queue <pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        unordered_map <int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }
        vector<int> result(k);
        for(int i = k - 1; i >= 0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main()
{
    return 0;
}
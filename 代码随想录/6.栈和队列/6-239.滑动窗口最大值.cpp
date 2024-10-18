// https://leetcode.cn/problems/sliding-window-maximum/description/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class MyDeque { //单调队列（从大到小）
public:
deque <int> deq;
    void pop(int value){
        if(!deq.empty() && value == deq.front()){
            deq.pop_front();
        }
    }
    void push(int value){
        while(!deq.empty() && value > deq.back()){
            deq.pop_back();
        }
        deq.push_back(value);
    }
    int top(){
        return deq.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyDeque mydeq;
        vector<int> vec;
        for(int i = 0; i < k; i++){
            mydeq.push(nums[i]);
        }
        vec.push_back(mydeq.top());
        for(int i = k; i < nums.size(); i++){
            mydeq.push(nums[i]);
            mydeq.pop(nums[i - k]);
            vec.push_back(mydeq.top());
        }
        return vec;
    }
};

int main()
{
    return 0;
}
// https://leetcode.cn/problems/implement-stack-using-queues/description/
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        while(que1.size() != 1){
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        return result;
    }
    
    int top() {
        while(que1.size() != 1){
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que2.push(que1.front());
        que1.pop();
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        return result;
    }
    
    bool empty() {
        return que1.empty() && que2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    return 0;
}
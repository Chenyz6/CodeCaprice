#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(222);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <memory>
using namespace std;

void Test()
{
    shared_ptr<int> ptr(new int[10],[](int * p) {delete []p; });     
    cout << "ptr---" << ptr.use_count() << endl;   
}

int main()
{
    Test();
    return 0;
}
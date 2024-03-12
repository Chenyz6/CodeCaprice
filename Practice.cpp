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
class Test
{
public:
    Test() 
    {
        cout << "construct Test..." << endl;
    }
    Test(int x) 
    {
        cout << "construct Test, x = " << x << endl;
    }
    Test(string str) 
    {
        cout << "construct Test, str = " << str << endl;
    }
    ~Test()
    {
        cout << "destruct Test ..." << endl;
    }
};

int main()
{
    shared_ptr<int> ptr(new int[10]);
    cout << "ptr---" << ptr.use_count() << endl;
    int * pt = ptr.get();
    pt[0] = 1000;
    cout << "ptr---" << ptr.use_count() << endl;

    return 0;
}
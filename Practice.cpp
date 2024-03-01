#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> uset;
    uset.insert(20);
    cout << uset.size() << endl;
    uset.insert(20);
    cout << uset.size() << endl;
    uset.insert(30);
    cout << uset.size() << endl;
    return 0;
}
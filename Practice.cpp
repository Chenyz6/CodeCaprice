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
    vector<int> v {1,2,3,4,5,6};

    vector<int> vv (v.begin(), v.begin() + 3); 

    for(int i = 0 ; i < vv.size(); i++){
        cout << vv[i] << " ";
    }
}

int main()
{
    Test();
    return 0;
}
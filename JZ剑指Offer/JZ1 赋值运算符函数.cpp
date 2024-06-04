#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
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

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str){}

private:
    char* m_pData;
};

CMyString& CMyString::operator = (const CMyString& str)
{
    if (&str == this){
        return *this;
    }

    char* temp = new char[strlen(str.m_pData) + 1];
    // memmove(temp, str.m_pData, strlen(str.m_pData) + 1);
    strcpy(temp, str.m_pData);
    delete[] m_pData;
    m_pData = nullptr;
    m_pData = temp;

    return *this;
}

int main()
{
    return 0;
}
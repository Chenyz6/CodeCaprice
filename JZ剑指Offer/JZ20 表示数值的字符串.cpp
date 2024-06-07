#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
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

// 遍历方式
class Solution1 {
public:
    //遍历字符串的下标
    int index = 0;
    //有符号判断
    bool integer(string& s){
        if(index < s.length() && (s[index] == '-' || s[index] == '+'))
            index++;
        return unsigned_integer(s);
    }
    //无符号数判断
    bool unsigned_integer(string& s){
        int temp = index;
        while(index < s.length() && (s[index] >= '0' && s[index] <= '9'))
            index++;
        return index > temp; // 直接排除掉了连续多个符号和其他的可能
    }
    bool isNumeric(string str) {
        //先判断空串
        if(str.length() == 0)
            return false;
        //去除前面的空格
        while(index < str.length() && str[index] == ' ')
            index++;
        int n = str.length() - 1;
        //去除字符串后面的空格
        while(n >= 0 && str[n] == ' ')
            n--;
        //限制的长度比下标1
        n++;
        //全是空格情况
        if(n < index)
            return false;
        //判断前面的字符是否是有符号的整数
        bool flag = integer(str);
        //如果有小数点
        if(index < n && str[index] == '.'){
            index++;
            //小数点前后有无数字可选
            flag = unsigned_integer(str) || flag; 
        }
        //如果有e
        if(index < n && (str[index] == 'e' || str[index] == 'E')){
            index++;
            //e后面必须全是整数
            flag = flag && integer(str);
        }
        //是否字符串遍历结束
        return flag && (index == n);
    }
};


// 正则表达式方式
#include<regex>
class Solution {
public:
    bool isNumeric(string str) {
        //正则表达式匹配
        string pattern = "(\\s)*[+-]?((\\d+(\\.(\\d+)?)?)|(\\.\\d+))([Ee][+-]?\\d+)?(\\s)*";
        regex re(pattern);
        //根据匹配值返回
        return regex_match(str, re);
    }
};



int main()
{
    return 0;
}
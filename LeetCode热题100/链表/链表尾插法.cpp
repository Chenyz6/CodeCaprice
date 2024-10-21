#include <iostream>
using namespace std;

struct Listnode {
    int val;
    Listnode* next;
};


int main() {
    int num = 0;
    cin >> num;
    if (num <= 0) return -1;
    Listnode* head = nullptr; Listnode* cur = nullptr;
    for (int i = 0; i < num; i++) {
        Listnode* temp = new Listnode;
        if (head == nullptr) {
            cin >> temp->val;
            cur = head = temp;
        }
        else {
            cin >> temp->val;
            cur->next = temp;
            cur = temp;
        }
    }
    cur->next = nullptr;

    Listnode* cur_out = head;
    while (cur_out != nullptr) {
        cout << cur_out->val << " ";
        cur_out = cur_out->next;
    }

    return 0;
}
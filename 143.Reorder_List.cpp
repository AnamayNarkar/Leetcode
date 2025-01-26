#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    void reorderList(ListNode *head) {

        vector<ListNode *> vec;
        int length = 0;
        while (head != nullptr) {
            vec.push_back(head);
            head = head->next;
            ++length;
        }

        int left = 0, right = length - 1;

        while (left < right) {
            vec[left++]->next = vec[right];

            if (left == right)
                break;

            vec[right--]->next = vec[left];
        }

        vec[left]->next = NULL;
    }
};
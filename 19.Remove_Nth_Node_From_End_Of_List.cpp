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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode *> vec;
        ListNode *tempHead = head;

        int length = 0;
        while (head != nullptr) {
            vec.push_back(head);
            head = head->next;
            length++;
        }

        if (n == length) {
            return tempHead->next;
        }

        ListNode *before = vec[length - n - 1];
        ListNode *after = (length - n < length - 1) ? vec[length - n]->next : nullptr;

        before->next = after;
        return tempHead;
    }
};
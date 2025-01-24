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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

        ListNode *newListHead = new ListNode();

        ListNode *currItr = newListHead;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val < list2->val) {
                currItr->next = list1;
                list1 = list1->next;
            } else {
                currItr->next = list2;
                list2 = list2->next;
            }

            currItr = currItr->next;
        }

        if (list1 != nullptr) {
            currItr->next = list1;
        } else {
            currItr->next = list2;
        }

        return newListHead->next;
    }
};
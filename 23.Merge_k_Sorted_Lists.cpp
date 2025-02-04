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
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        bool allNull = false;
        ListNode *head = new ListNode(0);
        ListNode *returnable = head;
        ListNode *nodeToInsert;
        int min, minIndex;

        while (allNull != true) {
            min = INT_MAX;
            minIndex = 0;
            allNull = true;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]) {
                    allNull = false;
                }
                if (lists[i] != nullptr && lists[i]->val < min) {
                    min = lists[i]->val;
                    minIndex = i;
                    nodeToInsert = lists[i];
                }
            }
            if (allNull) {
                break;
            }
            head->next = nodeToInsert;
            lists[minIndex] = lists[minIndex]->next;
            head = head->next;
        }
        return returnable->next;
    }
};

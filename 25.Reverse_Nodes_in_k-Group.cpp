#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
  void reverse(ListNode *head, ListNode *whereToStop, ListNode *prevGrpKaLast,
               ListNode **refToPointerOfThisGrpHead,
               ListNode **refToPointerOfThisGrpTail) {
    ListNode *prev = prevGrpKaLast;
    ListNode *curr = head;
    ListNode *next;
    ListNode *headStore = head;
    while (curr != whereToStop) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    *refToPointerOfThisGrpHead = prev;
    *refToPointerOfThisGrpTail = headStore;
  }

  ListNode *goKForward(ListNode *head, int k) {
    while (k != 1 && head != nullptr) {
      head = head->next;
      --k;
    }
    return head;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {

    bool edgeCaseFirstIG = true;
    ListNode *finalAns;

    ListNode *headStore = head;
    ListNode *prevGrpKaLast = nullptr;
    while (true) {
      ListNode *kth = this->goKForward(head, k);
      if (kth == nullptr) {
        break;
      }
      ListNode *nextGrpStart = kth->next;

      ListNode *headOfThisGrp;
      ListNode *TailOfThisGrp;
      this->reverse(head, nextGrpStart, prevGrpKaLast, &headOfThisGrp,
                    &TailOfThisGrp);
      // head and tail we get now are the ones for the revrsed part

      TailOfThisGrp->next = kth;
      if (prevGrpKaLast) {
        prevGrpKaLast->next = headOfThisGrp;
      }

      TailOfThisGrp->next = nextGrpStart; // this is for when the number of
                                          // elements arent divisible by k
      // because the line 59 wont happen if the func is going to break after
      // goingKForward returns nullptr
      prevGrpKaLast = TailOfThisGrp;
      head = nextGrpStart;

      if (edgeCaseFirstIG) {
        edgeCaseFirstIG = false;
        finalAns = headOfThisGrp;
      }
    }

    return finalAns;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  int k = 4;
  Solution s;
  head = s.reverseKGroup(head, k);
  int printCount = 7;
  while (printCount--) {
    if (head) {
      cout << head->val << " ";
      head = head->next;
    } else
      cout << " null ";
  }
}

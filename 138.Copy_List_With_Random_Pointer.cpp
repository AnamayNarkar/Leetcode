#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {

        if (head == nullptr) {
            return nullptr;
        }

        Node *headItr = head;
        unordered_map<Node *, Node *> mappy;

        Node *headToReturn;
        int i = 0;

        while (headItr != nullptr) {
            Node *newNode = new Node(headItr->val);
            mappy.insert({headItr, newNode});
            if (i == 0) {
                headToReturn = newNode;
            }
            i++;
            headItr = headItr->next;
        }

        headItr = head;

        while (headItr != nullptr) {
            mappy[headItr]->next = mappy[headItr->next];
            mappy[headItr]->random = mappy[headItr->random];
            headItr = headItr->next;
        }

        return headToReturn;
    }
};

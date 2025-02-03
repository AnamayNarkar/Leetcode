#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *prev;
    Node *next;
    int key;

    Node(int key, int value) {
        this->key = key;
        this->data = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
  private:
    int capacity;
    int currentNumberOfElements;
    Node *lru;
    Node *mru;
    unordered_map<int, Node *> myMap;

  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->currentNumberOfElements = 0;
        this->lru = nullptr;
        this->mru = nullptr;
    }

    int get(int key) {
        if (myMap.find(key) != myMap.end() && currentNumberOfElements != 0) {
            if (myMap[key] == mru) {
                return mru->data;
            } else {
                Node *temp = myMap[key];
                if (temp->prev)
                    temp->prev->next = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
                if (temp == lru)
                    lru = lru->next;
                lru->prev = nullptr;

                mru->next = temp;
                temp->prev = mru;
                mru = temp;
                mru->next = nullptr;

                return mru->data;
            }
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (myMap.find(key) != myMap.end()) {
            myMap[key]->data = value;
            get(key);
            return;
        } else {
            if (capacity == 1 && currentNumberOfElements == 1) {
                Node *temp = lru;
                lru = mru = new Node(key, value);
                myMap.erase(temp->key);
                myMap.insert({key, lru});
                delete temp;
                return;
            } else if (currentNumberOfElements == 0) {
                lru = mru = new Node(key, value);
                currentNumberOfElements++;
                myMap.insert({key, mru});
                return;
            } else if (currentNumberOfElements == capacity) {
                Node *temp = lru;
                lru = lru->next;
                if (lru)
                    lru->prev = nullptr;
                myMap.erase(temp->key);
                delete temp;

                Node *newNode = new Node(key, value);
                mru->next = newNode;
                newNode->prev = mru;
                mru = newNode;
                myMap.insert({key, newNode});
                return;
            } else {
                Node *newNode = new Node(key, value);
                mru->next = newNode;
                newNode->prev = mru;
                mru = newNode;
                currentNumberOfElements++;
                myMap.insert({key, newNode});
                return;
            }
        }
    }
};

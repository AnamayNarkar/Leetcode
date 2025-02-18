#include <bits/stdc++.h>
using namespace std;

class NumberContainers {

    unordered_map<int, int> indexAndNumber;
    unordered_map<int, set<int>> numberAndMinIndex;

  public:
    NumberContainers() {}

    void change(int index, int number) {
        if (indexAndNumber[index] != 0) {
            numberAndMinIndex[indexAndNumber[index]].erase(index);
        }
        indexAndNumber[index] = number;
        numberAndMinIndex[number].insert(index);
    }

    int find(int number) {
        if (numberAndMinIndex[number].empty()) {
            return -1;
        } else {
            return *numberAndMinIndex[number].begin();
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
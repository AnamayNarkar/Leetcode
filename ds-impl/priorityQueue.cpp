#include <iostream>
#include <optional>
#include <vector>
using namespace std;

class MyPriorityQueue {

private:
  vector<int> pq;
  int nextElementIndex;

public:
  MyPriorityQueue() { this->nextElementIndex = 0; }

  bool isEmpty() { return nextElementIndex == 0; }

  void insert(int valueToInsert) {
    if (this->pq.size() == nextElementIndex) {
      this->pq.push_back(valueToInsert); // satisfies the ACBT properties but
                                         // dosent follow the heap properties
    } else {
      this->pq[nextElementIndex] = valueToInsert;
    }

    this->nextElementIndex++;
    int current_index = this->nextElementIndex - 1;
    int parent_index = (current_index - 1) / 2;
    while (current_index != 0 &&
           this->pq.at(parent_index) > this->pq.at(current_index)) {
      swap(this->pq.at(current_index), this->pq.at(parent_index));

      current_index = parent_index;
      parent_index = (current_index - 1) / 2;
    }
  }

  optional<int> peek() {
    if (isEmpty()) {
      return nullopt;
    }
    return this->pq.at(0);
  }

  void pop() {
    if (isEmpty()) {
      return;
    }

    // delete last Element
    swap(this->pq.at(0), this->pq.at(pq.size() - 1));
    this->nextElementIndex--;

    // down heapify
    int current_index = 0;

    while (true) {
      int left_child_index = 2 * current_index + 1;
      int right_child_index = 2 * current_index + 2;

      int smallest = current_index;

      if (left_child_index < nextElementIndex &&
          this->pq[left_child_index] < this->pq[smallest]) {
        smallest = left_child_index;
      }

      if (right_child_index < nextElementIndex &&
          this->pq[right_child_index] < this->pq[smallest]) {
        smallest = right_child_index;
      }

      if (smallest == current_index) {
        break;
      }

      swap(this->pq[current_index], this->pq[smallest]);
      current_index = smallest;
    }

    this->pq.pop_back();
  }

  void printPriorityQueue() {
    for (int i = 0; i < this->nextElementIndex; ++i) {
      cout << this->pq.at(i) << " ";
    }
    cout << endl;
  }
};

int main() { // test cases
  MyPriorityQueue pq;

  // Edge case 1: Pop and peek from empty queue
  cout << "Peek on empty: "
       << (pq.peek().has_value() ? to_string(pq.peek().value()) : "nullopt")
       << endl;
  pq.pop(); // should not crash

  // Insert elements
  pq.insert(10);
  pq.insert(5);
  pq.insert(20);
  pq.insert(5); // duplicate
  pq.insert(1);
  pq.insert(15);
  pq.insert(0); // smallest element
  pq.insert(30);
  pq.insert(2);

  cout << "Heap after insertions: ";
  pq.printPriorityQueue(); // internal heap structure (not sorted)

  // Check peek
  cout << "Peek: " << pq.peek().value() << endl;

  // Pop all elements to get them in sorted order
  cout << "Elements popped in order: ";
  while (!pq.isEmpty()) {
    cout << pq.peek().value() << " ";
    pq.pop();
  }
  cout << endl;

  // Final edge case: pop on empty again
  pq.pop(); // should not crash
}

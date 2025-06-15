#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void heapSort(vector<int> &arr) {
  int tail = arr.size() - 1;

  // convert the array into a heap
  // start with the second element ( index 1 ) because we assume that the first
  // one is in the rigth place and even if it isnt it will get these eventually
  // as we insert and up-heapify over and over

  for (int i = 1; i <= tail; ++i) {
    int currentIndex = i;
    int parentIndex = (currentIndex - 1) / 2;
    while (currentIndex != 0 && arr[parentIndex] > arr[currentIndex]) {
      swap(arr[parentIndex], arr[currentIndex]);
      currentIndex = parentIndex;
      parentIndex = (currentIndex - 1) / 2;
    }
  }

  // now once we have our heap we now need to pop one by one
  // but inseat of doinf pop_back() at the end , we'll just
  // decrement the tail
  // so that once we are done with removing well have a descending soreted array

  while (tail != 0) {
    swap(arr[tail], arr[0]);
    tail--;

    // down heapify

    int currentIndex = 0;
    while (true) {
      int childIndex_1 = 1 + currentIndex * 2;
      int childIndex_2 = 2 + currentIndex * 2;
      int smallest = currentIndex;

      if (childIndex_1 <= tail && arr[childIndex_1] < arr[smallest]) {
        smallest = childIndex_1;
      }

      if (childIndex_2 <= tail && arr[childIndex_2] < arr[smallest]) {
        smallest = childIndex_2;
      }

      if (smallest == currentIndex) {
        break;
      }

      swap(arr[currentIndex], arr[smallest]);
      currentIndex = smallest;
    }
  }

  reverse(arr.begin(), arr.end());
}

int main() {

  vector<int> vec = {5, 4, 3, 2, 1};

  heapSort(vec);

  for (int num : vec) {
    cout << num << " ";
  }

  cout << endl;
}

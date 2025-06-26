#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void inplaceHeapSort(vector<int> &vec) {

  // make the array into a CBT
  // by adding an element of the array one by one
  // and up heapifying it to its correct place
  int end = vec.size() - 1;
  for (int i = 1; i <= end; ++i) {
    int newElementIndex = i;
    int newElementParentIndex = (newElementIndex - 1) / 2;

    while (newElementIndex != 0 &&
           vec[newElementParentIndex] > vec[newElementIndex]) {
      swap(vec[newElementIndex], vec[newElementParentIndex]);
      newElementIndex = newElementParentIndex;
      newElementParentIndex = (newElementIndex - 1) / 2;
    }
  }

  // its a CBT now but, not yet sorted
  // it will be sorted once we start popping
  // but we cant pop and store them in a separate arrat
  // because that will fuck ip the purpose
  // of inplaceHeapSort since well use extra space
  // so well pop (put that element at the emd)
  // and pretend that space dosent exist anymore
  // by decrementing the end pounter
  // so well have the min element at the end
  // and then reverse it to get the array sorted

  int tail = end;
  while (tail != 0) {
    swap(vec[0], vec[tail]);
    tail--;

    // down heapify

    int currentIndex = 0;
    while (true) {
      int firstChildIndex = (currentIndex * 2) + 1,
          secondChildIndex = (currentIndex * 2) + 2;

      int smallest = currentIndex;

      if (firstChildIndex <= tail && vec[firstChildIndex] < vec[smallest]) {
        smallest = firstChildIndex;
      }

      if (secondChildIndex <= tail && vec[secondChildIndex] < vec[smallest]) {
        smallest = secondChildIndex;
      }

      if (currentIndex == smallest) {
        break; // this means that elemnt which was
        // swapped to the first from the back
        // has reached its correct position
        // and theres no children
        // or theres no children smaller than him
      }
      swap(vec[smallest], vec[currentIndex]);
      currentIndex = smallest;
    }
  }

  reverse(vec.begin(), vec.end());
}

int main() {

  vector<int> vec = {5, 4, 3, 2, 1};

  inplaceHeapSort(vec);

  for (int num : vec) {
    cout << num << " ";
  }

  cout << endl;
}

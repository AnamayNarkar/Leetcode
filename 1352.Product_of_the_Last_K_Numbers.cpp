#include <bits/stdc++.h>
using namespace std;

//==================
// Constant add func

class ProductOfNumbers {
    vector<int> vec;

  public:
    ProductOfNumbers() {}

    void add(int num) { vec.push_back(num); }

    int getProduct(int k) {
        int prod = 1;
        for (int i = 0; i < k; i++) {
            prod *= vec[vec.size() - 1 - i];
        }
        return prod;
    }
};

//==================
// Constant get func
class ProductOfNumbers {
    vector<int> preCompute;

  public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            for (int i = 0; i < preCompute.size(); i++) {
                preCompute[i] = 0;
            }
        } else {
            for (int i = 0; i < preCompute.size(); i++) {
                preCompute[i] *= num;
            }
        }
        preCompute.push_back(num);
    }

    int getProduct(int k) { return preCompute[preCompute.size() - k]; }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int drunk = 0;
    int fullBottles = numBottles;
    while (numBottles >= numExchange) {
      drunk += fullBottles;
      fullBottles = 0;
      while (numBottles >= numExchange) {
        fullBottles++;
        numBottles -= numExchange;
        numBottles++;
        numExchange++;
      }
    }
    return drunk + fullBottles;
  }
};

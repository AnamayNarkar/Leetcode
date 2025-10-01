#include <bits/stdc++.h>
using namespace std;

// explanation
// drink the initial bottles since theyre all full
// calculate for the next itr how many you can exchange
// calculate for the next itr how many in total you got left
// if cant exchange moe break out of loop
// drink if any left (considering the loop got over before we could drink
// everything)

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int drunk = 0;
    int fullBottles = numBottles;

    while (numBottles >= numExchange) {
      drunk += fullBottles;
      fullBottles = numBottles / numExchange;
      numBottles = numBottles - (fullBottles * numExchange) + fullBottles;
    }

    return drunk + fullBottles;
  }
};

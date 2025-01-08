#include <bits/stdc++.h>
using namespace std;

class MinStack {

  public:
    stack<int> *nor;
    stack<int> *extra;

    MinStack() {
        this->nor = new stack<int>;
        this->extra = new stack<int>;
    }

    void push(int val) {
        this->nor->push(val);
        !this->extra->empty() ? this->extra->push(min(val, this->extra->top())) : this->extra->push(val);
    }

    void pop() {
        this->nor->pop();
        this->extra->pop();
    }

    int top() { return this->nor->top(); }

    int getMin() { return this->extra->top(); }
};

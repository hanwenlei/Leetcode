#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> Stack;

    MinStack() {
        
    }
    
    void push(int x) {
        Stack.push_back(x);
    }
    
    void pop() {
        vector<int>::iterator it = Stack.end();
        --it;
        Stack.erase(it);
    }
    
    int top() {
        vector<int>::iterator it = Stack.end();
        --it;
        return *it;
    }
    
    int getMin() {
        return *min_element(Stack.begin(), Stack.end());
    }
};

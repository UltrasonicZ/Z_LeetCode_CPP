#include <iostream>
#include <stack>
using std::stack;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stack1;
    stack<int> stack2;
    MinStack() {
//   	stack<int> stack1;
//    	stack<int> stack2;
    }
    
    void push(int x) {
        stack1.push(x);
        if (stack2.empty() || x < stack2.top())
            stack2.push(x);
        else 
            stack2.push(stack2.top());
    }
    
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
};

int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    std::cout << obj.getMin() << std::endl;
    obj.pop();
    int param_3 = obj.top();
    std::cout << param_3 << std::endl;
    int param_4 = obj.getMin();
    std::cout << param_4 << std::endl;
    return 0;
}

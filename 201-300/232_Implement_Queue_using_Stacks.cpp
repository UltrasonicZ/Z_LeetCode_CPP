#include <iostream>
#include <stack>
using std::stack;
class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    int front;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
	if (stack1.empty()) 
	    front = x;
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack2.empty())
	    while (!stack1.empty()) {
		int data = stack1.top();
		stack1.pop();
		stack2.push(data);
	    }
	int data = stack2.top();
	stack2.pop();
	return data;
    }
    
    /** Get the front element. */
    int peek() {
        if (!stack2.empty())
	    return stack2.top();
	return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue obj;
    obj.push(1);
    obj.push(2);
    int param_2 = obj.pop();
    int param_3 = obj.peek();
    bool param_4 = obj.empty();
    std::cout << param_2 << std::endl << param_3 << std::endl << param_4 << std::endl;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

class MaxStack {
private:
    stack<int> mainStack; // Main stack to store elements
    stack<int> maxStack;  // Stack to store maximum values
    
public:
    MaxStack() {
        // Constructor initializes empty stacks
    }
    
    // Push an element onto the stack
    void push(int x) {
        mainStack.push(x);
        // Update maxStack to maintain the current max
        if (maxStack.empty() || x >= maxStack.top()) {
            maxStack.push(x);
        }
    }
    
    // Remove the top element from the stack
    int pop() {
        if (mainStack.empty()) return -1; // Stack is empty
        int topElement = mainStack.top();
        mainStack.pop();
        // If the popped element is the current max, update maxStack
        if (!maxStack.empty() && topElement == maxStack.top()) {
            maxStack.pop();
        }
        return topElement;
    }
    
    // Get the top element of the stack
    int top() {
        if (mainStack.empty()) return -1; // Stack is empty
        return mainStack.top();
    }
    
    // Retrieve the maximum element in the stack
    int peekMax() {
        if (maxStack.empty()) return -1; // Stack is empty
        return maxStack.top();
    }
    
    // Remove the maximum element from the stack
    int popMax() {
        if (maxStack.empty()) return -1; // Stack is empty
        int maxVal = maxStack.top();
        stack<int> buffer;
        
        // Remove elements from mainStack until max is found
        while (mainStack.top() != maxVal) {
            buffer.push(mainStack.top());
            mainStack.pop();
        }
        
        // Remove the max element from both stacks
        mainStack.pop();
        maxStack.pop();
        
        // Restore elements from the buffer stack
        while (!buffer.empty()) {
            push(buffer.top());
            buffer.pop();
        }
        
        return maxVal;
    }
};

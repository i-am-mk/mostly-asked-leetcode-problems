// https://www.naukri.com/code360/problems/max-stack_985280
#include <stack>
using namespace std;
class MaxStack {
public:    	
	stack<int> mainStack;
	stack<int> maxStack;
	MaxStack() {
	}
	
    // Push value in stack.
	void specialPush(int value) {
		mainStack.push(value);
		if(maxStack.empty() || value>=maxStack.top())
			maxStack.push(value);
	}

    // Return pop value in stack.
	int specialPop() {
		if(mainStack.empty())
			return -1;
		int element = mainStack.top();
		mainStack.pop();
		if(!maxStack.empty() && element==maxStack.top())
			maxStack.pop();
		return element;
	}

    // Return top value in stack.
	int specialTop() {
		return mainStack.empty() ? -1 : mainStack.top();
	}

	// Return maximum value in stack.
	int specialMax() {
		return maxStack.empty() ? -1 : maxStack.top();
	}
};
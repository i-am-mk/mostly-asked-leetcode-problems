// https://leetcode.com/problems/min-stack/
class MinStack {
private:
    vector<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            pair<int, int> p = make_pair(val, val);
            st.push_back(p);
        }
        else
        {
            pair<int, int> p = make_pair(val, min(val, st.back().second));
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
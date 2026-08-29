class MinStack {
public:
    MinStack() {}
    
    void push(int val)
    {
        if (mStack.empty()) { mStack.push({val, val}); }
        else { mStack.push({val, std::min(mStack.top().second, val)}); }
    }
    
    void pop()
    {
        mStack.pop();
    }
    
    int top()
    {
        return mStack.top().first;
    }
    
    int getMin()
    {
        return mStack.top().second;
    }

private:
    std::stack<std::pair<int, int>> mStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
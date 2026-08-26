class MinStack {
private:
    vector<int> minStack;
    stack<int> allMins;
    int curMin;

public:
    MinStack() : minStack(), curMin(INT_MAX) {}
    
    void push(int val) {
        this->minStack.push_back(val);
        if(val <= this->curMin) {
            this->curMin = val;
            this->allMins.push(val);
        }
    }
    
    void pop() {
        if(this->minStack.back() == this->curMin) {
            this->allMins.pop();
        }
        this->minStack.pop_back();
        this->minStack.empty() ? this->curMin = INT_MAX : this->curMin = this->allMins.top();
    }
    
    int top() {
        return this->minStack.back();
    }
    
    int getMin() {
        if(this->minStack.size() == 1) {
            return this->minStack.back();
        }

        return this->curMin;
    }
};

class MinStack {
public:
    int mini=INT_MAX;
    stack<int>st;
    stack<int>minst;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minst.empty()||val<=minst.top()){
            minst.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        if(st.top()==minst.top()){
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
class MinStack {
public:
    MinStack() {
        
    }
    stack<int>s;
    stack<int>ms;
    void push(int val) {
        s.push(val);
        if(ms.empty()==true||ms.top()>=val){
            ms.push(val);
        }
    }
    void pop() {
        if(s.top()==ms.top()){
            ms.pop();
        }
        s.pop();
    }
    
    int top() {
       return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
class MinStack {
public:
    MinStack() {
        
    }
    stack<int>s;
    map<int,int>m;
    long long min=LONG_MAX;
    void push(int val) {
        s.push(val);
        if(min>val){
            min=val;
        }
        m[val]++;
    }
    
    void pop() {
        m[s.top()]--;
        if(m[s.top()]==0){
            m.erase(s.top());
        }
        if(s.top()==min){
            if(m.empty()==true){
                min=LONG_LONG_MAX;
            }
            else
                min=m.begin()->first;
        }
        s.pop();
    }
    
    int top() {
       return s.top();
    }
    
    int getMin() {
        return min;
    }
};
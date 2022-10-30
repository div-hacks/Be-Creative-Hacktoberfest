// Two Stacks
stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }

//O(1) amortized push or pop
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int temp = s2.top();
            s2.pop();
            return temp;
        }else{
            int temp = s2.top();
            s2.pop();
            return temp;
        }
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int temp = s2.top();
          
            return temp;
        }else{
            return s2.top();
        }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
    
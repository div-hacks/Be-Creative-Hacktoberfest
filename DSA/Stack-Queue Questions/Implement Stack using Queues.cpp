// T/C: O(n), S/C: O(n)
// 2 queues
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

//Single Queue
push(x){
    q.push(x);
    for(int i=1; i<=q.size()-1; i++){
        q.push(q.front());
        q.pop();
    }
}
pop(){
    q.pop();
}
top(){
    return q.front();
}
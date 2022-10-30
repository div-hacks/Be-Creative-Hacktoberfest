class Queue {
public:
    int q[10000];
    int n=10000;
    int sz, frnt, rear;
    Queue() {
        // Implement the Constructor
        frnt=0;
        rear=0;
        sz=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return sz==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(sz!=n){
            q[rear%n] = data;
            rear++;
            sz++;
        }
        
       
    }

    int dequeue() {
        // Implement the dequeue() function
        if(sz==0){
            return -1;
        }
        int ans = q[frnt%n];
        frnt++;
        sz--;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(sz==0){
            return -1;
        }
        return q[frnt%n];
    }
};
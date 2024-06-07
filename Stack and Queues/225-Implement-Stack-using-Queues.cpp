// We need to convert FIFO to LIFO

// M-1) Using two queue: T.C: O(N), S.C: O(2*N)
/*
class MyStack {
public:
    queue<int> q1;    // q1 will contain the final queue (in the form of stack)
    queue<int> q2;    // temporary queue

    MyStack() {

    }
    
    void push(int x) {
        q2.push(x);  // enter new element
        while(!q1.empty()){    // push all elements from q1 to q2 
           q2.push(q1.front());
           q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans; 
    }
    
    int top() {
        if(q1.empty())
            return -1;
        return q1.front(); 
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        return false;
    }
};
*/


// M-2) Using single queue: T.C: O(N), S.C: O(N)
// We need to convert FIFO to LIFO
class MyStack {
public:
    queue<int> q;    // q will contain the final queue (in the form of stack)

    MyStack() {

    }
    
    void push(int x) {
        if(q.empty()){
            q.push(x);   // enter new element
        }
        else{
            q.push(x);
            for(int i=1; i <= q.size()-1; i++){    // push all elements in front of x (except x) at the back of x
                q.push(q.front());
                q.pop();
            }
        }
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }
        int ans = q.front();
        q.pop();
        return ans; 
    }
    
    int top() {
        if(q.empty())
            return -1;
        return q.front(); 
    }
    
    bool empty() {
        if(q.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
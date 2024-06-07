// To satisfy FIFO property of a queue we need to keep two stacks. They serve to reverse arrival order of the elements and one of them store the queue elements in their final order.

// M-1) Using two Stacks where push operation is O(N)
// T.C: O(N), S.C: O(2N)
/*
class MyQueue {
public:
    stack<int> s1;    // stores the final stack (in the form of queue)
    stack<int> s2;    // temporary stack

    MyQueue() {
        
    }
    
    void push(int x) {    // we try to insert new element at bottom of stack s1, so that it behaves like queue finally when pop() is used
        if(s1.empty()){       // top of stack = front of queue
            s1.push(x);
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.push(x);   // or s1.push(x)
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            };
        }
    }
    
    int pop() {
        if(s1.empty()){
            return -1;
        }
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty())
            return true;
        return false;
    }
};
*/


// M-2) Using two Stacks where push operation is O(1)  i.e amortized O(1) time complexity
// T.C: push: O(1), pop and peek: O(N), empty: O(1);  S.C: O(2N)
class MyQueue {
public:
    stack<int> s1;    // stores the final stack (in the form of queue)
    stack<int> s2;    // temporary stack

    MyQueue() {
        
    }
    
    void push(int x) {     // insert new element at top of stack s1, so that top of stack s1  = rear of queue (to pop we need to use s2)
        s1.push(x);     // O(1)
    }
    
    int pop() {
        // if(s1.empty()){
        //     return -1;
        // }
        // while(!s1.empty()){    // bottom of stack s1 = front of queue
        //     s2.push(s1.top());
        //     s1.pop();
        // }
        
        // int ans = s2.top();    // pop front of queue = top of stack s2
        // s2.pop();

        // while(!s2.empty()){      // again store all elements from s2 to s1 in the same order
        //     s1.push(s2.top());
        //     s2.pop();
        // }

        // return ans;

        // Another approach: s1 acts as input stack and s2 acts as output stack
        if(s2.empty()){    
            while(!s1.empty()){
                s2.push(s1.top()); 
                s1.pop();
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        // if(s1.empty()){
        //     return -1;
        // }
        // while(!s1.empty()){    // bottom of stack s1 = front of queue
        //     s2.push(s1.top());
        //     s1.pop();
        // }
        
        // int ans = s2.top();    // pop front of queue = top of stack s2

        // while(!s2.empty()){      // again store all elements from s2 to s1 in the same order
        //     s1.push(s2.top());
        //     s2.pop();
        // }
        
        // return ans;

        // Another approach: s1 acts as input stack and s2 acts as output stack
        if(s2.empty()){   
            while(!s1.empty()){
                s2.push(s1.top()); 
                s1.pop();
            }
        }
        int ans = s2.top();
        return ans;
    }
    
    bool empty() {
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
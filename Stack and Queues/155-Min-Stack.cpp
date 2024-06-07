// We cannot solve this question using stack<int> st and a minNum variable; as we will not be able to perform pop() operation and find the min element. We don't know the previous min after popping. 
// Take eg: st = [4,3,5,0,1], then pop() multiple times.
// WARNING: Wrong Approach
/*
class MinStack {
public:
    stack<int> st;
    int minNum = INT_MAX;
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minNum = val; 
        }
        else{
            st.push(val);
            minNum = min(val, minNum);  
        }
    }
    
    void pop() {
        st.pop();
        minNum = min(st.top(), minNum);  
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minNum;
    }
};
*/


// M-1)
// T.C: O(N), S.C: O(2N) for storing pairs in stack.
// Take eg: st = [{4,4}, {3,3}, {5,3}, {0,0}, {1,0}] then pop() multiple times.
/*
Intuition:
Imagine a type of stack, that not only keeps track of the elements you push onto it but also remembers the smallest element so far.

Approach:
We will use a pair inside the stack data structure. Using pairs to store the value and minimum element till now.
The first element in the pair will store the value and the second element will store the minimum element till now.
*/
class MinStack {
public:
    stack<pair<int,int>> st;

    MinStack() {

    }
    
    void push(int val) {
        int minn;
        if (st.empty()) {
            minn = val;
            // st.push({val, val});
        } 
        else {
            minn = min(st.top().second, val);
            // st.push({val, min(st.top().second, val)});
        }
        
        st.push({val,minn});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};



// M-2) Similar as M-1 but using vector instead of stack.
/*
class MinStack {
public:
    vector< pair<int,int> > s;
	
    MinStack(){ 

    }
    
    void push(int val){
        if(s.empty())
            s.push_back({val,val});
        else
            s.push_back({val,min(s.back().second,val)});    
    }
    
    void pop(){ 
        s.pop_back(); 
    }
    
    int top(){ 
        return s.back().first; 
    }
    
    int getMin(){ 
        return s.back().second; 
    }
};
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
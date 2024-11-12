// Previous Smaller Element
// Monotonically increasing stack
// T.C: O(2*n), S.C: O(n) for stack, pse vector
// The while loop inside the for loop pops elements from the stack. However, each element in the array can be pushed and popped from the stack only once during the entire execution of the algorithm. Therefore, the total number of push and pop operations com
class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int> pse(n);  // Previous Smaller Element
        stack<int> st;
        
        for(int i=0; i<n; i++){  // O(n)
            while(!st.empty() && st.top() >= a[i]){
                st.pop();  // O(n) for each of the n elements 
            }
            
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            
            st.push(a[i]);
        }
        
        return pse;
    }
};


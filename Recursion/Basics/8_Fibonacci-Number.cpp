// M-1 (Recursion) --> Time: O(2^n)
// class Solution {
// public:
//     int fib(int n) {
//         if(n<=1)    
//             return n;
//         return fib(n-2) + fib(n-1);
//     }
// };

// M-2 (Iterative)  --> Time: O(n), Space: O(n)
/*
class Solution {
public:
    int fib(int n) {
        if(n<=1)    
            return n;

        vector<int> fib = {0,1};
        for(int i=2; i<=n; i++){
            fib.push_back(fib[i-1] + fib[i-2]);   // fib[i] = fib[i-1] + fib[i-2]
        }

        return fib[n];
    }
};
*/

class Solution {
public:
    int fib(int n) {
        if(n<=1)    
            return n;
        
        int last = 1, secondLast = 0;
        int current;
        for(int i=2; i<=n; i++){
            current = last + secondLast;
            secondLast = last;
            last = current; 
        }

        return current;
    }
};
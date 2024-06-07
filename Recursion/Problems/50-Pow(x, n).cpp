// M-1) Brute force --> T.C: O(n), S.C: O(1)
// WARNING: will give TLE for n = -2147483648 
/*
class Solution {
public:
    double myPow(double x, int n) {
        n = (long long)n;
        double ans = 1.0;
      
        if(n > 0){
            for(long long i = 1; i <= n; i++){
                ans *= x;
            }
        }
        else{
            x = 1 / x;
            long long absN = -n; // Convert n to a positive value using a long long variable
            for (long long i = 1; i <= absN; i++) {
                ans *= x;
            }
        }

        return ans;
    }
};
*/


// M-2) Binary exponentiation (Iterative approach - 1) --> T.C: O(log n), S.C: O(1)
// We can calculate x^n using O log2(N) multiplications.
/*
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // Store n as a long long to handle the case when n = INT_MIN
        
        double ans = 1.0;     
        
        if (N < 0) 
            N = -1 * N;
        
        while(N != 0){
            if(N % 2 == 0){
                x *= x;
                N /= 2;
            }
            else{
                ans *= x;
                N -= 1;
            }
        }

        if (n < 0)  // check for n, as N will become 0
            ans = 1.0 / ans;      
       
        return ans;
    }
};
*/

// M-3) Binary exponentiation (Iterative approach - 2) --> T.C: O(log n), S.C: O(1)
// Another way to write M-2 --> T.C: O(log n), S.C: O(1)
/*
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // Typecast int n to long long N

        double ans = 1.0;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        while (N > 0) {
            if (N % 2 == 0) {
                x *= x;
                N /= 2;
            } else {
                ans *= x;
                N--;
            }
        }

        return ans;
    }
};
*/

// M-4) Binary exponentiation (Recursive approach - 1) --> T.C: O(log n), S.C: O(1)
// We can calculate x^n using O log2(N) multiplications.
/*
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){     // Base Condition
            return 1; 
        }

        if(n < 0) {
            n = abs(n);
            x = 1/x;
        }

        if(n%2 == 0){
            return myPow(x*x, n/2);
        }
        else{
            return x*myPow(x, n-1);
        }
    }
};
*/

// M-5) Binary exponentiation (Recursive approach - 2) --> T.C: O(log n), S.C: O(1)
// We can calculate x^n using O log2(N) multiplications.
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;   // Base Condition

        if(n < 0) {
            n = abs(n);
            x = 1/x;
        }

        double ans = myPow(x, n/2);   // recursive call
        ans *= ans;
        if(n%2 == 1){
            ans *= x;
        }

        return ans;
    }
};



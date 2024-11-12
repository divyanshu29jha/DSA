// https://leetcode.com/problems/power-of-two/solutions/4748857/8-approaches-c-java-python-javascript-explained/

// T.C: O(logn)
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // Power of two must be positive
        while (n > 1) {
            if (n % 2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};
*/


// M-2) Left Shift
// T.C: O(logn)
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x = 1;
        while(x <= n){
            if(x == n) return true;
            if(x > INT_MAX /2) break;    // OR else TLE (since x doubles)
            x = x << 1;
        }

        return false;
    }
};
*/

// M-3) And Operator
// T.C: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n & (n-1)) == 0)  return true;
        return false;
    }
};

// M-4) Counting 1's
// T.C: O(logn)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int cnt = __builtin_popcount(n);
        return  (cnt==1) ? true:false;
    }
};
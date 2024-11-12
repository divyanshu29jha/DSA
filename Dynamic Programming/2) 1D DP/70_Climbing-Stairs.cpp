// M-1) Recursion + Backtracking --> Gives TLE
// T.C: O(2^n), generate all possible sequences of steps to reach n. At each step, the function has two choices: increment the step by 1 or by 2.
// S.C: (n), for recursion stack, in the worst case, the recursion depth will be n, which happens when the function always takes a step of 1.
/*
class Solution {
public:
    void helper(int step, int n, int& cnt){   // Pass cnt by reference, step by value
        if(step > n){
            return;
        }
        if(step == n){
            cnt++;
            return;
        }

        helper(step+1, n, cnt);
        helper(step+2, n, cnt);
    }

    int climbStairs(int n) {
        int step = 0, cnt = 0;
        helper(step, n, cnt);
        return cnt;
    }
};
*/

// Another way to write M-1
/*
class Solution {
public:
    int helper(int step, int n){   
        if(step > n)
            return 0;

        if(step == n)
            return 1;
        
        int ans=0;
        ans += helper(step+1, n);
        ans += helper(step+2, n);
        return ans;
    }

    int climbStairs(int n) {
        int step = 0;
        return helper(step, n);
    }
};

// Another way to write M-1
/*
class Solution {
public:
    void helper(int &step, int n, int &cnt) {      // Pass both step and cnt by reference
        if(step > n){
            return;
        }
        if(step == n){
            cnt++;
            return;
        }

        step += 1;
        helper(step, n, cnt);
        step -= 1; // Backtrack step

        step += 2;
        helper(step, n, cnt);
        step -= 2; // Backtrack step
    }

    int climbStairs(int n) {
        int step = 0, cnt = 0;
        helper(step, n, cnt);
        return cnt;
    }
};
*/

/*
Points to remember:
Step1. Identify a DP Problem.
Step2. To solve the problem after identification.
   1. Try to represent the given problem in terms of index.
   2. Do all possible operations/stuff on that index according to the problem statement.
   3. To count all possible ways - sum of all stuff. To find minimum/maximum - Take Minimum/maximum of all stuff.
*/

// M-2) Top-down DP: Memoization
// T.C: O(n), each step's result is computed only once, and it takes O(1) time to retrieve the result from the memoization array.
// S.C: O(n), space complexity is O(n) for the memoization array and the recursion stack depth, which is also O(n) in the worst case.
// The intuition is that the number of ways to climb n stairs is the sum of the number of ways to climb n-1 stairs and n-2 stairs, since we can either take one step or two steps from the n-th stair.
/*
class Solution {
public:
    int helper(int step, int n, vector<int>& dp) {
        if(step > n) 
            return 0;
    
        if(step == n) 
            return 1;
        
        if(dp[step] != -1)
            return dp[step];

        dp[step] = helper(step+1, n, dp) + helper(step+2, n, dp);
        return dp[step];
    }

    int climbStairs(int n) {
        int step = 0;
        vector<int> dp(n + 1, -1);   // Initialize memoization array
        
        return helper(step, n, dp);
    }
};
*/


// M-3) Bottom-up DP: Tabulation - Striver (SImilar to Fibonacci Series)
// T.C: O(N), we are running a simple iterative loop.
// S.C: O(N), we are using an external array of size ‘n+1’.
// The intuition is that the number of ways to climb n stairs is the sum of the number of ways to climb n-1 stairs and n-2 stairs, since we can either take one step or two steps from the n-th stair.
/*
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);   // Initialize memoization array
        dp[0]= 1;
        dp[1]= 1;
  
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};
*/

// M-3) Tabulation - Striver (SImilar to Fibonacci Series)
// T.C: O(N), we are running a simple iterative loop.
// S.C: O(1), we are not using any extra space.
/*
class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;   // start from 1
        int prev = 1;
        
        for(int i=2; i<=n; i++){
            int cur_i = prev2 + prev;
            prev2 = prev;
            prev= cur_i;
        }
        
        return prev;
    }
};
*/





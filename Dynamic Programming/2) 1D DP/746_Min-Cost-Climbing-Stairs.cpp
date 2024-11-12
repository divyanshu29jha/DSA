// M-1) DP - Memoization (top-down approach)
// T.C: O(N), the overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).
// S.C: O(N), we are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
/*
class Solution {
public:
    int solve(int i, vector<int>& cost, vector<int>& dp){
        if(i == 0 || i == 1) return 0;   // base case

        if(dp[i] != -1) return dp[i];

        int left = solve(i-1, cost, dp) + cost[i-1];   // jump one step 
        int right = solve(i-2, cost, dp) + cost[i-2];  // jump two step

        return dp[i] = min(left, right);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return solve(n, cost, dp);   // we need to reach the nth step, which is beyond the last index
    }
};
*/


// M-2) DP - Tabulation (bottom-up approach)
// T.C: O(N), we are running a simple iterative loop
// S.C: O(N), we are using an external array of size n.
/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= n; i++){    // i goes till n
            int left = dp[i-1] + cost[i-1];   // jump one step 
            int right = dp[i-2] + cost[i-2];  // jump two step

            dp[i] = min(left, right);
        }

        return dp[n];   // we need to reach the nth step, which is beyond the last index
    }
};
*/


// M-3) DP - Tabulation with space optimization (bottom-up approach)
// T.C: O(N), we are running a simple iterative loop
// S.C: O(1), we are not using any extra space.
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0;
        int prev = 0;

        for(int i = 2; i <= n; i++){    // i goes till n
            int left = prev + cost[i-1];   // jump one step 
            int right = prev2 + cost[i-2];  // jump two step

            int cur_i = min(left, right);
            prev2 = prev;
            prev = cur_i;
        }

        return prev;   // we need to reach the nth step, which is beyond the last index
    }
};
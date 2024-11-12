// M-1) DP - Memoization
// T.C: O(n*amount), there are n*amount states therefore at max 'n*amount' new problems will be solved.
// S.C: O(n*amount) + O(n), we are using a recursion stack space(O(n)) and a 2D array (O(n*amount)).
/*
class Solution {
public:
    int solve(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(target == 0)  // not compulsory, but will reduce further recursion calls
            return 1;
        
        if(ind == 0){
            if(target % coins[0] == 0)
                return 1;
            return 0;
        }

        if(dp[ind][target] != -1)
            return dp[ind][target];

        int notTaken = solve(ind-1, target, coins, dp);
        
        int taken = 0;
        if(coins[ind] <= target)
            taken = solve(ind, target-coins[ind], coins, dp);  // stay at same index

        return dp[ind][target] = taken + notTaken;
    }

    int change(int amount, vector<int>& coins) {
       int n = coins.size();
       // f(ind, target) --> no. of subsequences from 0 to ind that sum upto target (any coin can be chosen multiple times)
       vector<vector<int>> dp(n, vector<int>(amount+1, -1));

       return solve(n-1, amount, coins, dp); 
    }
};
*/

// M-2.1) DP - Tabulation
// T.C: O(n*amount), there are two nested loops
// S.C: O(n*amount), we are using an external array of size 'n*amount'. Stack Space is eliminated.
class Solution {
public:
    int change(int amount, vector<int>& coins) {
       int n = coins.size();
       // f(ind, target) --> no. of subsequences from 0 to ind that sum upto target (any coin can be chosen multiple times)
       vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));  // initialized with 0

        for(int i=0; i<=amount; i++){   // Initialize the first row of the DP table
            if(i % coins[0] == 0)
                dp[0][i] = 1;  // One way to make i using only multiples of coins[0]
        }

        long long mod = 1e18;
        for(int ind = 1; ind < n; ind++){
            for(int target = 0; target <= amount; target++){
                long long notTaken = dp[ind-1][target];
        
                long long taken = 0;
                if(coins[ind] <= target)
                    taken = dp[ind][target-coins[ind]];  // stay at same index

                dp[ind][target] = (taken % mod + notTaken % mod) % mod;
            }
        }

       return dp[n-1][amount]; 
    }
};


// M-2.2) DP - Tabulation (Divyank)
// T.C: O(n*amount), there are two nested loops
// S.C: O(n*amount), we are using an external array of size 'n*amount'. Stack Space is eliminated.
/*
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        vector<vector<long long>> dp(n+1, vector<long long>(amount+1, 0));   // 1-based indexing
        
        long long mod = 1e18;

        for(int i = 0; i <= n; i++){ 
            dp[i][0] = 1;  // there is only one way to make amount 0, i.e. using no coins.
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i-1][j];

                if(coins[i-1] <= j) 
                  dp[i][j] = (dp[i][j-coins[i-1]] + dp[i-1][j]) % mod;   // stay at same index of dp table, coins[i-1] represents current coin
            }
        }
        
        return dp[n][amount];
    }
};
*/


// M-3) Space Optimization in Tabulation
// T.C: O(n*amount), there are two nested loops
// S.C: O(amount), we are using two external arrays of size 'amount+1'.
/*
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        vector<long long> prev(amount+1, 0), curr(amount+1,0);   // 1-based indexing
        
        long long mod = 1e18;

        prev[0] = 1;  // Base case: there's one way to make amount 0 (using no coins)

        for(int i = 1; i <= n; i++){
            curr[0] = 1;  // Always one way to make amount 0 for the current row
            for(int j = 1; j <= amount; j++){
                curr[j] = prev[j];

                if(coins[i-1] <= j) 
                  curr[j] = (curr[j-coins[i-1]] + prev[j]) % mod;   // stay at same index of dp table, coins[i-1] represents current coin
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};
*/
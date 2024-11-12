// M-1) DP - Memoization
// T.C: O(n*amount), there are n*W states therefore at max 'n*amount' new problems will be solved.
// S.C: O(n*amount) + O(n), we are using a recursion stack space(O(n)) and a 2D array (O(n*amount)).
/*
class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0)   // not compulsory, but will reduce further recursion calls
            return 0;

        if(ind < 0){ 
            if(amount == 0)
                return 0;
            else
                return 1e9;
        }

        // if(ind == 0){   // M-2)
        //     if(amount % coins[ind] == 0)
        //         return amount/coins[ind];
        //     else
        //         return 1e9;
        // }
        
        if(dp[ind][amount] != -1)
            return dp[ind][amount];

        int notTaken = 0 + solve(ind-1, amount, coins, dp);
        
        int taken = 1e9;
        if(coins[ind] <= amount)
            taken = 1 + solve(ind, amount - coins[ind], coins, dp);   // stay at same index

        return dp[ind][amount] = min(taken, notTaken);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        // f(ind, target) --> gives no. of coins from index 0 to ind that sum up to target
        int ans = solve(n-1, amount, coins, dp);
        if(ans >= 1e9)    // If 'ans' is still very large, it means it's not possible to form the target sum
            return -1;
        return ans;
    }
};
*/

// M-2.1) DP - Tabulation
// T.C: O(n*amount), there are two nested loops
// S.C: O(n*amount), we are using an external array of size 'n*amount'. Stack Space is eliminated.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp[ind][target] --> gives no. of coins from index 0 to ind that sum up to target
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        for(int i=0; i<=amount; i++){   // Initialize the first row of the DP table
            if(i % coins[0] == 0)
                dp[0][i] = i/coins[0];
            else
                dp[0][i]  = 1e9; // Set it to a very large value if not possible
        }

        for(int ind = 1; ind < n; ind++){
            for(int target = 0; target <= amount; target++){
                int notTaken = 0 + dp[ind-1][target];
        
                int taken = 1e9;
                if(coins[ind] <= target)
                    taken = 1 + dp[ind][target - coins[ind]];   // stay at same index

                dp[ind][target] = min(taken, notTaken);
            }
        }

        int ans = dp[n-1][amount];
        if (ans >= 1e9)  // If 'ans' is still very large, it means it's not possible to form the target sum
            return -1;
        
        return ans;
    }
};


// M-2.2) DP - Tabulation (Divyank)
// T.C: O(n*amount), there are two nested loops
// S.C: O(n*amount), we are using an external array of size 'n*amount'. Stack Space is eliminated.
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp[ind][target] --> gives no. of coins from index 0 to ind that sum up to target
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 1e9));  // 1-based indexing
        
        for(int ind = 0; ind <= n; ind++){  // Base case: With 0 amount, no coins are needed
            dp[ind][0] = 0;
        }
    
        for(int ind = 1; ind <= n; ind++){
            for(int target = 1; target <= amount; target++){
                dp[ind][target] = 0 + dp[ind-1][target];
        
                if(coins[ind-1] <= target)  // coins[ind-1] as 1 based index
                    dp[ind][target] = min(1 + dp[ind][target-coins[ind-1]], dp[ind-1][target]);   // stay at same index of dp table
            }
        }

        int ans = dp[n][amount];
        if (ans >= 1e9)  // If 'ans' is still very large, it means it's not possible to form the target sum
            return -1;
        
        return ans;
    }
};
*/


// M-3) Space Optimization in Tabulation
// T.C: O(n*amount), there are two nested loops
// S.C: O(amount), we are using two external arrays of size 'amount+1'.
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1,0);
        
        for(int i=0; i<=amount; i++){   // Initialize the first row of the DP table
            if(i % coins[0] == 0)
                prev[i] = i/coins[0];
            else
                prev[i]  = 1e9; // Set it to a very large value if not possible
        }

        for(int ind = 1; ind < n; ind++){
            for(int target = 0; target <= amount; target++){
                int notTaken = 0 + prev[target];
        
                int taken = 1e9;
                if(coins[ind] <= target)
                    taken = 1 + curr[target - coins[ind]];   // stay at same index

                curr[target] = min(taken, notTaken);
            }

            prev = curr;
        }

        int ans = prev[amount];
        if (ans >= 1e9)  // If 'ans' is still very large, it means it's not possible to form the target sum
            return -1;
        
        return ans;
    }
};
*/
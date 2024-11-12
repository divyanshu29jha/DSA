// Same as Unbounded Knapsack Problem

// M-1) DP - Memoization
// T.C: O(n^2), S.C: O(n^2) + O(n)
/*
class Solution{
  public:
    int solve(int ind, int target, vector<int>& sizes, vector<int>& cost, vector<vector<int>>& dp){
        if(target == 0)   // not compulosry, but will reduce further recursion calls
            return 0;
            
        if(ind == 0){   // sizes[0] = 1
            return target*cost[0];    // target/sizes[0] = target
        }
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        
        int notTaken = 0 + solve(ind-1, target, sizes, cost, dp);
        
        int taken = INT_MIN;
        if(sizes[ind] <= target)
            taken = cost[ind] + solve(ind, target-sizes[ind], sizes, cost, dp);  // stay at same index
            
        return dp[ind][target] = max(notTaken, taken);
    }
    
    int cutRod(int price[], int n) {
        vector<int> cost(price, price+n);
        
        vector<int> sizes(n);
        for(int i=0; i<n; i++){
            sizes[i] = i+1;
        }
        
        int target = n;  // sum of all sizes cut should be equal to size of rod i.e n 
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        // f(ind, target) --> no. of subsequences from index 0 to ind that sum upto target (any element cannot be chosen multiple times)
        return solve(n-1, target, sizes, cost, dp);
    }
};
*/


// M-2) DP - Tabulation
// T.C: O(n*n), there are two nested loops.
// S.C: O(n*n), we are using an external array of size 'n*n. Stack Space is eliminated.
class Solution{
public:
    int cutRod(int price[], int n){
        vector<int> cost(price, price+n);
        
        vector<int> sizes(n);
        for(int i=0; i<n; i++){
            sizes[i] = i+1;
        }
        
        // dp[ind][target] --> no. of subsequences from index 0 to ind that sum upto target (any element cannot be chosen multiple times)
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        for(int i=0; i<=n; i++){
            dp[0][i] = i * cost[0];
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int target = 0; target <= n; target++){   
                int notTaken = 0 + dp[ind-1][target];
        
                int taken = INT_MIN;
                if(sizes[ind] <= target)
                    taken = cost[ind] + dp[ind][target-sizes[ind]];  // stay at same index
            
                dp[ind][target] = max(notTaken, taken);
            }
        }
        
        return dp[n-1][n];
    }
};  
// M-1) DP - Memoization
// T.C: O(N*W), S.C: O(N*W) + O(N)
/*
class Solution{
public:
    int solve(int ind, int W, vector<vector<int>>& dp, vector<int>& value, vector<int>& weight){
        // if(W == 0 || ind < 0)    // M-2)
        //     return 0;
        
        if(W == 0)     // not compulosry, but will reduce further recursion calls
            return 0;
            
        if(ind == 0){
            if(weight[ind] <= W)
                return W/weight[ind] * value[ind];
            return 0;
        }
        
        if(dp[ind][W] != -1)
            return dp[ind][W];
        
        int notTaken = 0 + solve(ind-1, W, dp, value, weight);
        
        int taken = 0;
        if(weight[ind] <= W)
            taken = value[ind] + solve(ind, W-weight[ind], dp, value, weight);  // stay at same index
            
        return dp[ind][W] = max(taken, notTaken);
    }
    
    int knapSack(int N, int W, int val[], int wt[]){
        vector<int> value(val, val+N);
        vector<int> weight(wt, wt+N);
        
        // f(ind, target) --> from index 0 to ind, max value that we can get by taking items such that sum of their weights <= W
        vector<vector<int>> dp(N, vector<int>(W+1, -1));
        
        return solve(N-1, W, dp, value, weight);
    }
};
*/


// M-2.1) DP - Tabulation
// T.C: O(n*W), there are two nested loops.
// S.C: O(n*W), we are using an external array of size 'n*W'. Stack Space is eliminated.
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]){
        vector<int> value(val, val+N);
        vector<int> weight(wt, wt+N);
        
        // f(ind, target) --> from index 0 to ind, max value that we can get by taking items such that sum of their weights <= W
        vector<vector<int>> dp(N, vector<int>(W+1, 0));
        
        for(int i=weight[0]; i<=W; i++){
            dp[0][i] = i/weight[0] * value[0];
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int target = 0; target <= W; target++){
                int notTaken = 0 + dp[ind-1][target];
               
                int taken = 0;
                if(weight[ind] <= target)
                    taken = value[ind] + dp[ind][target-weight[ind]];
                    
                dp[ind][target] = max(taken, notTaken);
            }
        }
        
        return dp[N-1][W];
    }
};  


// M-2.2) DP - Tabulation (Divyank)
// T.C: O(n*W), there are ntwo nested loops.
// S.C: O(n*W), we are using an external array of size 'n*W'. Stack Space is eliminated.
/*
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]){
        vector<int> value(val, val+N);
        vector<int> weight(wt, wt+N);
        
        // f(ind, target) --> from index 0 to ind, max value that we can get by taking items such that sum of their weights <= W
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        
        for(int i=1; i<=N; i++){        // i represents element
            for(int j=1; j<=W; j++){   // j represents knapsack capacity
                dp[i][j] = dp[i-1][j];  // not taken
                if(wt[i-1] <= j){       // taken (wt[i-1] represents current element's weight since 1-based indexing)
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);   // stay at same index
                }
            }
        }
        
        return dp[N][W];
    }
}; 
*/


// M-3.1) Space Optimization in tabulation (using two arrays)
// T.C: O(n*W), there are ntwo nested loops.
// S.C: O(W), we are using an external array of size 'W+1'.
/*
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]){
        vector<int> value(val, val+N);
        vector<int> weight(wt, wt+N);
        
        // f(ind, target) --> from index 0 to ind, max value that we can get by taking items such that sum of their weights <= W
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        for(int i=weight[0]; i<=W; i++){
            prev[i] = i/weight[0] * value[0];
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int target = 0; target <= W; target++){
                int notTaken = 0 + prev[target];
               
                int taken = 0;
                if(weight[ind] <= target)
                    taken = value[ind] + curr[target-weight[ind]];
                    
                curr[target] = max(taken, notTaken);
            }
            
            prev = curr;
        }
        
        return prev[W];
    }
};
*/ 


// M-3.2) Single Array Space Optimisation
// T.C: O(n*W), there are ntwo nested loops.
// S.C: O(W), we are using an external array of size 'W+1' to store only one row.
// start filling from left to right in for-loop as we need new value of the same row (since staying at same index)
/*
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]){
        vector<int> value(val, val+N);
        vector<int> weight(wt, wt+N);
        
        // f(ind, target) --> from index 0 to ind, max value that we can get by taking items such that sum of their weights <= W
        vector<int> prev(W+1, 0);
        
        for(int i=weight[0]; i<=W; i++){
            prev[i] = i/weight[0] * value[0];
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int target = 0; target <= W; target++){
                int notTaken = 0 + prev[target];
               
                int taken = 0;
                if(weight[ind] <= target)
                    taken = value[ind] + prev[target-weight[ind]];   // stay at same index
                    
                prev[target] = max(taken, notTaken);
            }
        }
        
        return prev[W];
    }
};
*/
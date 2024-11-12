// Example: W = 5, wt = [2,3,4,1], val = [30,40,20,10]. Do dry run and visualiza. Also, form dp table and visualize.
// https://takeuforward.org/data-structure/0-1-knapsack-dp-19/

// M-1) DP - Memoization
// T.C: O(n*W), there are n*W states therefore at max 'N*W' new problems will be solved.
// S.C: O(n*W) + O(n), we are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).
/*
class Solution {
  public:
    int solve(int ind, vector<vector<int>>& dp, int W, vector<int>& wt, vector<int>& val){
        // if(ind < 0 || W == 0){   // Base case (M-2): If there are no items left or the knapsack has no capacity, return 0
        //     return 0; 
        // }
        
        if(W == 0){
            return 0;
        }
    
        if(ind == 0){
            if(wt[ind] <= W)
                return val[ind];
            else 
                return 0;
        }
        
        if(dp[ind][W] != -1)
            return dp[ind][W];
        
        int notTaken = 0 + solve(ind-1, dp, W, wt, val);   /// no value added for current ind
        int taken = 0;
        if(wt[ind] <= W)
            taken = val[ind] + solve(ind-1, dp, W - wt[ind], wt, val);
            
        return dp[ind][W] = max(notTaken, taken);
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        
        // f(ind, W) --> max value from index 0 to ind (provided total weight till ind <= W)
        return solve(n-1, dp, W, wt, val);    // returns val
    }
};  
*/


// M-2.1) DP - Tabulation
// T.C: O(n*W), there are ntwo nested loops.
// S.C: O(n*W), we are using an external array of size 'n*W'. Stack Space is eliminated.
class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        // dp[ind][cap] --> gives max value from index 0 to ind (provided total weight till ind is less than equal to cap)
        vector<vector<int>> dp(n, vector<int>(W+1, 0));   // initialize it with zeros (not -1)
        
        for(int i = wt[0]; i <= W; i++){    // Base condition: Fill in the first row for the weight of the first item
            dp[0][i] = val[0];
        }

        for(int ind = 1; ind < n; ind++){
            for(int cap = 0; cap <= W; cap++){
                int notTaken = dp[ind-1][cap];
                
                int taken = INT_MIN;
                if(wt[ind] <= cap)
                    taken = val[ind] + dp[ind-1][cap - wt[ind]];
            
                dp[ind][cap] = max(notTaken, taken);
            }
        }

        return dp[n-1][W];  // The final result (val) is in the last cell of the DP table
    }
};


// M-2.2) DP - Tabulation (Divyank)
/*
class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));   // 1-based index
        
        for(int i=1; i<=n; i++){        // i represents element
            for(int j=1; j<=W; j++){   // j represents knapsack capacity
                dp[i][j] = dp[i-1][j];  // not taken
                if(wt[i-1] <= j){       // taken (wt[i-1] represents current element's weight since 1-based indexing)
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
            }
        }
       
        return dp[n][W];
    }
};
*/


// M-3.1) Space Optimization in tabulation (using two arrays)
// T.C: O(n*W), there are ntwo nested loops.
// S.C: O(W), we are using an external array of size 'W+1'.
/*
class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        for(int i = wt[0]; i <= W; i++){    // Base condition: Fill in the first row for the weight of the first item
            prev[i] = val[0];
        }

        for(int ind = 1; ind < n; ind++){
            for(int cap = 0; cap <= W; cap++){
                int notTaken = prev[cap];
                
                int taken = INT_MIN;
                if(wt[ind] <= cap)
                    taken = val[ind] + prev[cap - wt[ind]];
            
                curr[cap] = max(notTaken, taken);
            }
            
            prev = curr;
        }

        return prev[W];  // The final result (val) is in the last cell of the DP table
    }
};
*/

// M-3.2) Single Array Space Optimisation
// T.C: O(n*W), there are ntwo nested loops.
// S.C: O(W), we are using an external array of size 'W+1' to store only one row.
// start filling from right to left in for-loop as we need previous row values and they should not be changed.
/*
class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> prev(W+1, 0);
        
        for(int i = wt[0]; i <= W; i++){    // Base condition: Fill in the first row for the weight of the first item
            prev[i] = val[0];
        }

        for(int ind = 1; ind < n; ind++){
            for(int cap = W; cap >= 0; cap--){
                int notTaken = prev[cap];
                
                int taken = INT_MIN;
                if(wt[ind] <= cap)
                    taken = val[ind] + prev[cap - wt[ind]];
            
                prev[cap] = max(notTaken, taken);
            }
        }

        return prev[W];  // The final result (val) is in the last cell of the DP table
    }
};
*/
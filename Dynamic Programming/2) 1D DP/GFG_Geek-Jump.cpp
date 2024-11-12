// M-1) Recursion (top-down approach) --> Gives TLE
// T.C: O(2^n) [either take 1 jump or 2 jump], S.C: O(n) fpr recursion stack.
// f(n-1) signifies the minimum amount of energy required to move from stair 0 to stair n-1. 
// Therefore f(0) simply should give us the answer as 0(base case).
/*
class Solution {
  public:
    int solve(int idx, vector<int>& height){
        if(idx == 0)  return 0;
        
        int left = solve(idx-1, height) + abs(height[idx] - height[idx-1]);    // jump one
        
        int right = INT_MAX;   // to reach idx = 1, jump two is not possible
        if(idx > 1)
            right = solve(idx-2, height) + abs(height[idx] - height[idx-2]);   // jump two
        
        return min(left, right);
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        return solve(n-1, height);   // we need to reach idx (n-1)
    }
};
*/


// M-2) DP - Memoization (top-down approach)
// T.C: O(N), the overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).
// S.C: O(N), we are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
/*
class Solution {
  public:
    int solve(int idx, vector<int>& height, vector<int>& dp){
        if(idx == 0)  return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int left = solve(idx-1, height, dp) + abs(height[idx] - height[idx-1]);    // jump one
        
        int right = INT_MAX;   // to reach idx = 1, jump two is not possible
        if(idx > 1)
            right = solve(idx-2, height, dp) + abs(height[idx] - height[idx-2]);   // jump two
        
        return dp[idx] = min(left, right);
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        return solve(n-1, height, dp);   // we need to reach idx (n-1)
    }
};
*/  


// M-3) DP - Tabulation (bottom-up approach)
// T.C: O(N), We are running a simple iterative loop
// S.C: O(N), We are using an external array of size n.
/*
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        dp[0] = 0;
        
        for(int ind=1; ind<n; ind++){
            int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
            
            int jumpTwo = INT_MAX;
            if(ind>1)
                jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
            dp[ind] = min(jumpOne, jumpTwo);
        }
 
        return dp[n-1];   // we need to reach idx (n-1)
    }
};
*/ 

// M-4) DP - Tabulation with space optimization(bottom-up approach)
// T.C: O(N), We are running a simple iterative loop
// S.C: O(1), We are not using any extra space.
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int prev = 0;
        int prev2 = 0;
        
        for(int i=1; i<n; i++){
            int jumpOne= prev + abs(height[i]-height[i-1]);
            
            int jumpTwo = INT_MAX;
            if(i>1)
                jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
            cur_i = min(jumpOne, jumpTwo);
            prev2 = prev;
            prev = cur_i;
        }
        
        return prev;
    }
};
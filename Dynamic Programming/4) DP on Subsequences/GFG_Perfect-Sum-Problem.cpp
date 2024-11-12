// M-1) DP - Meoization
// T.C: O(n*Sum), there are n*sum states therefore at max 'n*Sum' new problems will be solved.
// S.C: O(n*Sum) + O(n), we are using a recursion stack space(O(n)) and a 2D array (O(n*Sum)).
// Edge cases: when arr contains 0s. (since taking 0s will not affect the sum)
// Eg: [0,0,1], when we take 1, target becomes 0. But two-0s still remain to be considered in subset.
/*
class Solution{
	public:
	int mod = 1e9 + 7;
	
	int solve(int ind, int target, vector<int>& v, vector<vector<int>>& dp){
	   // if(target == 0)     // if arr contains 0s, then traverse till ind==0. Don't return in between even if target == 0. 
	   //     return 1;
	        
	    if(ind == 0){
	        if(target == 0 && v[0] == 0)  return 2;     // taken + notTaken (both are valid)
 	        if(target == 0 || target == v[0]) return 1;   
 	        return 0;
	    }
	    
	    if (dp[ind][target] != -1) 
            return dp[ind][target];
	    
	    int notTaken = solve(ind-1, target, v, dp) % mod;
        
        int taken = 0;
        if(v[ind] <= target){
            taken = solve(ind-1, target - v[ind], v, dp) % mod;
        }
        
        return dp[ind][target] = (taken + notTaken) % mod;
	}
	
	int perfectSum(int arr[], int n, int sum){
        vector<int> v(arr, arr + n);
        
        // dp[ind][target] : from index 0 to ind, how many subsets have sum equal to target
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));     
        return solve(n-1, sum, v, dp);
	}
};
*/


// M-2) DP - Tabulation
// T.C: O(n*Sum), there are two nested loops
// S.C: O(n*Sum), we are using an external array of size 'n*sum'. Stack Space is eliminated.
// Edge cases: when arr contains 0s. (since taking 0s will not affect the sum)
// Eg: [0,0,1], when we take 1, target becomes 0. But two-0s still remain to be considered in subset.

class Solution{
	public:
	int mod = 1e9 + 7;
	
	int perfectSum(int arr[], int n, int sum){
        vector<int> v(arr, arr + n);
        
        // dp[ind][target] : from index 0 to ind, how many subsets have sum equal to target
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        
        for(int ind=0; ind < n; ind++){   // Base case: If the target is 0, there is one valid subset (the empty subset)
            dp[ind][0] = 1;
        }
       
        if(v[0] <= sum) {    // Initialize the first row based on the first element of the array
            dp[0][v[0]] = 1;
        }
        
        if(v[0] == 0){  // Special handling for the case when the first element is 0
            dp[0][0] = 2;  // Two ways: include or exclude 0
        }
        
        for(int ind=1; ind<n; ind++){
            for(int target = 0; target <= sum; target++){   // Start from 0 to handle the zero sum case
                int notTaken = dp[ind-1][target];
                
                int taken = 0;
                if(v[ind] <= target)
                    taken = dp[ind-1][target - v[ind]];
                    
                dp[ind][target] = (taken + notTaken) % mod;
            }
        }
        
        return dp[n-1][sum];
	}
};


// M-3) Space Optimation in Tabulation
// T.C: O(n*Sum), there are two nested loops
// S.C: O(Sum), we are using an external array of size 'sum+1' to store only one row.
// Edge cases: when arr contains 0s. (since taking 0s will not affect the sum)
// Eg: [0,0,1], when we take 1, target becomes 0. But two-0s still remain to be considered in subset.
/*
class Solution{
	public:
	int mod = 1e9 + 7;
	
	int perfectSum(int arr[], int n, int sum){
        vector<int> v(arr, arr + n);
        
        vector<int> prev(sum + 1, 0);  // Initialize a vector 'prev' to represent the previous row of the DP table
        
        // prev[0] = 1;   // Don't write this if arr contains 0's
       
        if(v[0] <= sum){    // Initialize the first row based on the first element of the array
            prev[v[0]] = 1;
        }
        
        if(v[0] == 0){  // Special handling for the case when the first element is 0
            prev[0] = 2;  // Two ways: include or exclude 0
        }
        else{
            prev[0] = 1;  
        }
        
        for(int ind=1; ind<n; ind++){
            vector<int> curr(sum + 1, 0);  // Create a vector 'curr' to represent the current row of the DP table
            curr[0] = 1;    // Base case: If k is 0, we can achieve it by taking no elements
            
            for(int target = 0; target <= sum; target++){   // Start from 0 to handle the zero sum case
                int notTaken = prev[target];
                
                int taken = 0;
                if(v[ind] <= target)
                    taken = prev[target - v[ind]];
                    
                curr[target] = (taken + notTaken) % mod;
            }
            
            prev = curr;
        }
        
        return prev[sum];   // The final result is in the last cell of the 'prev' vector
	}
};
*/
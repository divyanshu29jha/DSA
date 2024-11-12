// M-1) DP - Meoization
// T.C: O(n*Sum), there are n*sum states therefore at max 'n*Sum' new problems will be solved.
// S.C: O(n*Sum) + O(n), we are using a recursion stack space(O(n)) and a 2D array (O(n*Sum)).
// Edge cases: when arr contains 0s. (since taking 0s will not affect the sum)
// Eg: [0,0,1], when we take 1, target becomes 0. But two-0s still remain to be considered in subset.
// The question "Count Partitions with a difference D" is modified to "Count Number of subsets with sum (totSum - D)/2".
/*
class Solution{
	public:
	int mod = 1e9 + 7;
	
	int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
	   // if(target == 0)     // if arr contains 0s, then traverse till ind==0. Don't return in between even if target == 0. 
	   //     return 1;
	        
	    if(ind == 0){
	        if(target == 0 && arr[0] == 0)  return 2;     // taken + notTaken (both are valid)
 	        if(target == 0 || target == arr[0]) return 1;   
 	        return 0;
	    }
	    
	    if (dp[ind][target] != -1) 
            return dp[ind][target];
	    
	    int notTaken = solve(ind-1, target, arr, dp) % mod;
        
        int taken = 0;
        if(arr[ind] <= target){
            taken = solve(ind-1, target - arr[ind], arr, dp) % mod;
        }
        
        return dp[ind][target] = (taken + notTaken) % mod;
	}
	
	int countPartitions(int n, int d, vector<int>& arr){
        int totSum = 0;
        for(int i=0; i<arr.size();i++){
            totSum += arr[i];
        }
        
        int s2 = (totSum-d)/2;
        //Checking for edge cases
        if(totSum-d < 0) return 0;
        if((totSum-d)%2 == 1) return 0;
    
        
        // dp[ind][target] : from index 0 to ind, how many subsets have sum equal to target
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return solve(n-1,s2,arr,dp);
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
	
	int solve(vector<int>& arr, int n, int sum){
        // dp[ind][target] : from index 0 to ind, how many subsets have sum equal to target
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        
        for(int ind=0; ind < n; ind++){   // Base case: If the target is 0, there is one valid subset (the empty subset)
            dp[ind][0] = 1;
        }
       
        if(arr[0] <= sum)   // Initialize the first row based on the first element of the array
            dp[0][arr[0]] = 1;
        
        if(arr[0] == 0) // Special handling for the case when the first element is 0
            dp[0][0] = 2;  // Two ways: include or exclude 0
        
        for(int ind=1; ind<n; ind++){
            for(int target = 0; target <= sum; target++){   // Start from 0 to handle the zero sum case
                int notTaken = dp[ind-1][target];
                
                int taken = 0;
                if(arr[ind] <= target)
                    taken = dp[ind-1][target - arr[ind]];
                    
                dp[ind][target] = (taken + notTaken) % mod;
            }
        }
        
        return dp[n-1][sum];
	}
	
	int countPartitions(int n, int d, vector<int>& arr){
	    int totSum = 0;
        for(int i=0; i<n;i++){
            totSum += arr[i];
        }
    
        if(totSum-d < 0 || (totSum-d)%2 ) return 0;   // Checking for edge cases
    
        return solve(arr, n, (totSum-d)/2);
	}
};

// M-1) DP - Memoization
// T.C: O(n*sum) + O(n) + O(n), there are two nested loops that account for O(n*sum), at starting we are running a for loop to calculate sum and at last a for loop to traverse the last row.
// S.C: O(n*sum) + O(n), we are using an external array of size 'n* sum' and a stack space of O(n).
// f(ind, target) --> From index 0 to ind, does any subsequence exist in array with sum equal to target.
/*
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target == 0)   // Base case: If the target sum is 0, return true
        return dp[ind][target] = true;

    if(ind == 0)  // Base case: If we have considered all elements and the target is still not 0, return false
        return dp[ind][target] = (arr[0] == target);

    if(dp[ind][target] != -1)      // If the result for this state is already calculated, return it
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind-1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind-1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

class Solution{
  public:
	int minDifference(int arr[], int n) {
	    int sum = 0;
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	    }
	    
	    // Initialize a DP table to store the results of the subset sum problem
	    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));     
	    
        // Calculate the subset sum for each possible sum from 0 to the total sum
	    vector<int> vec(arr, arr + n); 
        for(int target = 0; target <= sum; target++){
            bool dummy = subsetSumUtil(n-1, target, vec, dp);
        }

        int mini = 1e9;
        for(int target = 0; target <= sum; target++){
            if(dp[n - 1][target] == true){    // check for the last row i.e (n-1)th index
                int diff = abs(target - (sum - target));   
                mini = min(mini, diff);
            }
        }
        
        return mini;
	} 
};
*/

// M-2.1) DP - Tabulation
// T.C: O(n*sum) + O(n) + O(n), there are two nested loops that account for O(n*sum), at starting we are running a for loop to calculate 'sum', and at last a for loop to traverse the last row.
// S.C: O(n*sum), we are using an external array of size 'n*sum'. Recursion Stack Space is eliminated
// f(ind, target) --> From index 0 to ind, does any subsequence exist in array with sum equal to target
class Solution{
  public:
	int minDifference(int arr[], int n) {
	    int sum = 0;
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	    }
	    
	    // Initialize a DP table to store the results of the subset sum problem
	    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
	    
        for(int i = 0; i < n; i++){   // Base case: If sum is 0, we can always achieve it by taking no elements
            dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;    // till 0-th index, sum = arr[0] is always possible
        
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum; target++){
                // If we don't take the current element, the result is the same as the previous row
                bool notTaken = dp[ind-1][target];

                // If we take the current element, subtract its value from the target and check the previous row
                bool taken = false;
                if(arr[ind] <= target){
                    taken = dp[ind-1][target - arr[ind]];
                }

                dp[ind][target] = notTaken || taken;
            }
        }
        
        int mini = INT_MAX;
        for(int target = 0; target <= sum; target++){
            if(dp[n-1][target] == true){    // check for the last row i.e (n-1)th index
                int s1 = target;
                int s2 = sum - target;
                mini = min(mini, abs(s1-s2));
            }
        }
        
        return mini;
	} 
};  


// M-2.2) DP - Tabulation
// T.C: O(n*sum) + O(n) + O(n), there are two nested loops that account for O(n*sum), at starting we are running a for loop to calculate 'sum', and at last a for loop to traverse the last row.
// S.C: O(n*sum), we are using an external array of size 'n*sum'. Recursion Stack Space is eliminated
// f(ind, target) --> From index 0 to ind, does any subsequence exist in array with sum equal to target
/*
class Solution{
  public:
	int minDifference(int arr[], int n) {
	    int sum = 0;
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	    }
	    
	    vector<vector<bool>> dp(n, vector<bool>(sum/2 + 1, false));   // consider targets till sum/2 only
	    
        for(int i = 0; i < n; i++){   // Base case: If sum is 0, we can always achieve it by taking no elements
            dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;    // till 0-th index, sum = arr[0] is always possible
        
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum/2; target++){
                // If we don't take the current element, the result is the same as the previous row
                bool notTaken = dp[ind-1][target];

                // If we take the current element, subtract its value from the target and check the previous row
                bool taken = false;
                if(arr[ind] <= target){
                    taken = dp[ind-1][target - arr[ind]];
                }

                dp[ind][target] = notTaken || taken;
            }
        }
        
        int diff;
        for(int target = sum/2; target >= 0; target--){    // check max target closest to sum/2
            if(dp[n-1][target] == true){    // check for the last row i.e (n-1)th index
                int s1 = target;
                int s2 = sum - target;
                diff = abs(s1-s2);
                break;
            }
        }

        return diff;
	} 
};
*/
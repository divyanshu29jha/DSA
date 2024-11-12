// M-1) Recursion (my brute force) --> TLE
// T.C: O(2^n), S.C: O(2^n) + O(n)
/*
class Solution{   
public:
    bool findCombination(int i, vector<int>& comb, int sum, vector<int>& arr){
        if(sum == 0)
            return true;
            
        if(i == arr.size() || sum < 0)
            return false;
        
        comb.push_back(arr[i]);
        if(findCombination(i+1, comb, sum - arr[i], arr))
            return true;
        comb.pop_back();
        
        while(i+1 < arr.size() && arr[i] == arr[i+1]){    // skip duplicates
            i++;
        }
        if(findCombination(i+1, comb, sum, arr))
            return true;
            
        return false;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        sort(arr.begin(), arr.end());
        int i = 0;
        vector<int> comb;
        return findCombination(i, comb, sum, arr);  
    }
};
*/ 

// M-2) DP - Memoization
// T.C: O(N*Sum) as there are N*sum states therefore at max 'N*Sum' new problems will be solved. 
// S.C: O(N*Sum) + O(N) as we are using a recursion stack space(O(N)) and a 2D array (O(N*Sum)).

// We need to find f(n-1, target) which means that we need to find whether there exists a subsequence in the array from index 0 to n-1, 
// whose sum is equal to the target.
// f(ind, target) --> Check whether a subsequence exists in the array fron index 0 to ind, whose sum is equal to target.

// Create a dp array of size [n][sum+1]. The size of the input array is ‘n’, so the index will always lie between ‘0’ and ‘n-1’. 
// The sum can take any value between ‘0’ and ‘sum’. Therefore we take the dp array as dp[n][sum+1].
/*
class Solution{   
public:
    bool solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0)     // If the target sum is 0, we have found a subset
            return true;
            
        if(ind == 0)        // If we have reached the first element in 'arr'
            return arr[0] == target;
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
       
        bool notTaken = solve(ind-1, target, arr, dp);   // taking the current element into the subset

        bool taken = false;  // taking the current element into the subset if it doesn't exceed the target
        if(arr[ind] <= target)
            taken = solve(ind-1, target - arr[ind], arr, dp);

        return dp[ind][target] = notTaken || taken;  // Store the result in the dp array to avoid recomputation
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n-1, sum, arr, dp);
    }
};
*/


// M-3) DP - Tabulation
// T.C: O(N*Sum) as there are two nested loops
// S.C: O(N*Sum) as we are using an external array of size 'N*Sum'. Stack Space is eliminated.
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        // Base case: If the target sum is 0, we can always achieve it by taking no elements
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        
        if(arr[0] <= sum) 
            dp[0][arr[0]] = true;

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

        return dp[n-1][sum];    // The final result is stored in dp[n-1][k]
    }
};


// M-4) DP - Space Optimization in Tabulation
// T.C: O(N*sum) as there are two nested loops
// S.C: O(sum) as we are using an external array of size ‘sum+1’ to store only one row.
/*
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        vector<bool> prev(sum + 1, false);   // Initialize a vector 'prev' to store the previous row of the DP table
    
        prev[0] = true;   // Base case: If the target sum is 0, we can always achieve it by taking no elements
    
        if (arr[0] <= sum){  // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
            prev[arr[0]] = true;
        }
    
        for(int ind = 1; ind < n; ind++){
            vector<bool> curr(sum + 1, false);   // Initialize a new row 'cur' to store the current state of the DP table
        
            curr[0] = true;   // Base case: If the target sum is 0, we can achieve it by taking no elements

            for(int target = 1; target <= sum; target++){
                bool notTaken = prev[target];  // If we don't take the current element, the result is the same as the previous row
            
                bool taken = false;   // If we take the current element, subtract its value from the target and check the previous row
                if (arr[ind] <= target) {
                    taken = prev[target - arr[ind]];
                }

                curr[target] = notTaken || taken;   // Store the result in the current DP table row for the current subproblem
            }

            prev = curr;    // Update 'prev' with the current row 'cur' for the next iteration
        }
        
        return prev[sum];     // The final result is stored in prev[k]
    }
};
*/
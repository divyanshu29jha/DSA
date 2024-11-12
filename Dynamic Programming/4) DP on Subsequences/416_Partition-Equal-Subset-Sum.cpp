// M-1) Recursion (my brute force) --> Gives TLE
// T.C: O(2^n), S.C: O(2^n) + O(n)
/*
class Solution {
public:
    int getSum(vector<int> v){
        int sum = 0;
        for(auto num : v){
            sum += num;
        }
        return sum;
    }

    bool solve(int i, vector<int>& v1, vector<int>& v2, vector<int>& nums){
        if(i == nums.size()){
            if(getSum(v1) == getSum(v2))
                return true;
            return false;
        }

        v1.push_back(nums[i]);
        bool takenInV1 = solve(i+1, v1, v2, nums);
        v1.pop_back();  

        v2.push_back(nums[i]);
        bool takenInV2 = solve(i+1, v1, v2, nums);
        v2.pop_back(); 

        return takenInV1 || takenInV2; 
    }

    bool canPartition(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        int i = 0;
        return solve(i, v1, v2, nums);
    }
};
*/


// M-2) DP - Memoization
// T.C: O(N*target) as there are N*sum states therefore at max 'N*target' new problems will be solved. 
// S.C: O(N*target) + O(N) as we are using a recursion stack space(O(N)) and a 2D array (O(N*target)).

// We need to find f(n-1, target) which means that we need to find whether there exists a subsequence in the array from index 0 to n-1, 
// whose sum is equal to the target.
// f(ind, target) --> Check whether a subsequence exists in the array fron index 0 to ind, whose sum is equal to target.

// Create a dp array of size [n][sum+1]. The size of the input array is ‘n’, so the index will always lie between ‘0’ and ‘n-1’. 
// The sum can take any value between ‘0’ and ‘sum’. Therefore we take the dp array as dp[n][sum+1].
/*
class Solution {
public:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0)     // If the target sum is 0, we have found a subset
            return true;
            
        if(ind == 0)        // If we have reached the first element in 'nums'
            return nums[0] == target;
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
       
        bool notTaken = solve(ind-1, target, nums, dp);   // taking the current element into the subset

        bool taken = false;  // taking the current element into the subset if it doesn't exceed the target
        if(nums[ind] <= target)
            taken = solve(ind-1, target - nums[ind], nums, dp);

        return dp[ind][target] = notTaken || taken;  // Store the result in the dp array to avoid recomputation
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0; i < n; i++){
            totSum += nums[i];
        }

        if(totSum % 2 == 1){   // If the total sum is odd, it cannot be partitioned into two equal subsets
            return false;
        }
        else{
            int target = totSum / 2;

            // Create a DP table with dimensions n x target+1 and initialize with -1
            vector<vector<int>> dp(n, vector<int>(target+1, -1)); 

            return solve(n-1, target, nums, dp);  // Call the solve function to check if it's possible to partition
        }
    }
};
*/


// M-3) DP - Tabulation
// T.C: O(N*k) as there are two nested loops
// S.C: O(N*k) as we are using an external array of size 'N*k'. Stack Space is eliminated.
class Solution{   
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = 0;
        for(int i = 0; i < n; i++){
            totSum += nums[i];
        }

        if(totSum % 2 == 1){   // If the total sum is odd, it cannot be partitioned into two equal subsets
            return false;
        }
        else{
            int k = totSum / 2;

            // Create a DP table with dimensions n x k+1 and initialize with -1
            vector<vector<bool>> dp(n, vector<bool>(k+1, false)); 

            // Base case: If k is 0, we can always achieve it by taking no elements
            for(int i = 0; i < n; i++){
                dp[i][0] = true;
            }
        
            if(nums[0] <= k) 
                dp[0][nums[0]] = true;

            for(int ind = 1; ind < n; ind++){
                for(int target = 1; target <= k; target++){
                    // If we don't take the current element, the result is the same as the previous row
                    bool notTaken = dp[ind-1][target];

                    // If we take the current element, subtract its value from the target and check the previous row
                    bool taken = false;
                    if(nums[ind] <= target){
                        taken = dp[ind-1][target - nums[ind]];
                    }

                    dp[ind][target] = notTaken || taken;
                }
            }

            return dp[n-1][k];    // The final result is stored in dp[n-1][k]
        }
    }
};


// M-4) DP - Space Optmization in Tabulation
// T.C: O(N*k) as there are two nested loops
// S.C: O(k) as we are using an external array of size 'k+1' to store only one row.
/*
class Solution{   
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = 0;
        for(int i = 0; i < n; i++){
            totSum += nums[i];
        }

        if(totSum % 2 == 1){   // If the total sum is odd, it cannot be partitioned into two equal subsets
            return false;
        }
        else{
            int k = totSum / 2;

            vector<bool> prev(k + 1, false);   // Initialize a vector 'prev' to store the previous row of the DP table
    
            prev[0] = true;   // Base case: If k is 0, we can always achieve it by taking no elements
    
            if(nums[0] <= k){  // Base case: If the first element of 'nums' is less than or equal to 'k', set prev[nums[0]] to true
                prev[nums[0]] = true;
            }
    
            for(int ind = 1; ind < n; ind++){
                vector<bool> curr(k + 1, false);   // Initialize a new row 'curr' to store the current state of the DP table
        
                curr[0] = true;   // Base case: If k is 0, we can achieve it by taking no elements

                for(int target = 1; target <= k; target++){
                    bool notTaken = prev[target];  // If we don't take the current element, the result is the same as the previous row
            
                    bool taken = false;   // If we take the current element, subtract its value from the target and check the previous row
                    if (nums[ind] <= target) {
                        taken = prev[target - nums[ind]];
                    }

                    curr[target] = notTaken || taken;   // Store the result in the current DP table row for the current subproblem
                }

                prev = curr;    // Update 'prev' with the current row 'cur' for the next iteration
            }
        
            return prev[k];   // The final result is stored in prev[k]
        }
    }
};
*/
// M-1) DP - Memoization (top-down approach)
// T.C: O(n), The overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).
// S.C: O(n), We are using a recursion stack space(O(N)) and an array (again O(N)). 
// We define f(ind) as : Maximum sum of the subsequence (of non-adjacent elements) starting from index 0 to index ind. We need to return f(n-1) as our final answer.
// If we pick an element then, pick = arr[ind] + f(ind-2). The reason we are doing f(ind-2) is because we have picked the current index element so we need to pick a non-adjacent element so we choose the index ‘ind-2’ instead of ‘ind-1’.
// Next we need to ignore the current element in our subsequence. So nonPick= 0 + f(ind-1). As we don’t pick the current element, we can consider the adjacent element in the subsequence.
// Base Conditions: If ind=0, then we know to reach at index=0, we would have ignored the element at index = 1. Therefore, we can simply return the value of arr[ind] and consider it in the subsequence.
// If ind<0, this case can hit when we call f(ind-2) at ind=1. In this case we want to return to the calling function so we simply return 0 so that nothing is added to the subsequence sum.
/*
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return nums[0];   // this means we have not picked nums[1]
        if(i < 0) return 0;   // when we call f(i-2) at i=1

        if(dp[i] != -1) return dp[i];  

        int pick = nums[i] + solve(i-2, nums, dp);     // solve(i-2, nums, dp) returns sum of non-adjacent elements till (i-2)th index
        int nonPick = 0 + solve(i-1, nums, dp);   // solve(i-1, nums, dp) returns sum of non-adjacent elements till (i-1)th index

        return dp[i] = max(pick, nonPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);   // stores sum of non-adjacent elements till i-th index for each indices
        return solve(n-1, nums, dp);   // Start solving from the last element (we need to reach last element)
    }
};
*/


// M-2) DP - Tabulation (bottom-up approach)
// T.C: O(n), we are running a simple iterative loop
// S.C: O(n), we are using an external array of size ‘n+1’.
// Calculate the maximum value by either picking the current element or not picking it (i.e., taking the maximum of dp[i-2] + arr[i] and dp[i-1])
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);   // stores sum of non-adjacent elements till i-th index for each indices
        dp[0] = nums[0];

        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1)
                pick += dp[i-2];
            
            int nonPick = 0 + dp[i-1];
        
            dp[i] = max(pick, nonPick);
        }
    
        return dp[n-1];    // The last element of the dp array will contain the maximum sum
    }
};
*/


// M-3) DP - Tabulation with Space Optimization(bottom-up approach)
// T.C: O(n), we are running a simple iterative loop.
// S.C: O(1), we are not using any extra space.
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];   // Initialize the maximum sum ending at the previous element
        int prev2 = 0;       // Initialize the maximum sum ending two elements ago
    
        for(int i = 1; i < n; i++){
            int pick = nums[i];  // Maximum sum if we pick the current element
            if (i > 1)
                pick += prev2;  // Add the maximum sum two elements ago
        
            int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
            int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
            prev2 = prev;   // Update the maximum sum two elements ago
            prev = cur_i;   // Update the maximum sum ending at the previous element
        }
    
        return prev;  // Return the maximum sum
    }
};

// M-1.1) DP - Memoization
// Same as GFG - Partitions with Given Difference (Count Partitions with Given Diff)
// T.C: O(n*target), there are  states therefore at max 'n*target' new problems will be solved.
// S.C: O(n*target) + O(n), we are using a recursion stack space(O(n)) and a 2D array (O(n*target)).
/*
class Solution {
public:
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == 0){    // nums contains 0s, hence travel to 0-th index even if target becomes 0 in between
            if(target == 0 && nums[0] == 0)
                return 2;       // Two ways to partition: include or exclude the element
            if(target == 0 || target == nums[0])
                return 1;       // One way to partition
            return 0;           // No way to partition
        }
    
        if (dp[ind][target] != -1)
            return dp[ind][target];
        
        int notTaken = solve(ind-1, target, nums, dp);

        int taken = 0;
        if (nums[ind] <= target)
            taken = solve(ind-1, target-nums[ind], nums, dp);
        
        return dp[ind][target] = notTaken + taken; 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        int s2 = (totSum - target)/2;   // s1 + s2 = totSum, s1 - s2 = target
        if(totSum - target < 0)    // Checking for edge cases (s2 must be an integer)
            return 0;       
        if((totSum - target) % 2 == 1)   // The difference between the total sum and target sum must be even
            return 0; 
    
        vector<vector<int>> dp(n, vector<int>(s2+1, -1)); // Initialize DP table
        // f(ind, target) --> returns no. of subsequences from index 0 to ind that sum upto target
        return solve(n-1, s2, nums, dp);   // s2 is the new target
    }
};
*/

// M-1.2) DP - Memoization
// T.C: O(n * 2*sum(nums)), where n is the size of the nums array and sum(nums) is the total sum of the array.
// S.C: O(n * 2 * sum(nums)) + O(n) for recursion stack.
// Edge Case: -1000 <= target <= 1000
// M-1.2 --> uses unordered_map<string, int>& dp to handle negative target values.
// M-1.3 --> since target is negative, in the dp[ind][target], the possible target values range from -sum to +sum. (sum = sum of nums array).
/*
class Solution{
public:
    int solve(int i, int target, vector<int>& nums, unordered_map<string, int>& dp){
        if(i == 0){
            if(target == 0 && nums[0] == 0)
                return 2;   // Two ways to partition: include or exclude the element
            if(target == nums[0] || target == -nums[0])    // don't write if(target == 0) return 1, as we cannot exclude element
                return 1;    // One way to partition: include or exclude the element
            return 0;    // No way to partition
        }

        string key = to_string(i) + "," + to_string(target);
        if (dp.find(key) != dp.end())
            return dp[key];

        int add = solve(i-1, target - nums[i], nums, dp);
        int subtract = solve(i-1, target + nums[i], nums, dp);
        
        return dp[key] = add + subtract;  // gives total no. of ways
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // key(string) stores [ind, target] pair and value(int) stores no. of subsequences from index 0 to ind that sum upto target
        unordered_map<string, int> dp;   
        
        return solve(n-1, target, nums, dp);
    }
};
*/


// M-1.3) DP - Memoization
// T.C: O(n * 2*sum(nums)), where n is the size of the nums array and sum(nums) is the total sum of the array.
// S.C: O(n * 2 * sum(nums)) + O(n) for recursion stack.
// Edge Case: -1000 <= target <= 1000
// M-1.2 --> uses unordered_map<string, int>& dp to handle negative target values.
// M-1.3 --> since target is negative, in the dp[ind][target], the possible target values range from -sum to +sum. (sum = sum of nums array).
// Shift the target by an offset to handle negative values. The offset will be equal to the sum of all elements in the nums array (sum), as the possible target values range from -sum to +sum.
// Allocate the dp array size as n x (2*sum + 1) to account for all possible target values.
// Adjust the target in recursive calls and during memoization to ensure that negative indices are properly handled.
class Solution {
public:
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp, int offset) {
        if(i == 0) {
            if(target == 0 && nums[0] == 0)
                return 2;  // Two ways to partition: include or exclude the element
            if(target == nums[0] || target == -nums[0])
                return 1;  // One way to partition
            return 0;  // No way to partition
        }

        if(target + offset < 0 || target + offset >= dp[0].size())
            return 0;

        if(dp[i][target+offset] != -1)   // Memoization check with shifted index for negative targets
            return dp[i][target+offset];

        int add = solve(i-1, target - nums[i], nums, dp, offset);
        int subtract = solve(i-1, target + nums[i], nums, dp, offset);
        
        return dp[i][target + offset] = add + subtract;  // Store the result in dp array with shifted index
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) 
            sum += num;
        
        if(abs(target) > sum)   // If the target is out of possible range, no solution exists
            return 0;
        
        int offset = sum;  // Shifted target offset to handle negative indices
        
        vector<vector<int>> dp(n, vector<int>(2*sum + 1, -1));  // DP array size should be n x (2*sum + 1) to handle all possible target values
        
        return solve(n-1, target, nums, dp, offset);
    }
};


// M-2.1) DP - Tabulation
// Same as GFG - Partitions with Given Difference (Count Partitions with Given Diff)
// T.C: O(n*target), there are two nested loops
// S.C: O(n*target), we are using an external array of size 'n*target'. Stack Space is eliminated.
/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        int s2 = (totSum - target)/2;   // s1 + s2 = totSum, s1 - s2 = target
        if(totSum - target < 0)    // Checking for edge cases (s2 must be an integer)
            return 0;       
        if((totSum - target) % 2 == 1)   // The difference between the total sum and target sum must be even
            return 0; 

        vector<vector<int>> dp(n, vector<int>(s2+1, 0));  // target now is s2
        
        for(int ind=0; ind < n; ind++){   // Base case: If the target is 0, there is one valid subset (the empty subset)
            dp[ind][0] = 1;
        }
       
        if(nums[0] <= s2)   // Initialize the first row based on the first element of the array
            dp[0][nums[0]] = 1;
        
        if(nums[0] == 0) // Special handling for the case when the first element is 0
            dp[0][0] = 2;  // Two ways: include or exclude 0
        
        for(int ind=1; ind<n; ind++){
            for(int target = 0; target <= s2; target++){   // Start from 0 to handle the zero sum case
                int notTaken = dp[ind-1][target];
                
                int taken = 0;
                if(nums[ind] <= target)
                    taken = dp[ind-1][target - nums[ind]];
                    
                dp[ind][target] = taken + notTaken;
            }
        }
        
        return dp[n-1][s2];
    }
};
*/

// M-2.2) DP - Tabulation
// T.C: O(n*target), there are two nested loops
// S.C: O(n*target), we are using an external array of size 'n*target'. Stack Space is eliminated.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) 
            sum += num;
        
        if(abs(target) > sum)   // If the target is out of possible range, no solution exists
            return 0;

        int offset = sum;  // Shifted target offset to handle negative indices
        int totalRange = 2*sum + 1; // Range of possible target values is from -sum to +sum

        vector<vector<int>> dp(n, vector<int>(totalRange, 0));  // DP table of size n x (2*sum + 1)

        
        if(nums[0] == 0){   // Base case: handle the first element
            dp[0][offset] = 2;  // +0 and -0 both valid
        } 
        else{
            dp[0][offset + nums[0]] = 1;  // +nums[0]
            dp[0][offset - nums[0]] = 1;  // -nums[0]
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < totalRange; ++j) {
                if (dp[i-1][j] != 0){
                    int addIdx = j + nums[i];
                    int subtractIdx = j - nums[i];
                    if(addIdx < totalRange)
                        dp[i][addIdx] += dp[i-1][j];
                    if(subtractIdx >= 0)
                        dp[i][subtractIdx] += dp[i-1][j];
                }
            }
        }

        return dp[n-1][target + offset];
    }
};

   
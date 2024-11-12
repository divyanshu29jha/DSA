// M-3) DP - Tabulation with Space Optimization(bottom-up approach)
// T.C: O(n), we are running a simple iterative loop.
// S.C: O(1), we are not using any extra space.
// House[0] and House[n-1] are adjacent, they cannot be robbed together. Now proceed as 198. House Robber.
class Solution {
public:
    int solve(vector<int>& nums){
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

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];

        vector<int> temp1;    // contains elements from index 1 to (n-1)
        vector<int> temp2;    // contains elements from index 0 to (n-2)
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
    
        int ans1 = solve(temp1);   // skips 0-th index
        int ans2 = solve(temp2);   // skips last index
    
        return max(ans1,ans2);
    }
};


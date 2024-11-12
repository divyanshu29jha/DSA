// Approach-1 (Using simple recursion to find subsets)
// T.C : O(2^n), S.C : O(1)
/*
class Solution {
public:
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr){
        if(idx == nums.size()){
            if(currOr == maxOr)
                return 1;    //  Found one subset
            return 0;
        }

        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr);
        int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr);

        return takeCount + notTakeCount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int num : nums){
            maxOr |= num;
        }

        int currOr = 0;
        int idx = 0;
        return countSubsets(idx, currOr, nums, maxOr);
    }
};
*/


// Approach-2 (Memoizing to store subproblems result)
// T.C : O(n*maxOr), S.C : O(1)
class Solution {
public:
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr, vector<vector<int>>& dp){
        if(idx == nums.size()) {
            if(currOr == maxOr)
                return dp[idx][currOr] = 1;   // Found one subset
            return dp[idx][currOr] = 0;
        }

        if(dp[idx][currOr] != -1) 
            return dp[idx][currOr];

        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr, dp);
        int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr, dp);

        return dp[idx][currOr] = takeCount + notTakeCount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for(int &num : nums){
            maxOr |= num;
        }

        vector<vector<int>> dp(n+1, vector<int>(maxOr+1, -1));
        int idx = 0;
        int currOr = 0;
        return countSubsets(idx, currOr, nums, maxOr, dp);
    }
};




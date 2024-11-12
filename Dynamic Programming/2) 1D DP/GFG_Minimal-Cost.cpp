// M-1) DP - Memoization (top-down approach)
// T.C: O(N*K), The overlapping subproblems will return the answer in constant time. Therefore the total number of new subproblems we solve is ‘n’. At every new subproblem, we are running another loop for K times. Hence total time complexity is O(N * K).
// S.C: O(N), we are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
/*
class Solution {
  public:
    int solve(int idx, vector<int>& arr, vector<int>& dp, int k){
        if(idx == 0)  return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int minSteps = INT_MAX;
        for(int j = 1; j <= k; j++){   // Loop to try all possible jumps from '1' to 'k'
            if(idx - j >= 0){   // Ensure that we do not jump beyond the beginning of the array
                int jump = solve(idx-j, arr, dp, k) + abs(arr[idx] - arr[idx-j]);
                minSteps = min(jump, minSteps);
            }
        }
    
        return dp[idx] = minSteps;  // Store the minimum cost for this index in the dp array and return it.
    }
    
    int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(n-1, arr, dp, k);   // we need to reach idx (n-1) as 0-based indexing
    }
};
*/


// M-2) DP - Tabulation (bottom-up approach)
// T.C: O(N*K), We are running two nested loops, where outer loops run from 1 to n-1 and the inner loop runs from 1 to K
// S.C: O(N), We are using an external array of size ‘n’.
class Solution {
  public:
    int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        
        for(int i = 1; i < n; i++){   // Loop through the array to fill in the dp array
            int minSteps = INT_MAX;
    
            for(int j = 1; j <= k; j++){    // Loop to try all possible jumps from '1' to 'k'
                if(i - j >= 0){
                    int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                    minSteps = min(jump, minSteps);
                }
            }
            dp[i] = minSteps;
        }
        
        return dp[n-1];   // The result is stored in the last element of dp
    }
};
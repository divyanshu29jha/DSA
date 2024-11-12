// M-1.1) Memoization --> My way
// T.C: O(N*N*N), at max, there will be N*N calls of recursion to solve a new problem, and we are running for-loop of size n.
// S.C: O(N) + O(N*N), we are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*N’.
/*
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i == n-1)    // last row
            return matrix[i][j];

        if(dp[i][j] != -1e9)
            return dp[i][j];
        
        int down = matrix[i][j] + solve(i+1, j, n, matrix, dp);
        
        int diagLeft = matrix[i][j];
        if(j > 0) diagLeft += solve(i+1, j-1, n, matrix, dp);
        else diagLeft +=  1e9;

        int diagRight = matrix[i][j];
        if(j < n-1) diagRight += solve(i+1, j+1, n, matrix, dp);
        else diagRight += 1e9;

        return dp[i][j] = min({down, diagLeft, diagRight});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        // initialize with -1e9 since matrix has negative nos., sometimes path sum can be -1 or 0
        vector<vector<int>> dp(n, vector<int>(n,-1e9));    
        
        vector<int> ans(n);
        for(int j=0; j<n; j++){
            ans[j] = solve(0, j, n, matrix, dp);   // 0-th row and all columns
        }
        return *min_element(ans.begin(), ans.end());        
    }
};
*/

// M-1.2) Memoization --> Striver
// T.C: O(N*N), at max, there will be N*N calls of recursion to solve a new problem.
// S.C: O(N) + O(N*N), we are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*N’.
/*
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j < 0 || j >= n)   // Base Conditions
            return 1e9; // A very large value to represent an invalid path
    
        if(i == 0)
            return matrix[0][j];    // The maximum path sum for the top row is the value itself
    
        if (dp[i][j] != -1e5)
            return dp[i][j];    // If the result for this cell is already calculated, return it
    
        int up = matrix[i][j] + solve(i-1, j, n, matrix, dp);
        int leftDiagonal = matrix[i][j] + solve(i-1, j-1, n, matrix, dp);
        int rightDiagonal = matrix[i][j] + solve(i-1, j+1, n, matrix, dp);
    
        return dp[i][j] = min({up, leftDiagonal, rightDiagonal});    // Store the minimum of the three paths in dp
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows in the matrix
        vector<vector<int>> dp(n, vector<int>(n, -1e5)); // Memoization table to store computed results
    
        int mini = INT_MAX; // Initialize the minimum path sum to a very small value
    
        // Iterate through each cell in the first row to find the maximum path sum starting from each of them
        for (int j = 0; j < n; j++) {
            int ans = solve(n-1, j, n, matrix, dp); // Calculate the minimum path sum for the last row
            mini = min(mini, ans); // Update the minimum path sum if a larger one is found
        }
    
        return mini;    // Return the minimum path sum      
    }
};
*/


// M-2) Tabulation --> Striver
// T.C: O(N*N), there are two nested loops
// S.C: O(N*N), we are using an external array of size ‘N*N’. The stack space will be eliminated.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();      
        vector<vector<int>> dp(n, vector<int>(n, -1e5)); 

        for(int j = 0; j < n; j++) {   // Initialize the first row of dp with values from the matrix (base condition)
            dp[0][j] = matrix[0][j];
        }

    
        for(int i = 1; i < n; i++){    // Iterate through the matrix rows starting from the second row
            for(int j = 0; j < n; j++){
                int up = matrix[i][j] + dp[i-1][j];

                int leftDiagonal = matrix[i][j];
                if(j > 0) leftDiagonal += dp[i-1][j-1];
                else leftDiagonal += 1e9;   // A very large value to represent an invalid path
            
                int rightDiagonal = matrix[i][j];
                if(j < n-1) rightDiagonal += dp[i-1][j+1];
                else rightDiagonal += 1e9;     // A very large value to represent an invalid path
            
                dp[i][j] = min({up, leftDiagonal, rightDiagonal});
            }
        }

        // Find the minimum value in the last row of dp, which represents the minimum path sums ending at each cell
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n-1][j]);
        }

        return mini;    // The minimum path sum is the minimum value in the last row
    }
};


// M-3) Space Optmization in Tabulation --> Striver
// T.C: O(N*N), there are two nested loops
// S.C: O(N), we are using an external array of size ‘N’ to store only one row.
/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();      
        vector<int> prev(n, 0); // Represents the previous row's minimum path sums
        vector<int> curr(n, 0);  // Represents the current row's minimum path sums

        for(int j = 0; j < n; j++) {   // Initialize the first row of dp with values from the matrix (base condition)
            prev[j] = matrix[0][j];
        }

    
        for(int i = 1; i < n; i++){    // Iterate through the matrix rows starting from the second row
            for(int j = 0; j < n; j++){
                int up = matrix[i][j] + prev[j];

                int leftDiagonal = matrix[i][j];
                if(j > 0) leftDiagonal += prev[j-1];
                else leftDiagonal += 1e9;   // A very large value to represent an invalid path
            
                int rightDiagonal = matrix[i][j];
                if(j < n-1) rightDiagonal += prev[j+1];
                else rightDiagonal += 1e9;     // A very large value to represent an invalid path
            
                curr[j] = min({up, leftDiagonal, rightDiagonal});  // Store the maximum of the three paths in the current row
            }

            prev = curr;
        }

        // Find the minimum value in the last row of dp, which represents the minimum path sums ending at each cell
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, prev[j]);
        }

        return mini;    // The minimum path sum is the minimum value in the last row
    }
};
*/
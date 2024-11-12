// M-1) Recursion --> TLE
// T.C: O(2^(m+n)), since there are two choices (up or left) at each step, and there are (m-1 + n-1) steps to reach the top-left corner from the bottom-right, the number of recursive calls is approximately O(2^(m+n)).
// S.C: O(2^(m+n)) since the ans vector stores all possible path sums, which can contain up to O(2^(m+n)) elements in the worst case. Also, O(m+n) for recursion stack as the maximum depth of the recursion stack corresponds to the longest path in the grid, which is (m-1 + n-1) steps. 
/*
class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& grid, int sum, vector<int>& ans){  
        if(i == 0 && j == 0){       // Base case: If we reach the top-left corner (0, 0)
            // ans.push_back(sum);  // wrong: value grid[i][j] is not included in the sum when the path reaches the top-left corner
            ans.push_back(sum + grid[i][j]);  
            return;
        }
        
        if(i < 0 || j < 0)   // If we go out of bounds or reach a blocked cell
            return;    

        solve(i-1, j, grid, sum + grid[i][j], ans);    // either move up 
        solve(i, j-1, grid, sum + grid[i][j], ans);    // or move left
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans;
        int sum = 0;
        solve(m-1, n-1, grid, sum, ans);

        return *min_element(ans.begin(), ans.end()); // Find the minimum path sum
    }
};
*/


// M-2) DP - Memoization
// T.C: O(M*N), at max, there will be M*N calls of recursion.
// S.C: O((M-1)+(N-1)) + O(M*N), we are using a recursion stack space: O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘M*N’.
// NOTE: dp[i][j] represents the minimum path sum for each cell to reach grid[0][0]
/*
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){  
        if(i == 0 && j == 0)    // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            return grid[i][j];
        
        if(i < 0 || j < 0)      // If we go out of bounds, return a large value to avoid considering this path
            return 1e5;     // Don't use INT_MAX, as it can lead to integer overflow when added to grid[i][j] while finding up & left

        if (dp[i][j] != -1)     // If the result is already computed, return it
            return dp[i][j]; 

        // Calculate the minimum sum path by considering moving up and moving left
        int up = grid[i][j] + solve(i-1, j, grid, dp);   
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);  // Store the result in the DP table and return it
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        return solve(m-1, n-1, grid, dp);
    }
};
*/  


// M-3.1) DP - Tabulation
// T.C: O(M*N), there are two nested loops.
// S.C: O(M*N), we are using an external array of size M*N.
// NOTE: dp[i][j] represents the minimum path sum for each cell to reach grid[m-1][n-1]
/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int up = 1e5;     // for i = 0 i.e first row
                if(i > 0)
                    up = grid[i][j] + dp[i-1][j];
                
                int left = 1e5;   // for j = 0  i.e first column
                if(j > 0)
                    left = grid[i][j] + dp[i][j-1]; 

                dp[i][j] = min(up, left);
            }
        }

        return dp[m-1][n-1];
    }
};
*/

// M-3.2) DP - Tabulation --> Striver
// T.C: O(M*N), there are two nested loops.
// S.C: O(M*N), we are using an external array of size M*N.
// NOTE: dp[i][j] represents the minimum path sum for each cell to reach grid[m-1][n-1]
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
                else{
                    int up = grid[i][j];
                    if (i > 0)
                        up += dp[i-1][j]; // Include the minimum path sum from above
                    else
                        up += 1e9;   // A large value if moving up is not possible (out of bounds)

                    int left = grid[i][j];
                    if (j > 0)
                        left += dp[i][j-1]; // Include the minimum path sum from the left
                    else
                        left += 1e9;   // A large value if moving left is not possible (out of bounds)

               
                    dp[i][j] = min(up, left);    // Store the minimum path sum in dp[i][j]
                }
            }
        }

        return dp[m-1][n-1];
    }
};


// M-4) DP - Space optimization in Tabulation
// T.C: O(M*N), there are two nested loops.
// S.C: O(N), ee are using an external array of size ‘N’ to store only one row.
// NOTE: dp[i][j] represents the minimum path sum for each cell to reach grid[m-1][n-1]
/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);   // n cols

        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);     // Initialize a temporary vector for the current row
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0)
                    curr[j] = grid[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
                else{
                    int up = grid[i][j];   
                    if (i > 0)
                        up += prev[j]; // Include the minimum path sum from above (previous row)
                    else
                        up += 1e9; // A large value if moving up is not possible (out of bounds)

                    int left = grid[i][j];
                    if (j > 0)
                        left += curr[j - 1]; // Include the minimum path sum from the left (current row)
                    else
                        left += 1e9; // A large value if moving left is not possible (out of bounds)

                    curr[j] = min(up, left);  // Store the minimum path sum in curr[j]
                }
            }
            
            prev = curr;    // Update the previous row with the current row
        }

        return prev[n - 1];  // The final result is stored in prev[n-1], which represents the destination in the last column
    }
};
*/

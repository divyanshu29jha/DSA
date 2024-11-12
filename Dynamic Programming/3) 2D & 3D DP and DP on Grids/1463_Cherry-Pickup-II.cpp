// M-1) DP - Memoization
// T.C: O(N*M*M) * 9, At max, there will be N*M*M calls of recursion to solve a new problem and in every call, two nested loops together run for 9 times.
// S.C: O(N) + O(N*M*M), we are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M*M’.
// f(i,j1,j2) will give us the maximum number of chocolates collected by Alice from cell[i][j1] and Bob from cell[i][j2] till the last row. 
/*
class Solution {
public:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)   // Check if the positions (j1, j2) are valid
            return -1e9; // A very large negative value to represent an invalid position

        if(i == n - 1){     // Base case: If we are at the last row, return the chocolate at the positions (j1, j2)
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)    // If the result for this state is already computed, return it
            return dp[i][j1][j2];

        int maxi = INT_MIN;
        for(int di = -1; di <= 1; di++){   // Try all possible moves (up, left, right) for both positions (j1, j2)   // O(9)
            for(int dj = -1; dj <= 1; dj++){
                int ans;
            
                if (j1 == j2)
                    ans = grid[i][j1] + solve(i+1, j1 + di, j2 + dj, n, m, grid, dp);
                else
                    ans = grid[i][j1] + grid[i][j2] + solve(i+1, j1 + di, j2 + dj, n, m, grid, dp);
            
                maxi = max(maxi, ans);
            }
        }
    
        return dp[i][j1][j2] = maxi;   // Store the maximum result for this state in dp
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();  
        int m = grid[0].size();

        // Create a 3D DP array of size [N][M][M], initialized to -1, to store computed results
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        int i = 0, j1 = 0, j2 = m-1;   
        return solve(i, j1, j2, n, m, grid, dp);
    }
};
*/

// M-2) DP - Tabulation
// T.C: O(N*M*M) * 9, the outer nested loops run for (N*M*M) times and the inner two nested loops run for 9 times..
// S.C: O(N*M*M), we are using an external array of size ‘N*M*M’. The stack space will be eliminated..
// dp[2][0][3] means that we are getting the value of the maximum chocolates collected by Alice and Bob, when Alice is at (2,0) and Bob is at (2,3).
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();  
        int m = grid[0].size();

        // Create a 3D DP array of size [N][M][M], initialized to -1, to store computed results
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        for(int j1 = 0; j1 < m; j1++){   // Initialize the DP array for the last row
            for(int j2 = 0; j2 < m; j2++){
                if (j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
        for(int i = n - 2; i >= 0; i--){
            for(int j1 = 0; j1 < m; j1++){
                for(int j2 = 0; j2 < m; j2++){
                    int maxi = INT_MIN;

                    for(int di = -1; di <= 1; di++){    // Inner nested loops to try out 9 options (diagonal moves)
                        for (int dj = -1; dj <= 1; dj++) {
                            int ans;

                            if (j1 == j2)
                                ans = grid[i][j1];
                            else
                                ans = grid[i][j1] + grid[i][j2];

                            // Check if the move is valid (within the grid boundaries)
                            if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                                ans += -1e9; // A very large negative value to represent an invalid move
                            else
                                ans += dp[i + 1][j1 + di][j2 + dj]; // Include the DP result from the next row

                            maxi = max(ans, maxi); // Update the maximum result
                        }
                    }
                    
                    dp[i][j1][j2] = maxi; // Store the maximum result for this state in the DP array
                }
            }
        }
    
        return dp[0][0][m - 1];  // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    }
};
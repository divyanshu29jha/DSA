// M-1) DP - Memoization (top-down approach)  --> Striver
// T.C: O(M*N), At max, there will be M*N calls of recursion.
// S.C: O((N-1)+(M-1)) + O(M*N), we are using a recursion stack space: O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.
// NOTE: dp[i][j] represents no. of all possible ways to reach obstacleGrid[i][j] starting from obstacleGrid[0][0].
/*
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){  
        // Base cases
        if (i < 0 || j < 0) return 0;   // If we go out of bounds, return 0
        if (obstacleGrid[i][j] == 1) return 0;   // If there's an obstacle at (i, j), return 0  (no way to reach it possible)
        if (i == 0 && j == 0) return 1;     // If we reach the destination (0, 0), return 1
        
        if (dp[i][j] != -1) return dp[i][j];    // If the result is already computed, return it

        int moveUp = solve(i-1, j, dp, obstacleGrid);
        int moveLeft = solve(i, j-1, dp, obstacleGrid);

        return dp[i][j] = moveUp + moveLeft;   // Store the result in dp[i][j] and return it
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));        
        return solve(m-1, n-1, dp, obstacleGrid);
    }
};
*/


// M-2.1) DP - Tabulation  --> My way
// T.C: O(M*N), there are two nested loops
// S.C: O(M*N), we are using an external array of size ‘M*N’.
// Base case: There's only one way to reach any cell in the first row or first column
// NOTE: dp[i][j] represents no. of all possible ways to reach obstacleGrid[i][j] starting from obstacleGrid[0][0].
/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 1){
                dp[i][0] = 0;   
                break;         // rest all dp[i][0] are already initialized to 0
            } 
            dp[i][0] = 1;  // Only one way to reach any cell in the first column
        }
        
        for(int j = 0; j < n; j++){
            if(obstacleGrid[0][j] == 1){
                dp[0][j] = 0;   
                break;     // rest all dp[0][j] are already initialized to 0
            }
            dp[0][j] = 1;  // Only one way to reach any cell in the first row
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // The number of ways to reach dp[i][j] is the sum of the ways to reach
                // the cell directly above it (dp[i-1][j]) and the cell directly to the left of it (dp[i][j-1])
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] == 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];   // The bottom-right corner will contain the number of unique paths
    }
};
*/

// M-2.2) DP - Tabulation  --> Striver
// T.C: O(M*N), there are two nested loops
// S.C: O(M*N), we are using an external array of size ‘M*N’.
// Base case: There's only one way to reach any cell in the first row or first column
// NOTE: dp[i][j] represents no. of all possible ways to reach obstacleGrid[i][j] starting from obstacleGrid[0][0].
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
             
        for(int i=0 ; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                    continue;
                }

                if(i == 0 && j == 0){  // Base condition: If we are at the top-left cell (0, 0), there is one way.
                    dp[i][j] = 1;
                    continue;   
                }

                int up = 0;  //  Initialize variables to store the no. of ways from the cell above (up) and left (left).
                int left = 0;
            
                if (i > 0)   // If we are not at the first row (i > 0), update 'up' with the value from the cell above.
                    up = dp[i - 1][j];

                if (j > 0)   // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
                    left = dp[i][j - 1];

                dp[i][j] = up + left;   // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.

                // if(obstacleGrid[i][j] == 1){
                //     dp[i][j] = 0; 
                // } else if(i == 0 && j == 0){ 
                //     dp[i][j] = 1;
                // } else {
                //     int up = (i > 0) ? dp[i - 1][j] : 0;  
                //     int left = (j > 0) ? dp[i][j - 1] : 0;  
                //     dp[i][j] = up + left;  
                // }
            }
        }

        return dp[m - 1][n - 1];   // The result is stored in the bottom-right cell (m-1, n-1)
    }
};


// M-3) DP - Space optimization in tabulation --> Striver
// T.C: O(M*N), there are two nested loops
// S.C: O(M*N), we are using an external array of size ‘N’ to store only one row.
// If we closely look at the relationship, dp[i][j] = dp[i-1][j] + dp[i][j-1]), we see that we only need the previous row and column, in order to calculate dp[i][j]. Therefore we can space optimize it.
// 1. We can take a dummy row (say prev) and initialize it as 0.
// 2. Now the current row (say curr) only needs the previous row value and the current row’s value in order to calculate dp[i][j].
// 3. At the next step, the curr array becomes the prev of the next step and using its values we can still calculate the next row’s values.
// 4. At last prev[n-1] will give us the required answer.
/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);  // Create a vector to represent the previous row of the grid.
    
        for(int i = 0; i < m; i++){  
            vector<int> curr(n, 0);   // Create a temporary vector to represent the current row.
            for(int j = 0; j < n; j++){   // iterate through columns
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                    continue;
                }
                if (i == 0 && j == 0){    // Base case: If we are at the top-left cell (0, 0), there is one way.
                    curr[0] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)   // If we are not at the first row (i > 0), update 'up' with the value from the previous row.
                    up = prev[j];

                if (j > 0)   // If we are not at the first column (j > 0), update 'left' with the value from the current row.
                    left = curr[j - 1];

                curr[j] = up + left;   // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            }

            prev = curr;   // Update the previous row with the values calculated for the current row.
        }

        return prev[n - 1];
             
       
    }
};
*/

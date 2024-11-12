// M-1.1) Recursion --> TLE (return type void)
// T.C: O(2^(m+n)), S.C: O(m+n)
/*
class Solution {
public:
    void solve(int i, int j, int m, int n, int& cnt){   // pass cnt by reference
        if(i == m-1 && j == n-1){ 
            cnt++;
            return;
        }
        
        if(i >= m || j >= n){
            return;
        }

        solve(i+1, j, m, n, cnt);
        solve(i, j+1, m, n, cnt);
    }

    int uniquePaths(int m, int n) {
        int cnt = 0;
        int i = 0, j = 0;
        solve(i, j, m, n, cnt);

        return cnt;
    }
};
*/

// M-1.2) Recursion --> TLE (return type int)
// T.C: O(2^(m+n)), S.C: O(m+n)
/*
class Solution {
public:
    int solve(int i, int j, int m, int n){  
        if(i == m-1 && j == n-1){ 
            return 1;   // count increases
        }
        
        if(i >= m || j >= n){
            return 0;   // count remains same
        }

        int moveRight = solve(i+1, j, m, n);
        int moveDown = solve(i, j+1, m, n);

        return moveRight + moveDown;
    }

    int uniquePaths(int m, int n) {
        int i = 0, j = 0;
        return solve(i, j, m, n);
    }
};
*/

// M-2.1) DP - Memoization (top-down approach)  --> Striver
// T.C: O(M*N), At max, there will be M*N calls of recursion.
// S.C: O((N-1)+(M-1)) + O(M*N), we are using a recursion stack space: O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.
/*
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp){  
        if(i == 0 && j == 0)
            return 1;    // Base case: If we reach the top-left corner (0, 0), there is one way.
        
        if(i < 0 || j < 0)
            return 0;    // If we go out of bounds or reach a blocked cell, there are no ways.

        if(dp[i][j] != -1)
            return dp[i][j];   // Return the precomputed result

        int moveUp = solve(i-1, j, dp);
        int moveLeft = solve(i, j-1, dp);

        return dp[i][j] = moveUp + moveLeft;   // Store the result in dp[i][j] and return it
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));        
        return solve(m-1, n-1, dp);
    }
};
*/

// M-2.2) DP - Memoization  --> My way
// T.C: O(M*N), At max, there will be M*N calls of recursion.
// S.C: O((N-1)+(M-1)) + O(M*N), we are using a recursion stack space: O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.
/*
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp){  
        if(i == m-1 && j == n-1){ 
            return 1;   // Base case: 1 valid path found  // count increases
        }
        
        if(i >= m || j >= n){
            return 0;   // Out of bounds: no valid path   // count remains same
        }

        if(dp[i][j] != 0){
            return dp[i][j];   // Return the precomputed result
        }

        int moveRight = solve(i+1, j, m, n, dp);
        int moveDown = solve(i, j+1, m, n, dp);

        return dp[i][j] = moveRight + moveDown;   // Store the result in dp[i][j] and return it
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int i = 0, j = 0;
        
        return solve(i, j, m, n, dp);
        // solve(i, j, m, n, dp);   // Start solving from the top-left corner
        // return dp[0][0];
    }
};
*/

// M-2.2) DP - Memoization  --> Divyank
/*
class Solution {
public:
    vector<vector<int>>dp;

    int solve(int i, int j, int m, int n){  
        if(i == m-1 && j == n-1){ 
            return 1;   // Base case: 1 valid path found  // count increases
        }
        
        if(i >= m || j >= n){
            return 0;   // Out of bounds: no valid path   // count remains same
        }

        if(dp[i][j] != 0){
            return dp[i][j];   // Return the precomputed result
        }

        int moveRight = solve(i+1, j, m, n);
        int moveDown = solve(i, j+1, m, n);

        return dp[i][j] = moveRight + moveDown;   // Store the result in dp[i][j] and return it
    }

    int uniquePaths(int m, int n) {
        this->dp = vector(m, vector<int>(n, 0));
        int i = 0, j = 0;
        
        return solve(i, j, m, n);
    }
};
*/


// M-3.1) DP - Tabulation  
// T.C: O(M*N), there are two nested loops
// S.C: O(M*N), we are using an external array of size ‘M*N’.
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: There's only one way to reach any cell in the first row or first column
        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;  // Only one way to reach any cell in the first column
        }
        
        for(int j = 0; j < n; j++) {
            dp[0][j] = 1;  // Only one way to reach any cell in the first row
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // The number of ways to reach dp[i][j] is the sum of the ways to reach
                // the cell directly above it (dp[i-1][j]) and the cell directly to the left of it (dp[i][j-1])
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];   // The bottom-right corner will contain the number of unique paths
    }
};
*/

// M-3.2) DP - Tabulation  --> Striver
// T.C: O(M*N), there are two nested loops
// S.C: O(M*N), we are using an external array of size ‘M*N’.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
             
        for(int i=0 ; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0){  // Base condition: If we are at the top-left cell (0, 0), there is one way.
                    dp[i][j] = 1;
                    continue;   // Skip the rest of the loop and continue with the next iteration.
                }

                int up = 0;  //  Initialize variables to store the no. of ways from the cell above (up) and left (left).
                int left = 0;
            
                if (i > 0)   // If we are not at the first row (i > 0), update 'up' with the value from the cell above.
                    up = dp[i - 1][j];

                if (j > 0)   // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
                    left = dp[i][j - 1];

                dp[i][j] = up + left;   // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            }
        }

        return dp[m - 1][n - 1];   // The result is stored in the bottom-right cell (m-1, n-1).
    }
};


// M-4) DP - Space optimization in tabulation --> Striver
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
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);  // Create a vector to represent the previous row of the grid.
    
        for(int i = 0; i < m; i++){  
            vector<int> curr(n, 0);   // Create a temporary vector to represent the current row.
            for(int j = 0; j < n; j++){   // iterate through columns
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


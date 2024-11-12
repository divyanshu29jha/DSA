// M-1.1) Memoization --> My way
// T.C: O(M*M), since each state (i, j) is calculated once due to memoization, the overall time complexity for filling out the DP table is O(M^2).
// S.C: O(M*M), The dp table is a 2D vector of size M*M, so it takes M^2 space. The recursion stack depth can go up to m (the height of the triangle), so the stack space is O(M).
/*
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i == 0 && j == 0)
            return triangle[i][j];
    
        if (j < 0 || j > i)  // Invalid index for a triangle
            return 1e5;    

        if(dp[i][j] != -1)     
            return dp[i][j];    

        int up = triangle[i][j] + solve(i-1, j, triangle, dp);   
        int diag = triangle[i][j] + solve(i-1, j-1, triangle, dp);

        return dp[i][j] = min(up, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();   // m rows
        vector<vector<int>> dp(m, vector<int>(m, -1));  // Initialize dp with -1

        vector<int> ans(m, 0);  // m elements in last row
        for(int col=0; col<m; col++){
            ans[col] = solve(m-1, col, triangle, dp);   // (m-1)th row
        } 
        return *min_element(ans.begin(), ans.end());  
    }
};
*/

// M-1.2) Memoization --> Striver
// T.C: O(M*M), since each state (i, j) is calculated once due to memoization, the overall time complexity for filling out the DP table is O(M^2).
// S.C: O(M*M), The dp table is a 2D vector of size M*M, so it takes M^2 space. The recursion stack depth can go up to m (the height of the triangle), so the stack space is O(M).
// We can define f(i,j) such that it gives us the minimum path sum from the cell [i][j] to the last row.
/*
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, int m, vector<vector<int>>& dp){
        if(i == m-1)     // If we're at the bottom row, return the value of the current cell
            return triangle[i][j];
        
        if(dp[i][j] != -1)         
            return dp[i][j];
        
        // Calculate the sum of two possible paths: going down and going diagonally
        int down = triangle[i][j] + solve(i+1, j, triangle, m, dp);
        int diagonal = triangle[i][j] + solve(i+1, j+1, triangle, m, dp);

        return dp[i][j] = min(down, diagonal);  // Store the minimum of the two paths in the dp table and return it
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();   // m rows
        vector<vector<int>> dp(m, vector<int>(m, -1));  // Initialize dp with -1 (m rows, m columns)
        int i=0, j=0;
        return solve(i, j, triangle, m, dp);
    }
};
*/


// M-2.1) Tabulation --> My way 
// T.C: O(M*M), there are two nested loops
// S.C: O(M*M), We are using an external array of size ‘M*M’. The stack space will be eliminated.
/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();   // m rows
        vector<vector<int>> dp(m, vector<int>(m, -1));  // Initialize dp with -1 (m rows, m columns)
        
        for(int i = 0; i < m ; i++){     // Fill the DP table from the second row onwards
            for(int j = 0; j <= i; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = triangle[i][j]; 
                else{
                    int up = triangle[i][j];
                    if (j < i)      // To avoid out of bounds, only add from directly above
                        up += dp[i-1][j]; 
                    else
                        up += 1e9;   // A large value if moving up is not possible (out of bounds)

                    int diag = triangle[i][j];
                    if (j > 0)
                        diag += dp[i-1][j-1]; // Include the minimum path sum from the diagonally up-left
                    else
                        diag += 1e9;   // A large value if moving diagonally up-left is not possible (out of bounds)

                    dp[i][j] = min(up, diag);    // Store the minimum path sum in dp[i][j]
                }
            }
        }

        int minPath = 1e9;
        for(int j = 0; j < m; j++){
            minPath = min(minPath,dp[m-1][j]);
        }
        return minPath;
    }
};
*/

// M-2.2) Tabulation --> Striver 
// T.C: O(M*M), there are two nested loops
// S.C: O(M*M), we are using an external array of size ‘M*M’. The stack space will be eliminated.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();   // m rows
        vector<vector<int>> dp(m, vector<int>(m, -1));  // Initialize dp with -1 (m rows, m columns)
        
        for(int j = 0; j < m; j++){   // Initialize the bottom row of dp with the values from the triangle
            dp[m-1][j] = triangle[m-1][j];
        }

        for(int i = m-2; i >= 0; i--) {   // Iterate through the triangle rows in reverse order
            for(int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i+1][j];   // Calculate the minimum path sum for the current cell
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);  // Store the minimum of the two possible paths in dp
            }
        }

        return dp[0][0];  // The top-left cell of dp now contains the minimum path sum
    }
};


// M-3) Space optimzation in Tabulation --> Striver 
// T.C: O(M*M), there are two nested loops
// S.C: O(M), we are using an external array of size ‘M’ to store only one row.
/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();   // m rows
        vector<vector<int>> dp(m, vector<int>(m, -1));  // Initialize dp with -1 (m rows, m columns)
        
        vector<int> prev(m, 0); // Represents the previous row
        vector<int> curr(m, 0);   // Represents the current row
    
        // Initialize the prev array with values from the last row of the triangle
        for (int j = 0; j < m; j++) {
            prev[j] = triangle[m-1][j];
        }
    
        for(int i = m-2; i >= 0; i--){    // Iterate through the triangle rows in reverse order
            for (int j = i; j >= 0; j--){
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j+1];
        
                curr[j] = min(down, diagonal);   // Store the minimum of the two possible paths in the current row
            }
        
            prev = curr;   // Update the prev array with the values from the current row
        }
    
        return prev[0];   // The prev array now contains the minimum path sum from the top to the bottom of the triangle
    }
};
*/
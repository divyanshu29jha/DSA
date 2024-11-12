// T.C: O(m * n * health), S.C: (m * n * health) + O(m * n) + O(m+n), each for dp table, visited matrix and recursion stack.
class Solution {
public:
    bool solve(int i, int j, int m, int n, vector<vector<int>>& grid, int health, vector<vector<bool>>& visited, vector<vector<vector<int>>>& dp){
        if(i < 0 || j < 0 || i >= m || j >= n) 
            return false;

        if(visited[i][j] == true)
            return false;

        if(health <= 0)
            return false;

        if (i == m - 1 && j == n - 1){
            if(grid[m-1][n-1] == 1){
                health--;  
            }
            return health > 0;
        }     

        if(dp[i][j][health] != -1)
            return dp[i][j][health];       

        visited[i][j] = true;     // Mark current cell as visited
        int newHealth = health - grid[i][j];
        bool moveDown = solve(i + 1, j, m, n, grid, newHealth, visited, dp);
        bool moveRight = solve(i, j + 1, m, n, grid, newHealth, visited, dp);
        bool moveUp = solve(i - 1, j, m, n, grid, newHealth, visited, dp);
        bool moveLeft = solve(i, j - 1, m, n, grid, newHealth, visited, dp);
        visited[i][j] = false;    // Unmark the current cell after all directions are processed

        return dp[i][j][health] = moveDown || moveRight || moveUp || moveLeft;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // 3D DP table: dp[i][j][h] represents whether we can reach the target from cell (i, j) with health h
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return solve(0, 0, m, n, grid, health, visited, dp);
    }
};



// WRONG METHOD: once a value is stored in DP table, it will not get updated if we travel from some other path as that cell will get marked as visited. Hence, the same dp[i][j] gets returned even if it is not the min path value.
/*
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp, vector<vector<bool>>& visited){  
        if(i == 0 && j == 0)    // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            return grid[i][j];

        if(i < 0 || j < 0 || i >= m || j >= n)      // If we go out of bounds, return a large value to avoid considering this path
            return 1e5;     // Don't use INT_MAX, as it can lead to integer overflow when added to grid[i][j] while finding up & left

        if(visited[i][j] == true)
            return 1e5;

        if (dp[i][j] != -1)     // If the result is already computed, return it
            return dp[i][j]; 

        visited[i][j] = true;  // Mark current cell as visited
        int up = grid[i][j] + solve(i-1, j, m, n, grid, dp, visited);   
        int left = grid[i][j] + solve(i, j-1, m, n, grid, dp, visited);
        int down = grid[i][j] + solve(i+1, j, m, n, grid, dp, visited);
        int right = grid[i][j] + solve(i, j+1, m, n, grid, dp, visited);
        visited[i][j] = false;   // Unmark the current cell after all directions are processed
        
        return dp[i][j][visited] = min({up, left, down, right});     // Store the result in the DP table and return it
    }
    
    bool findSafeWalk(vector<vector<int>>& grid, int health){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int minPath = solve(m-1, n-1, m, n, grid, dp, visited);
        cout << minPath;
        if(health > minPath)
            return true;
        return false;
    }
};
*/



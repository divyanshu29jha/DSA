// M-1) DP - Memoization (top-down approach) --> Striver
// T.C: O(N*4*3), there are N*4 states and for every state, we are running a for loop iterating three times.
// S.C: O(N) + O(N*4), we are using a recursion stack space(O(N)) and a 2D array (again O(N*4)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
// f(day, last) - max points till given day and last task chosen on previous day 
/*
class Solution {
  public:
    int solve(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if(day == 0){
            int maxi = 0;
            for(int task=0; task<=2; task++){
                if(task !=  last) 
                    maxi = max(maxi, arr[0][task]);
            }
            return dp[day][last] = maxi;  // Store the result in dp array and return it
        }  
        
        if(dp[day][last] != -1) 
            return dp[day][last];
        
        int maxi = 0;
        for(int task=0; task<=2; task++){   // Iterate through the activities for the current day
            if (task != last){
            // Calculate the points for the current activity and add it to the maximum points obtained so far (recursively calculated)
                int points = arr[day][task] + solve(day-1, task, arr, dp);  // task is chosen, so it becomes 'last' for next recursive call
                maxi = max(maxi, points);
            }
        }

        return dp[day][last] = maxi;   // Store the result in dp array and return it   (for first iteration, store in dp[n-1][3])
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // M-1.1)
        vector<vector<int>> dp(n, vector<int>(4, -1));   // Create a memoization table (dp) to store intermediate results
        return solve(n-1, 3, arr, dp);  // Start from the last day with no previous activity (last = 3 indicates any task 0,1,2 can be chosen for last day)
       
        // M-1.2) 
        // vector<vector<int>> dp(n, vector<int>(4, -1));   // Create a memoization table (dp) to store intermediate results
        // solve(n-1, 3, arr, dp);    // do not store the returned value
        // return dp[n-1][3];         // dp[n-1][0], dp[n-1][1], dp[n-1][2] remain -1. dp[n-1][3] contains final ans.
        
        // M-1.3)
        // vector<vector<int>> dp(n, vector<int>(3, -1));
        // return max({solve(n-1, 0, arr, dp), solve(n-1, 0, arr, dp), solve(n-1, 0, arr, dp)}); 
        
        // M-1.4)
        // vector<vector<int>> dp(n, vector<int>(3, -1));
        // solve(n-1, 0, arr, dp);
        // solve(n-1, 1, arr, dp);
        // solve(n-1, 2, arr, dp);
        // return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    } 
};
*/


// M-2.1) DP - Tabulation (bottom-up approach)  --> Striver
// T.C: O(N*4*3), there are three nested loops
// S.C: O(N*4), we are using an external array of size N*4.
/*
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Create a 2D DP table to store the maximum points
        // dp[i][j] represents the maximum points at day i, considering the last activity as j
        vector<vector<int>> dp(n, vector<int>(4, -1));   // Create a memoization table (dp) to store intermediate results
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});
        
        for(int day = 1; day < n; day++){   // Iterate through the days starting from day 1
            for(int last = 0; last < 4; last++){   
                dp[day][last] = 0;
                for(int task = 0; task <= 2; task++){   // Iterate through the tasks for the current day
                    if(task != last){
                        // Calculate the points for the current activity and add it to the
                        // maximum points obtained on the previous day (recursively calculated)
                        int points = arr[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], points);    // Update the maximum points for the current day and last activity
                    }
                }
            } 
        }
        
        return dp[n-1][3];   // The maximum points for the last day with any activity can be found in dp[n-1][3]
    }
};
*/

// M-2.2) DP - Tabulation (bottom-up approach)
/*
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Create a 2D DP table to store the maximum points
        // dp[i][j] represents the maximum points at day i, considering the last activity as j
        vector<vector<int>> dp(n, vector<int>(3, -1));   // Create a memoization table (dp) to store intermediate results
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        
        for(int day = 1; day < n; day++){   // Iterate through the days starting from day 1
            for(int last = 0; last < 3; last++){   
                dp[day][last] = 0;   // last task of previous day
                for(int task = 0; task <= 2; task++){   // Iterate through the tasks for the current day
                    if(task != last){
                        // Calculate the points for the current activity and add it to the
                        // maximum points obtained on the previous day (recursively calculated)
                        int points = arr[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], points);    // Update the maximum points for the current day and last activity
                    }
                }
            } 
        }
        
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};
*/

// M-2.3) DP - Tabulation (bottom-up approach)  --> Divyank
// class Solution {
// public:
// int maximumPoints(vector<vector<int>>& a, int n) {
//         vector<vector<int>>dp(n,vector<int>(3,0));
//         dp[0][0] = a[0][0];   // dp[i][j] represents max points till i-th day and j-th task is now chosen on i-th day
//         dp[0][1] = a[0][1];
//         dp[0][2] = a[0][2];
        
//         for(int i=1; i<n; i++){
//             // dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
//             // dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
//             // dp[i][2] = a[i][2] + max(dp[i-1][0], dp[i-1][1]);
//             for(int j=0; j<3; j++){
//                 for(int k=0; k<3; k++){  // i-th day, j-th task and k iterates through task of previous day
//                     if(j != k)
//                         dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][k]);
//                 }
//             }
//         }
        
//         return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
//     }
// };



// M-3.1) Space optimization in tabulation
// T.C: O(N*4*3), there are three nested loops
// S.C: O(4), We are using an external array of size ‘4’ to store only one row.
class Solution {
public:
int maximumPoints(vector<vector<int>>& a, int n) {
        vector<vector<int>>dp(n,vector<int>(3,0));
        int prev1 = a[0][0];   // dp[i][j] represents max points till i-th day and j-th task is now chosen on i-th day
        int prev2 = a[0][1];
        int prev3 = a[0][2];
        
        for(int i=1; i<n; i++){   // i itertes through day
            int curr1, curr2, curr3;
            curr1 = a[i][0] + max(prev2, prev3);
            curr2 = a[i][1] + max(prev3, prev1);
            curr3 = a[i][2] + max(prev1, prev2);
            
            prev1 = curr1;
            prev2 = curr2;
            prev3 = curr3;
        }
        
        return max({prev1, prev2, prev3});
    }
};

// M-3.2) Space optimization in tabulation
// T.C: O(N*4*3), there are three nested loops
// S.C: O(4), We are using an external array of size ‘4’ to store only one row.
/*
class Solution {
public:
    int maximumPoints(vector<vector<int>>& a, int n) {
        vector<int> prev(3, 0);  // Stores the maximum points for the previous day
        prev[0] = a[0][0];
        prev[1] = a[0][1];
        prev[2] = a[0][2];
        
        for (int i = 1; i < n; i++) {
            vector<int> curr(3, 0);  // Stores the maximum points for the current day
            curr[0] = a[i][0] + max(prev[1], prev[2]);
            curr[1] = a[i][1] + max(prev[0], prev[2]);
            curr[2] = a[i][2] + max(prev[0], prev[1]);
            prev = curr;  // Update prev to current for the next iteration
        }
        
        return max({prev[0], prev[1], prev[2]});
    }
};
*/
















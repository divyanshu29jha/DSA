/*
1. Recursion: each function calls give rise to 2 more: therefore O(2^n)
2. Memoization: stores in an array: O(n). Subproblem results are stored in an array, ensuring that each subproblem is solved only once.
3. Tabulation: iterative approach and takes O(n) for subproblems from the smallest to the largest.

RECURSION: Top-down: We start from answer, go to the base case and then go back.
MEMOIZATION: Top-down:  Avoids redundant calls done in recursion reducing time complexity.
TABULATION IS: Bottom-up: We start from the base case and we try to go to the required answer.
*/

#include <bits/stdc++.h>
using namespace std;

// M-1) Memoization (Top-Down approach): Overlapping subproblem results are stored in an array, ensuring that each subproblem is solved only once.
// T.C: O(N), the overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).
// S.C: O(N), we are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)

int fib(int n, vector<int>& dp){
    if(n <= 1) return n;
    
    if(dp[n] != -1) return dp[n];  // check whether the answer is already calculated 
    
    dp[n] = fib(n-1, dp) + fib(n-2, dp);  // before returning from the function, we will set dp[n] to the solution we get.
    return dp[n];
    // return dp[n] = fib(n-1, dp)+ fib(n-2, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);   // Create a dp[n+1] array initialized to -1.
    
    cout<<fib(n, dp);
    return 0;
}


// M-2) Tabulation (Bottom-Up approach): We start from the base case and we try to go to the required answer.
// T.C: O(N), we are running a simple iterative loop.
// S.C: O(N), we are using an external array of size ‘n+1’.

int main(){
  int n=5;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1] + dp[i-2];
  }
  
  cout<<dp[n];
  return 0;
}


// M-3 Tabulation with space optimization.
// T.C: O(N), we are running a simple iterative loop.
// S.C: O(1), we are not using any extra space.

int main(){
  int n=5;
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int curr = prev2 + prev;
      prev2 = prev;
      prev= curr;
  }

  cout<<prev;
  return 0;
}














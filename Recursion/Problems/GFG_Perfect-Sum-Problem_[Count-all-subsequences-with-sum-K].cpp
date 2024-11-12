// Question : Count all subsequences with sum K

// M-1) Recursion + Backtracking --> Gives TLE
// T.C: O(2^n), S.C: O(n)
/*
class Solution{
    public:
    
    int ans = 0;

    void helper(int arr[], int n, vector<int>& sub, int i, int total, int sum){
        if(i == n){
            if(total == sum)  ans++;
            return;
        }
        
        sub.push_back(arr[i]);
        // total += arr[i];
        helper(arr, n, sub, i+1, total + arr[i], sum);
        // total -= arr[i];
        sub.pop_back();
        
        helper(arr, n, sub, i+1, total, sum);
    }
    
    int perfectSum(int arr[], int n, int sum) {
        int i = 0;
        int total = 0;
        vector<int> sub;
        helper(arr, n, sub, i, total, sum);
        
        return ans;
	}
	  
};
*/


// M-2) Recursion + Backtracking --> Gives TLE
// T.C: O(2^n), S.C: O(n)
class Solution{
    public:

    int helper(int arr[], int n, vector<int>& sub, int i, int total, int sum){
        if(i == n){ 
            if(total == sum)    // condition satisfied
                return 1;
            else              // condition not satisfied
                return 0;
        }
        
        sub.push_back(arr[i]);
        total += arr[i];
        int l = helper(arr, n, sub, i+1, total, sum);
        
        sub.pop_back();
        total -= arr[i];
        int r = helper(arr, n, sub, i+1, total, sum);
        
        return l + r;
    }
    
    int perfectSum(int arr[], int n, int sum) {
        int i = 0;
        int total = 0;
        vector<int> sub;
        int ans = helper(arr, n, sub, i, total, sum);
        
        return ans;
	}
	  
};


// M-3) DP
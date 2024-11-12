// Question : Check if there exists a subsequence with sum K


// M-1) Recursion + Backtracking --> Gives TLE
// T.C: O(2^n), S.C: O(n)
// Technique to print only one answer - https://www.youtube.com/watch?v=eQCS_v3bw0Q
// In base case, if condition in satisfied, return true. Else return false. Then, if(helper() == true) return;
// This avoids future recursive calls if even a single true is returned in any recursion frame.
class Solution{
    public:
    
    bool helper(vector<int>& arr, int n, vector<int>& sub, int i, int total, int k){
        if(i == n){ 
            if(total == k)    // condition satisfied
                return true;
            else              // condition not satisfied
                return false;
        }
        
        sub.push_back(arr[i]);
        total += arr[i];
        if(helper(arr, n, sub, i+1, total, k) == true){
            return true;
        }
        
        sub.pop_back();
        total -= arr[i];
        if(helper(arr, n, sub, i+1, total, k) == true){
            return true;
        }
        
        return false;
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        int i=0;
        int total = 0;
        vector<int> sub;
        bool ans = helper(arr, n, sub, i, total, k);
        
        return ans;
    }
};  


// M-2) DP
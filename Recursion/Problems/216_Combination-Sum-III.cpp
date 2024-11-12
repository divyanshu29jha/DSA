// M-1) Recursion + Backtracking (without for-loop)
// T.C: O(2^N), S.C: O(N), N = size of arr
/*
class Solution {
public:
    void getComb(vector<int>& arr, vector<int>& comb, vector<vector<int>>& ans, int i, int k, int n){
        if(i > 8){
            if(comb.size() == k && n == 0)
                ans.push_back(comb);
            return;
        }

        comb.push_back(arr[i]);
        getComb(arr, comb, ans, i+1, k, n-arr[i]);   // i-th element included in comb and subtracted from sum n
        comb.pop_back();

        getComb(arr, comb, ans, i+1, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> comb;
        int i = 0;

        getComb(arr, comb, ans, i, k, n);

        return ans;
    }
};
*/

// M-2) Recursion + Backtracking (with for-loop)
// T.C: O(2^N), S.C: O(N), N = size of arr
class Solution {
public:
    void getComb(vector<int>& arr, vector<int>& comb, vector<vector<int>>& ans, int idx, int k, int n){
        if(comb.size() == k && n == 0){
            ans.push_back(comb);   // push comb in ans only if target == 0
        }

        for(int i = idx; i < arr.size(); i++){
            // if(arr[i] > n) break;    // can prevent unnecessary future recursion calls
            
            comb.push_back(arr[i]);
            getComb(arr, comb, ans, i+1, k, n-arr[i]);   // i-th element picked in comb and subtracted from sum n
            comb.pop_back();   // not pick i-th element is handled by for-loop iteration after pop back
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> comb;
        int idx = 0;

        getComb(arr, comb, ans, idx, k, n);

        return ans;
    }
};

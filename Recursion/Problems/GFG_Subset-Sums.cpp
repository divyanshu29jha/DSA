// T.C: O(2^n). Each index has two ways. You can either pick it up or not pick it. So for n index, T.C is O(2^n).
// S.C: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
class Solution {
  public:
    void getSubSum(int i, int sum, vector<int>& arr, int n, vector<int>& ans){
        if(i == n){
            ans.push_back(sum);
            return;
        }
        
        getSubSum(i+1, sum+arr[i], arr, n, ans);   // i-th element included in sum
        
        getSubSum(i+1, sum, arr, n, ans);    // i-th element not included in sum
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        int i = 0;
        int sum = 0;
        getSubSum(i, sum, arr, n, ans);
        
        return ans;
    }
};
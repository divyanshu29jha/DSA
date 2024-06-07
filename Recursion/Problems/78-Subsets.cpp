// M-1) Recursion + Backtrackking
// T.C: O(2^n), S.C: O(n), recursion stack.
// We need to pop_back() from the subset vector because we are using the same subset vector for the entire problem 
// and passing it by reference. For backtrackking, the subset vector should be same as in that recursion frame for 
// execution of further code
class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int> &subset, vector<int> &nums, int i){    // Important to pass subset vector by reference 
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }

        // ith element of nums not included in subset
        helper(subset, nums, i+1);

        //ith element of nums included in subset
        subset.push_back(nums[i]);
        helper(subset, nums, i+1);
        subset.pop_back();    // for backtrackking, string should be same as in that recursion frame
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<int> subset;   // subset vector is intially empty in the argument
        helper(subset, nums, 0);    // 0-th index for trackking current element of nums vector
        return ans;
    }
};

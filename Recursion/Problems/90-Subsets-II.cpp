// M-1) Recursion + Backtrackking (without for-loop)
// T.C: O(n*2^n), S.C: O(n*2^n) + O(n) for recursion stack.
// We need to pop_back() from the subset vector because we are using the same subset vector for the entire problem and passing it by reference. For backtrackking, the subset vector should be same as in that recursion frame for execution of further code.
/*
class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int> &subset, vector<int> &nums, int i){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }
            
        subset.push_back(nums[i]);
        helper(subset, nums, i+1);    // ith element of nums included in subset
        
        subset.pop_back();  // for backtrackking, string should be same as in that recursion frame    
        while(i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        helper(subset, nums, i+1);   // ith element of nums not included in subset
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // sort the nums array to bring duplicates together
        vector<int> subset;   // subset vector is intially empty in the argument
        helper(subset, nums, 0);    // 0-th index for trackking current element of nums vector
        
        return ans;
    }
};
*/


// M-2) Recursion + Backtrackking  (with for-loop)
// T.C: O(n*2^n), S.C: O(n*2^n) + O(n) for recursion stack.
// We need to pop_back() from the subset vector because we are using the same subset vector for the entire problem  and passing it by reference. For backtrackking, the subset vector should be same as in that recursion frame for execution of further codes.
// To avoid duplicates you have to check if your previous element was also same, other wise tree with duplicate elements will be created.Thus we check num[i] == nums[i-1], if it's true we we skip the loop (skip making tree for that element), but for 1st element code will crash since we are checking if nums[0] == nums[-1]. Thus we check with i>0 but for sub problems this won't hold true, since they are not aware of first element at i == 0, so thus to generalize this we check i != idx && nums[i] == nums[i-1], this condition holds true for all the subproblems.
class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int> &subset, vector<int> &nums, int idx) {
        ans.push_back(subset);   

        for(int i = idx; i < nums.size(); i++){
            if(i != idx && nums[i] == nums[i-1]){   // Skip duplicates
                continue;
            }
            
            subset.push_back(nums[i]);
            helper(subset, nums, i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // sort the nums array to bring duplicates together
        vector<int> subset;   // subset vector is intially empty in the argument
        helper(subset, nums, 0);    // 0-th index for trackking current element of nums vector
        
        return ans;
    }
};

// M-1) Recursion + Backtracking (without for-loop)
// T.C: O(n*2^n), S.C: O(n*2^n) + O(n) for recursion stack.
// We are using a single & same subset for each recursive call (by passing as reference). So, it's important to pop back each no. so that the subset remains same for each recursion frame. For backtrackking, the subset vector should be same as in that recursion frame for execution of further code.
/*
Time Complexity:
Subset Generation: For an array of size n, there are 2^n possible subsets (including the empty subset).
The helper function is called recursively to generate each subset. Since there are 2^n subsets, the number of recursive calls is O(2^n).
Subset Construction: For each recursive call that reaches the base case (i.e., when i == nums.size()), the current subset is added to the answer ans.
The process of copying the current subset into ans takes O(n) time because, in the worst case, the subset contains all n elements.
Total Time Complexity: Since there are 2^n subsets and each subset takes O(n) time to construct, the total time complexity is: O(n×2^n).
This is the overall time complexity for generating all subsets and adding them to the result (ans vector).

Space Complexity:
Auxiliary Space (Recursion Stack): The recursion depth is at most n, so the space required for the recursion stack is O(n).
Space for Storing Subsets: The total space required to store all subsets in ans is O(n×2^n) because there are 2^n subsets, each of which can have up to n elements.
Total Space Complexity: O(n×2^n) (for storing all subsets) plus O(n) (for the recursion stack).
*/
/*
class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int> &subset, vector<int> &nums, int i){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }

        //ith element of nums included in subset
        subset.push_back(nums[i]);
        helper(subset, nums, i+1);
        subset.pop_back();    // for backtrackking, string should be same as in that recursion frame

        // ith element of nums not included in subset
        helper(subset, nums, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<int> subset;   // subset vector is intially empty in the argument
        helper(subset, nums, 0);    // 0-th index for trackking nums vector
        return ans;
    }
};  
*/

// M-2) Recursion + Backtracking (with for-loop)  [https://www.youtube.com/watch?v=W9JE_V-6FYI&list=PLICVjZ3X1AcY5ai7at5OvS4ckXiMbWxCa]
// T.C: O(n*2^n), S.C: O(n*2^n) + O(n) for recursion stack.
// Every node in recursion tree stores an answer (in a dfs manner) and no base condition required.
// We are using a single & same subset for each recursive call (by passing as reference). So, it's important to pop back each no. so that the subset remains same for each recursion frame. For backtrackking, the subset vector should be same as in that recursion frame for execution of further code.
class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int> &subset, vector<int> &nums, int idx) {
        ans.push_back(subset);   

        for(int i = idx; i < nums.size(); i++){            
            subset.push_back(nums[i]);
            helper(subset, nums, i + 1);
            subset.pop_back();
        }
        // return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;   // subset vector is intially empty in the argument
        helper(subset, nums, 0);    // 0-th index for trackking current element of nums vector

        return ans;
    }
};


// M-3) Bit Manupulation (https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/)
// T.C: O(2^n * n) because O(2^n) for the outer for loop and O(n) for the inner for loop
// S.C: O(1)
// NOTE: If n&(1<<i) != 0,then the ith bit is set. If n&(1<<i) == 0,then the ith bit is not set.
// First, write down all the numbers from 0 to 2^(n)-1 and their bit representation. 0 means I am not picking the character in my subsequence, and 1 means I am picking the character.
// Basically, we traverse from 0 to 2^(n)-1 and check for every number if their bit is set or not. If the bit is set add that character to your subsequence.
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int num=0; num < (1 << n); num++){     // (1 << n) is 2^n
	        vector<int> subset;
		    for(int i = 0; i < n; i++){
			    if(num & (1 << i)){    //check if the i-th bit is set or not
				    subset.push_back(nums[i]);
			    }
		    }
			
            ans.push_back(subset);
	    }

        return ans;
    }
};
*/




// M-1) Recursion (with extra space of freq vector)
// T.C: O(n * n!). The total number of permutations of an array of size n is n!. For each permutation, the algorithm performs a series of recursive calls and a loop over the elements of the array. The loop iterates n times, and within each iteration, it makes a recursive call. Thus, the time complexity is O(n * n!), since the algorithm iterates over all n! permutations and for each permutation, it takes O(n) time to generate it.
/* S.C: O(n * n!). The space complexity includes:
Recursion Stack: The maximum depth of the recursion is n (one level for each element in the permutation). So, the space required for the recursion stack is O(n).
Frequency Array (freq): The frequency array freq is of size n, so it requires O(n) space.
Result Storage (ans): The result ans stores all n! permutations, and each permutation is of size n. Hence, the space required for storing the permutations is O(n×n!).
*/
/*
class Solution {
public:
    void recurPermute(vector<int>& nums, vector<int>& freq, vector<int>& perm, vector<vector<int>>& ans){
        if(perm.size() == nums.size()){      // cannot use i == nums.size()
            ans.push_back(perm);
            return;
        }

        for(int i = 0; i < nums.size(); i++){     // loop always runs from 0 to n-1
            if(freq[i] == 0){     // element is unmarked then it means it has not been picked and then we pick.
                perm.push_back(nums[i]);
                freq[i] = 1;
                
                recurPermute(nums, freq, perm, ans);   // freq[i] is marked in this call and element in pushed in perm
                
                perm.pop_back();
                freq[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> perm;    // stores individual permutations
      vector<int> freq(nums.size(), 0);   // initialize freq vector to track element taken in perm or not  

      recurPermute(nums, freq, perm, ans);

      return ans;
    }
};
*/


// M-2) Recursion (With Backtracking.)
// T.C: O(n * n!). The total number of permutations of an array of size n is n!. The function recurPermute is called once for each level of the permutation tree, and at each level, the loop runs n−idx times. Since the depth of the recursive call stack is 𝑛 and each level processes n−idx elements, the overall time complexity is O(n×n!).
/* S.C: O(n * n!). The space complexity includes:
Recursion Stack: The maximum depth of the recursion is n (one level for each element in the permutation). So, the space required for the recursion stack is O(n).
Result Storage (ans): The result ans stores all n! permutations, and each permutation is of size n. Hence, the space required for storing the permutations is O(n×n!).
// idx represents a particular index and i represents what other values can get chance to be at index 2idx.
*/
class Solution {
public:
    void recurPermute(int idx, vector<int>& nums, vector<vector<int>>& ans){
        if(idx == nums.size()){    // idx pointer reaches out of nums
            ans.push_back(nums);   // nums pushed in ans
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            recurPermute(idx + 1, nums, ans);    // swapped nums is passed
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;
      int idx = 0;
      recurPermute(idx, nums, ans);

      return ans;
    }
};
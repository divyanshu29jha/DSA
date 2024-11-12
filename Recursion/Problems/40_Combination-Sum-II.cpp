// M-1) Recursion + Backtracking (without for-loop)
// T.C: O(2^n * k), where no. of subsequence you will get will be O(2^n) and k is max size of combination that is pushed in ans.
// S.C: O(k*x), k is the average length of combination and x is the no. of combinations.
/*
class Solution {
public:
    void findCombination(int i, int target, vector<int>& candidates, vector<int>& comb, vector<vector<int>>& ans){
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(comb);   // push comb in ans only if target == 0, but return everytime when i reaches last index
            }
            return;
        }     
        
        if(candidates[i] <= target){
            comb.push_back(candidates[i]);  
            findCombination(i+1, target-candidates[i], candidates, comb, ans);  // pick candidates[i] and move at next index   
            comb.pop_back();
        }      
        
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        findCombination(i+1, target, candidates, comb, ans);   // not pick candidates[i] and move at next index
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int i = 0;
        vector<vector<int>> ans;
        vector<int> comb;
        findCombination(i, target, candidates, comb, ans); 

        return ans;
    }
};
*/


// M-2) Recursion + Backtracking (with for-loop)
// T.C: O(2^n * k), where no. of subsequence you will get will be O(2^n) and k is max size of combination that is pushed in ans.
// S.C: O(k*x), k is the average length of combination and x is the no. of combinations.
// Every node in recursion tree stores an answer (in a dfs manner) and no base condition required.
// idx is that index which tells what value to keep in the comb and i is just traversal of array. To pick and not to pick candidate[i] is handled by the for-loop iteration after a candidate is popped.
class Solution {
public:
    void findCombination(int idx, int target, vector<int>& candidates, vector<int>& comb, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(comb);   // push comb in ans only if target == 0
        }
             
        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]){     // OR i != idx
                continue;
            }

            if (candidates[i] > target)  // as sorted candidates  // if we ignore this, then TLE
                break;

            comb.push_back(candidates[i]); 
            findCombination(i+1, target-candidates[i], candidates, comb, ans);   // pick candidates[i] and stay at same index   
            comb.pop_back();
        } 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int idx = 0;
        vector<vector<int>> ans;
        vector<int> comb;
        findCombination(idx, target, candidates, comb, ans); 

        return ans;
    }
};

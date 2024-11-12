// Question: Print all distinct Subsequences.

// M-1) Recurion + Backtracking --> Gives TLE
// T.C: O(2^n * n) : Generating all subsequences takes O(2^n). Inserting each subsequence takes O(n) in the worst case.
// S.C: O(2^n * n) : Recursion Stack has O(n) space and the unordered_set stores all unique subsequences. 
// In the worst case, all subsequences are unique, and there are 2^n subsequences, each taking up to O(n) space.
// NOTE: String is by-default passed as reference. Subsequences must contain elements in same order as in original string.
// Power set may contatin elements in any order. So, Power Set is not always same as distinct Subsequences.
class Solution {
  public:
    void helper(unordered_set<string>& ans, string str, string sub, int i){    // pass ans by reference 
        if(i == str.size()){
            ans.insert(sub);
            return;
        }
        
        sub.push_back(str[i]);
        helper(ans, str, sub, i+1);
        
        sub.pop_back();
     
        helper(ans, str, sub, i+1);
    }
    
    string betterString(string str1, string str2) {
        unordered_set<string> ans1;   // stores distinct subsequences for str1
        string sub = "";  
        int i = 0;   // tracks index of string str1
        helper(ans1, str1, sub, i);
    
        unordered_set<string> ans2;   // stores distinct subsequences for str2
        sub = "";  
        i = 0;   // tracks index of string str2
        helper(ans2, str2, sub, i);
        
        
        if(ans1.size() >= ans2.size()) return str1;
        return str2;
    }
};


// M-2) Using DP
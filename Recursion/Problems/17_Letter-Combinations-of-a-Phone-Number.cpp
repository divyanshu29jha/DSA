// Similar to Combination Sum II
// T.C: O(k^n * n), S.C: O(k^n * n)
// If the length of the input digits is n, and each digit maps to an average of k letters, the total number of combinations is O(k^n).
// For each combination, building the string and making recursive calls involve O(n) work, where n is the length of the digits string.
class Solution {
public:
    void getComb(string digits, int idx, unordered_map<int, string>& mpp, string comb, vector<string>& ans){
        if(comb.size() == digits.size()){
            ans.push_back(comb);
            return;
        }

        string s = mpp[digits[idx] - '0'];
        for(int i=0; i<s.size(); i++){
            comb.push_back(s[i]);
            getComb(digits, idx+1, mpp, comb, ans);
            comb.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mpp = { {2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"} };

        vector<string> ans;
        string comb = "";
        int idx = 0;

        if(digits == "")
            return ans;

        getComb(digits, idx, mpp, comb, ans);

        return ans;
    }
};


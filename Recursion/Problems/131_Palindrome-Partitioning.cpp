// Recursion + Backtracking
// T.C: O(n * 2^n), where n is the length of the string. For each substring, there are two possibilities: either the substring is included in the current partition, or it isn't, and the palindrome check is O(n).
// S.C: O(n), which comes from the recursion depth and the space used by the part vector to store current partitions. The output space could be as large as O(n * 2^n) to store all possible partitions.
// Consider partition to the right-side of index.
// If the substring is not a palidrome inside a given parition, then no need to check for further partitions towards the right.
class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void getPartition(int idx, string s, vector<string>& part, vector<vector<string>>& ans){
        if(idx == s.size()){
            ans.push_back(part);
            return;
        }

        for(int i=idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                part.push_back(s.substr(idx, i-idx+1));   // copy (i-idx+1) characters of s starting from from index idx 
                getPartition(i+1, s, part, ans);
                part.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        int idx = 0;
        getPartition(idx, s, part, ans);

        return ans;
    }
};
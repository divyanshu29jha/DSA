// M-1) T.C: O(2^n), S.C: O(2^n)
// Only add open parenthesis if open < n
// Only add closed parenthesis if closed < open
// Well-formed parentheses if open == closed == n  (OR)  s.size() == 2*n
/*
class Solution {
public:
    void helper(vector<string>& v, int n, int oc, int cc, string s){  // Important - pass vector by refernce for recursion call 
        if(oc == n && cc == n){    // Base Case:   OR s.size() == 2*n
            v.push_back(s);
            return;
        }

        if(oc < n){
            helper(v, n, oc+1, cc, s+'(');
        }

        if(cc < oc){
            helper(v, n, oc, cc+1, s+')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int oc = 0, cc = 0;   // initially open count and closed count are 0
        helper(v, n, oc, cc, "");   // pass empty string initially

        return v;
    }
};
*/


// M-2) T.C: O(N * 2^N) where N = 2*n
// O(2^N) : We have N = 2n places to fill and for every place we will have a maximum of 2 choices.
// O(N): We will have to multiply our TC by a factor of N, as every time when we hit the base case, we will copy current string (which is of size N) into the answer vector.
// S.C: O(N) + Recursive Stack Space (We have used an extra string of size N for storing current output)
class Solution {
public:
    vector<string> v;  // declare the ans vector globally
    void helper(int n, int oc, int cc, string &s){   
        if(oc == n && cc == n){    // Base Case:   OR s.size() == 2*n
            v.push_back(s);
            return;
        }

        if(oc < n){
            s.push_back('(');
            helper(n, oc+1, cc, s);
            s.pop_back();   // for backtrackking, string should be same as in that recursion frame for execution of further code
        }

        if(cc < oc){
            s.push_back(')');
            helper(n, oc, cc+1, s);
            s.pop_back();   // for backtrackking, string should be same as in that recursion frame
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        int oc = 0, cc = 0;   // initially open count and closed count are 0
        helper(n, oc, cc, s);   // pass empty string initially

        return v;
    }
};
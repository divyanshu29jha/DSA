// M-1) T.C: O(2^n), S.C: O(2^n)
class Solution{
public:
    void helper(vector<string>& ans, int n, string s){   // Important - pass vector by refernce for recursion call 
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        
        helper(ans, n, s+'0');
        
        if(s.empty() || s[s.size()-1] != '1'){   // OR s.back() != '1'   // Check if the last character is not '1'
            helper(ans, n, s+'1');
        }
    }
    
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        string s = "";
        helper(ans, num, s);
        
        return ans;
    }
};


// M-2) T.C: O(2^n), S.C: O(2^n)
/*
class Solution{
public:
    void helper(vector<string>& ans, int n, string s){   // Important - pass vector by refernce for recursion call 
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        
        s.push_back('0');
        helper(ans, n, s);
        s.pop_back();
        
        if(s.empty() || s[s.size()-1] != '1'){   // OR s.back() != '1'   // Check if the last character is not '1'
            s.push_back('1');
            helper(ans, n, s);
            s.pop_back();
        }
    }
    
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        string s = "";
        helper(ans, num, s);
        
        return ans;
    }
};
*/
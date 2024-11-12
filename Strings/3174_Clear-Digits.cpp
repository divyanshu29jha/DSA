// Example - 123abc123
// Method-1 (Brute force)
// T.C: O(n^2)
/*
class Solution {
public:
    string clearDigits(string s) {
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                s[i] = '*';
                for(int j=i; j>=0; j--){
                    if(isalpha(s[j])){
                        s[j] = '*';
                        break;
                    }
                }
            }
        }


        string ans;
        for(auto i : s){
            if(i != '*')
                ans.push_back(i);
        }
        return ans;
    }
};
*/


// Method-2
// T.C: O(n)
class Solution {
public:
    string clearDigits(string s) {
        int i=0, j=0;
        string ans;
        while(i < s.length()){
            if(!isdigit(s[i])){   // s[i] is alphabet
                ans += s[i];
                i++;
            }
            else{     // s[i] is digit
                i++;
                if(!ans.empty())    // if(ans.size() >= 1)
                    ans.pop_back();
            }
        }
        
        return ans;
    }
};
// M-1 (Using stack)
// T.C : O(n)
// S.C : O(n)
/*
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cc = 0;
        
        for(char& ch : s){
            if(ch == '(')
                st.push(ch);
            else if(!st.empty())
                st.pop();
            else
                cc++;
        }
        
        return cc + st.size();  
    }
};
*/


// M-2 (without using stack)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int oc = 0, cc = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(')
                oc++;
            else if(s[i] == ')' && oc > 0)
                oc--;
            else 
                cc++;
        }

        return oc+cc;
    }
};
// M-1) Using stacks: T.C - O(N), S.C - O(N)
// Youtube - https://www.youtube.com/watch?v=obdjfsKer0I   (Ayushi Sharma) 
// Intuition - Take inspiration from 'Valid Parentheses' leetcode problem.
// Approach - We will traverse the string and replace the brackets which need to be removed with '#'. Later, we will again traverse the string again and push the characters apart from '# in a new ans string. Then return this ans string.

// Now we need to find out which brackets should be replaced by '#' to remove. 
// case 1: s = "lee(t(c)o)de)". Here the first four brackets will cancel each other in stack. The last closing bracket should be replaced with '#'.
// case 2: s = "(l)e(e(t(c)o)de". Here the first two brackets and last four brackets will cancel each other in stack. But 3rd opening bracket will still remain in stack. This need to be replaced by '#' to remove, but we don't know at which index this opening bracket is present. So, we will create a stack and push indices of brackets that should be replaced by '#'.
/*
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;  // create stack of integers to store indices of brackets to be replaced by '#'

        for(int i=0; i<s.size(); i++){    // Implement case 1: Replace extra closing brackets with '#'
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    s[i] = '#';   // closing bracket without any opening bracket in stack
                }
                else{      
                    st.pop();
                }
            }
        }

        // if there are still opening brackets (indices) left in the stack
        while(!st.empty()){    // Implement case 2: Replace extra opeing brackets with '#'
            s[st.top()] = '#';
            st.pop();
        }

        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] != '#'){ 
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};
*/



// M-2) Without using stacks: T.C - O(N), S.C - O(1)
// Use a single count variable to replace the stack. 
// Case 1: Extra closing bracket - opening bracket will increase the count, closing bracket will decrease the count.
// Case 2: Extra opening bracket - closing bracket will increase the count, opening bracket will decrease the count [traverse in reverse]
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        
        // extra closing bracket
        int count=0; 
        for(int i=0; i<n; i++){
            if(s[i] == '('){ 
                count++;
            }
            else if(s[i] == ')'){
                if(count == 0){   // closing bracket without any opening bracket 
                    s[i]='#';
                }
                else{
                    count--;
                }
            }
        }
        
        // extra opening bracket
        count=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == ')'){ 
                count++;
            }
            else if(s[i] == '('){ 
                if(count == 0){ 
                    s[i]='#';
                }
                else{
                    count--;
                }
            }
        }
        
       string ans;
        for(int i=0; i<n; i++){
            if(s[i] != '#'){ 
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
        
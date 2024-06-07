class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto it : s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }
            else{
                if(st.empty()) return false;   // case when stack will be empty, if there is a closing bracket without any opening brackets (when closing brackets > opening brackets) 
                                                
                char ch = st.top();
                st.pop();
                if ((it == ')' && ch != '(') || (it == '}' && ch != '{') || (it == ']' && ch != '[')) {
                    return false;
                }
            }
        }

        if(st.empty())    // equal no. of opening and closing brackets, so stack will be empty
            return true;
        else        // case when there are opening brackets still in the stack (when opening brackets > closing brackets)  
            return false;
    }
};
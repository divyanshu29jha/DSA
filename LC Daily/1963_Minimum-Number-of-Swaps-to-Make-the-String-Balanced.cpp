// M-1) (Using stack)
// T.C : O(n)
// S.C : O(n)
/*
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(char &ch : s){
            if(ch == '[')
                st.push(ch);
            else if(!st.empty())
                st.pop();
        }
        
        return (st.size()+1)/2;
    }
};
*/


// M-2) (without using stack)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        
        for(char &ch : s){
            if(ch == '[')      
              cnt++;
            else if(cnt != 0)
              cnt--;
        }
        
        // return (cnt+1)/2;
        return ceil(double(cnt)/2);
    }
};

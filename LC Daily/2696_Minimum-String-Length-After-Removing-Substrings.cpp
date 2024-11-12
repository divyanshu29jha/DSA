// M-1) (Brute Force)
// T.C : O(n^2)
// S.C : O(1)
/*
class Solution {
public:
    int minLength(string s) {
        while(s.find("AB") != -1 || s.find("CD") != -1){    // "AB" exists or "CD" exists
            if(s.find("AB") != -1) 
                s.erase(s.find("AB"), 2);   // from index s.find("AB"), erase two charcters
            else if(s.find("CD") != -1) 
                s.erase(s.find("CD"), 2);
        }

        return s.length();
    }
};
*/

// M-2) (Using stack)
// T.C : O(n)
// S.C : O(n)
/*
class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            char currentChar = s[i];

            // if(st.empty()){
            //     st.push(currentChar);
            //     continue;
            // }

            if(currentChar == 'B' && !st.empty() && st.top() == 'A')
                st.pop();
            else if(currentChar == 'D' && !st.empty() && st.top() == 'C')
                st.pop();
            else
                st.push(currentChar);
        }

        return st.size();
    }
};
*/

// M-3 (Using 2 pointers = i : read, j ; write)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        
        int i = 0; //Write
        int j = 1; //Read

        while(j < n){
            if(i < 0){
                i++;
                s[i] = s[j];
            } 
            else if((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D')){
                i--;
            } 
            else{
                i++;
                s[i] = s[j];
            }

            j++;

        }
        return i+1;
    }
};



// Approach 1: Depth Counting
// T.C: O(n), since we iterate through whole array logs, S.C: O(1), since no extra space is used
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(int i=0; i<logs.size(); i++){
            if(logs[i] == "./"){
                continue;
            }
            else if(logs[i] == "../"){
                if(cnt != 0) 
                    cnt--;
            }
            else{
                cnt++;
            }
        }

        return cnt;
    }
};


// Approach 2: Using stacks to keep track of the current directory path. Return length of the stack after perfoming all operations.
// T.C: O(n), since we iterate through whole array logs, S.C: O(n), since we use stack which can be of size n in worst case.
/*
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (string& log : logs) {
            if (log == "../") {
                if (!st.empty()) 
                    st.pop();
            } 
            else if (log != "./") {
                st.push(log);
            }
        }

        return st.size();
    }
};
*/
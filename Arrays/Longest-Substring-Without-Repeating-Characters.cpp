// M-1) Brute force --> T.C: O(n^2); S.C: O(n)
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 1;

        if(s.length() == 0){
            return 0;
        }

        for(int i = 0; i < n; i++){     
            unordered_set<char> st;
            st.insert(s[i]);    // O(1)
            int count = 1;

            for(int j = i + 1; j < n; j++){
                if(st.find(s[j]) == st.end()){  // if the selement does not exist in the set
                    st.insert(s[j]);
                    count++;
                    maxLength = max(maxLength, count);
                }
                else{
                    break;
                }
            }
        }

        return maxLength;
    }
};
*/


// M-2) Using set & sliding window --> T.C: O(2*n); S.C: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 1;
        int count = 0;
        unordered_set<char> st;

        if(s.length() == 0){
            return 0;
        }

        int i = 0, j = 0;  // two-pointers
        while(j < n){
            if(st.find(s[j]) == st.end()){  // if s[j] does not lie in the set
                st.insert(s[j]);
                count++;
                j++;
                maxLength = max(maxLength, count);
            }
            else{
                st.erase(s[i]);
                count--;
                i++;
            }
        }

        // while(j<n){      // Another way to write above code snippet without using 'count' variable
        //     if(st.count(s[j])==0)    // if s[j] does not lie in the set
        //     {
        //         st.insert(s[j]);
        //         maxLength=max(maxLength,(int)st.size());
        //         j++;
        //     }
        //     else
        //     {
        //         st.erase(s[i]);
        //         i++;
        //     }
        // }
        
        return maxLength;
    }
};













// M-1) Prefix Sum and Hashing
// T.C: O(n), S.C: O(n)

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int cnta = 0, cnte = 0, cnti = 0, cnto = 0, cntu = 0;
        int ans = 0;
        unordered_map<string, int> m;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a') cnta++;
            if(s[i] == 'e') cnte++;
            if(s[i] == 'i') cnti++;
            if(s[i] == 'o') cnto++;
            if(s[i] == 'u') cntu++;
            
            string even = to_string(cnta % 2) + to_string(cnte % 2) + to_string(cnti % 2) + to_string(cnto % 2) + to_string(cntu % 2);
            
            if(even == "00000"){   // this means ans is valid starting from index 0 
                ans = i + 1;
            }
            else{
                if(m.find(even) != m.end()) 
                    ans = max(ans, i - m[even]);      // odd - odd = even, even - even = even
                else
                    m[even] = i;
            }
        }

        return ans;
    }
};


// M-2) Bitmasking
// T.C : O(n), S.C: O(n)
// We use a bitmask where each bit represents whether a vowel has been seen an odd number of times. For example, if the bit for a is set, it means a has been seen an odd number of times. 
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        unordered_map<int,int> m;
        m[0] = -1;
        int mask = 0, ans = 0;
        
        for(int i = 0; i < n; i++){
            if (s[i] == 'a') mask ^= (1 << 0);       // mask ^= 1
            else if (s[i] == 'e') mask ^= (1 << 1);  // mask ^= 2
            else if (s[i] == 'i') mask ^= (1 << 2);  // mask ^= 4
            else if (s[i] == 'o') mask ^= (1 << 3);  // mask ^= 8
            else if (s[i] == 'u') mask ^= (1 << 4);  // mask ^= 16
            
            if(m.find(mask) != m.end()) 
                ans = max(ans, i  - m[mask]);
            else
                m[mask] = i;
        }
        return ans;
    }
};


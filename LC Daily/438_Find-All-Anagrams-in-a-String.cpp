// M-1) Using sorting
// T.C: O((n2-n1)*n1logn1) 
/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();
        vector<int> ans;
        sort(p.begin(), p.end());

        for(int i = 0; i <= slen-plen; i++){
            string temp = s.substr(i, plen);
            sort(temp.begin(), temp.end());
            if(temp == p)
                ans.push_back(i);
        }

        return ans;
    }
};
*/


// M-2) Sliding Window + Hashmap
// T.C: O(n1 + (26+n1)*(n2-n1))
// S.C: O(n2-n1)
// One string will be a permutation of another string only if both of them contain the same characters with the same frequency.
/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int slen = s.size(), plen = p.size();
        if(slen < plen) return ans; 
        
        vector<int> pfreq(26, 0);  // Frequency of characters in p
        vector<int> sfreq(26, 0);  // Frequency of characters in current window of s
        
        int left = 0, right = plen-1;
        for(int i = left; i <= right; i++){  // first window
            pfreq[p[i]-'a']++;
            sfreq[s[i]-'a']++;
        }
        if(pfreq == sfreq) ans.push_back(left);

        while(right < slen-1){
            sfreq[s[left]-'a']--;
            left++;
            right++;
            sfreq[s[right]-'a']++;
            if(pfreq == sfreq) ans.push_back(left);
        }

        return ans;
    }
};
*/

// Another way to write M-2
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int slen = s.size(), plen = p.size();
        
        if (slen < plen) return ans;  
        
        vector<int> pfreq(26, 0);  // Frequency of characters in p
        vector<int> sfreq(26, 0);  // Frequency of characters in current window of s
        
        for(char ch : p){
            pfreq[ch - 'a']++;
        }
        
        for(int i = 0; i < slen; i++){
            sfreq[s[i] - 'a']++;  // Add the current character to the window
            
            if(i >= plen){    // Remove the character that is left behind the window of size plen
                sfreq[s[i - plen] - 'a']--;
            }
            
            if(sfreq == pfreq) // Compare frequency arrays of current window and p
                ans.push_back(i - plen + 1);
        }
        
        return ans;
    }
};


// M-3) Map (instead of frequency array)
/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int slen = s.size(), plen = p.size();
        if (slen < plen) return ans;

        unordered_map<char, int> pfreq;  // Frequency of characters in p
        unordered_map<char, int> sfreq;  // Frequency of characters in current window of s

        for (int i = 0; i < plen; i++) {  // Initialize frequency for first window
            pfreq[p[i]]++;
            sfreq[s[i]]++;
        }

        int left = 0, right = plen - 1;
        if (pfreq == sfreq) ans.push_back(left);  // Check if the first window is an anagram

        while (right < slen - 1) {
            sfreq[s[left]]--;  // Remove the leftmost character from the window
            left++;
            right++;
            sfreq[s[right]]++;  // Add the next character to the window

            if (pfreq == sfreq) ans.push_back(left);  // Check for anagram in the current window
        }

        return ans;
    }
};
*/
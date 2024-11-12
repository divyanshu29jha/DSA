// M-1) Using sorting
// T.C: O((n2-n1)*n1logn1) 
/*
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        sort(s1.begin(), s1.end()); 

        for(int i=0; i <= n2-n1; i++){
            string temp = s2.substr(i, n1);
            sort(temp.begin(), temp.end());
            if(s1 == temp)
                return true;
        }

        return false;
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
    bool matches(unordered_map<char, int>& s1map, unordered_map<char, int>& s2map) {
        for(auto& it : s1map){   // O(26)
            if(it.second != s2map[it.first])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {        
        int n1 = s1.length(), n2 = s2.length();
        unordered_map<char, int> s1map;
        for(char ch : s1){   // O(n1)
            s1map[ch]++;
        }
         
        for(int i = 0; i <= n2-n1; i++){   // Sliding window over s2    // O(n2-n1+1)
            unordered_map<char, int> s2map;
            for(int j = 0; j < n1; j++){   // O(n1)
                s2map[s2[i+j]]++;
            }

            if(matches(s1map, s2map))
                return true;
        }

        return false;
    }
};
*/

// Another way to write M-2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.size(), s2len = s2.size();
        if (s1len > s2len) return false;

        vector<int> s1freq(26, 0);  // Frequency of characters in s1
        vector<int> s2freq(26, 0);  // Frequency of characters in current window of s2

        
        int left = 0, right = s1len - 1;  
        for(int i = left; i <= right; i++){  // Initialize frequency arrays for the first window
            s1freq[s1[i] - 'a']++;
            s2freq[s2[i] - 'a']++;
        }
        if (s1freq == s2freq) return true;

        while(right < s2len - 1){ 
            s2freq[s2[left] - 'a']--;  
            left++; 
            right++;   
            s2freq[s2[right] - 'a']++;  

            if (s1freq == s2freq) return true;
        }

        return false;
    }
};

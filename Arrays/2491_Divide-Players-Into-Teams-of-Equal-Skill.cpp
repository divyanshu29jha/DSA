// M-1) Using set
/*
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long totSum = 0;
        for(int i : skill){
            totSum += i;
        }
        if(totSum % (n/2) != 0) 
            return -1;
        long long k = totSum / (n/2);   // n/2 pairs will be formed

        unordered_multiset<int> s;
        long long chem = 0;
        for(int num : skill){
            int target = k - num;
            if(s.find(target) != s.end()){
                chem += num * target;
                s.erase(s.find(target));    // delete only one element if duplicates present
            }
            else{
                s.insert(num);
            }      
        }

        if(s.empty())        
            return chem;    
        return -1;
    }
};
*/

// M-2) Using map
// T.C: O(n), S.C: O(n)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long totSum = 0;
        for(int i : skill){
            totSum += i;
        }
        
        if (totSum % (n/2) != 0) return -1;
        
        long long k = totSum / (n/2);  
        unordered_map<int, int> mp;   // Count occurrences of each skill
        long long chem = 0;
        
        for(int num : skill){
            int target = k - num;  
            if(mp[target] > 0){
                chem += num * target;  // Add chemistry (product of skills)
                mp[target]--;    // Use up one instance of the target
            } 
            else{
                mp[num]++;  
            }
        }
        
        for(auto it : mp) {
            if(it.second != 0) return -1;  // Some players couldn't form teams
        }

        return chem;
    }
};


// M-3) Sorting
// T.C: O(n*logn), S.C: O(1)
/*
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int n = skill.size();
        long long chem = 0;

        int target = skill[0] + skill[n-1];

        for(int i = 0; i < n/2; i++) {   // Iterate through half of the array, pairing players from both ends
            int currentTeamSkill = skill[i] + skill[n-i-1];

            if(currentTeamSkill != target) 
                return -1;
            
            chem += (long long)skill[i] * (long long)skill[n-i-1];
        }

        return chem;
    }
};
*/           
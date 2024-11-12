// M-1) Hasing
// T.C: O(n), S.C: O(n)
/*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;   // no. as key and index as value
        
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){   // O(1)
                if(abs(i-mp[nums[i]]) <= k)
                    return true;
            }
            
            mp[nums[i]] = i;
        }
    
        return false;
    }
};
*/

// M-2) Sliding window (fixed size)
// T.C: O(n), S.C: O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;  
    
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end())   // O(1)
                return true;

            s.insert(nums[i]);

            if(s.size() > k)
                s.erase(nums[i-k]);
        }
    
        return false;
    }
};
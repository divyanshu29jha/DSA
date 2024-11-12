// M-1) Brute Force (Time Limit Exceeded)
// T.C: O(n^2), S.C: O(1)
/*
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(int i : nums) sum += i;

        if(sum % p == 0) return 0;

        int minLen = n;
        for(int i = 0; i < n; i++){  // Try removing every possible subarray
            long long subSum = 0;  
            for(int j = i; j < n; j++){
                subSum += nums[j];  // Calculate the subarray sum

                long long remainingSum = (sum - subSum) % p;

                if(remainingSum == 0)
                    minLen = min(minLen, j-i+1);  
            }
        }

        if(minLen == n)
            return -1;
        return minLen;
    }
};
*/

// M-2) Prefix Sum Modulo
// T.C: O(n), S.C: O(1)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        int rem = totalSum % p;
        if(rem == 0) return 0;   

        unordered_map<int, int> mp;   // stores predixMod as key and index as value 
        mp[0] = -1;     // Initialize for handling full prefix
        int minLen = n;
        long prefixSum = 0;

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];
            int prefixMod = prefixSum % p;
            int targetMod = (prefixMod - rem + p) % p;   // add p to handle negative target

            if(mp.find(targetMod) != mp.end()){
                minLen = min(minLen, i - mp[targetMod]);
            }

            mp[prefixMod] = i;   // update to closest i since we need to find minLen. 
	    // If maxLen needs to found, then don't update if prefixMod already exists in mp
        }

        if(minLen == n)
            return -1;
        return minLen;
    }
};
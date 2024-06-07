// M-1) Brute force (find sum of all possible subarrays)  --> T.C: O(n^2) + O(n), S.C: O(n)
// WARNING : Gives TLE as 1 <= nums.length <= 10^5 and T.C is O(n^2)
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> subSum;
        
        for(int i = 0; i < n; i++){     // sum of all possible subarrays
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                subSum.push_back(sum);
            }
        }

        int count = 0;  // no. of subarrays with sum k
        for(auto i : subSum){
            if(i == k)
                count++;
        }

        return count;
    }
};
*/

// M-2) Brute force (find sum of all possible subarrays)  --> T.C: O(n^2), S.C: O(1)
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;  // no. of subarrays with sum k
        for(int i = 0; i < n; i++){     // sum of all possible subarrays
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k)
                    count++;
            }
        }

        return count;
        
    }
};
*/


// In Longest Sub-Array with Sum K, we store prefix sum as key and index as value. Here it is important to check if prefix sum does not lies in map before inserting new prefixSum as we need the longest subarray.
// In Subarray Sum Equals K, we store prefix sum as key and no. of subarrays with same prefix sum as value. Here we can increae the count if two or more subarrays have the same prefix sum.

// M-3) Prefix Sum --> T.C: O(n) or O(n*logn) depending on type of map; S.C: O(n) 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> preSumCount;  // map to store Prefix Sum as key and no. of subarrays 
        int sum = 0;                // having the same prefix sum as value  
        int count = 0;  // total count

        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(sum == k){
                count++;
            }

            int rem = sum - k;

            if(preSumCount.find(rem) != preSumCount.end()){
                count += preSumCount[rem]; // Add the count of subarrays with sum equal to rem
            }
            
            // No need to check if(preSumCount.find(rem) == preSumCount.end())
            preSumCount[sum]++; // Update the count of the current prefix sum
        }

        return count;
        
    }
};


// M-3) Prefix Sum (Striver)  --> T.C: O(n) or O(n*logn); S.C: O(n) 
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;  // map to store Prefix Sum as key and no. of subarrays 
        int count = 0, sum = 0;

        m[0] = 1; // store the subarrays with prefix sum = 0 

        for(int i = 0; i < n; i++){
            sum += nums[i];     // add current element to prefix Sum
            int rem = sum - k;  // calculate remaining sum to be searched in predix sum map
            count += m[rem];    // if sum == k, then rem = 0 and m[0] = 1 initially.
                                // if rem is not found in map m, then m[rem] = 0 by default
            m[sum]++;
        }

        return count;
        
    }
};
*/
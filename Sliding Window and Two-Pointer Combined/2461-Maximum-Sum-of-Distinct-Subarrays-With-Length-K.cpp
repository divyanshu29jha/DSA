// Reference: https://www.youtube.com/watch?v=8QPkdFLODC4
// T.C: O(n), S.C: O(k) for storing k elements in map
// Using an ordered map, the time complexity of the solution is 𝑂(𝑛log⁡𝑘).
// Eg: [2,4,2,2,4,5,3] and k=3
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0, sum = 0;
        unordered_map<int,int> m;    // num[i] as key and its frequency as value

        for(int i=0; i<n; i++){
            if(i >= k){   // start subtracting first element of window if i>=k (k is window size)
                sum -= nums[i-k];
                m[nums[i-k]]--;    // decrease frequency

                if(m[nums[i-k]] == 0){   // if i-th element frequency is 0 then erase that element otherwise it will be counted in m.size()
                    m.erase(nums[i-k]);
                }
            }
            
            sum += nums[i];
            m[nums[i]]++;            
            if(m.size() == k){  // if size == k means all elements are unique
                    maxSum = max(sum, maxSum);    // update maxSum only if all elements in the window are unique
            }             
        }

        return maxSum;
    }
};
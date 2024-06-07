// If there are no 0's in the array, then it is always possible to reach the last index.
// If it is possible to cross the 0 by jumping, then also it will always be possible to reach the last index.

// A greedy approach can be effective for this problem. The idea is to keep track of the maximum reachable index (maxReach) that can be reached as we iterate through the array.
// If we can reach or cross the last index using maximum jump greedy approach for each index, then we can always reach the last index.
// If at any point, the current index (i) exceeds the maximum reachable index (maxReach), it means you cannot move further and hence, return false.
// Eg: nums = [1,2,4,1,1,0,2,5] --> true, nums = [1,2,3,1,1,0,2,5] --> false at i = 6, maxReach = 5 and i > maxReach.

class Solution {
public:
    bool canJump(vector<int>& nums) {     // T.C: O(n), S.C: O(1)
        int n = nums.size();
        int maxReach = 0;
        
        for (int i=0; i<n; i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            
            // if (maxReach >= n - 1) {      // Only for optimization, not compulsory
            //     return true;
            // }
        }
        
        // return false;
        return true;
    }
};
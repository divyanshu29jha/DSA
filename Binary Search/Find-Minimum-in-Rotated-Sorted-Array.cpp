// The minimum may lie in sorted half or may lie in unsorted half.
// Find whether left half or right half of mid is sorted. Then take the min from that sorted half and eliminate the search space to the other half. 
// In  if(nums[low] <= nums[mid]), always take <= sign and not just < to check if left part is sorted: Take eg: [2,1] & dry run to understand.

// M-1) Binary Search --> T.C: O(logn), S.C: O(1)
/*
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[low] <= nums[mid]){     // left half is sorted:
                ans = min(nums[low], ans);    // store the minimum
                low = mid + 1;   // eliminate left half
            }
            else{       // right half is sorted:
                ans = min(nums[mid], ans);    // store the minimum
                high = mid - 1;  // eliminate right half
            }
        }

        return ans;
    }
};
*/

// M-2) More improved version of M-1 --> T.C: O(logn), S.C: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high) / 2;

            // search space is already sorted then nums[low] will always be the minimum in that search space:
            if (nums[low] <= nums[high]) {  // eg: nums = {1,2,3,4,5}. It is rotated 5 times and appears fully sorted.
                ans = min(ans, nums[low]);
                break;
            }

            if(nums[low] <= nums[mid]){     // left half is sorted:
                ans = min(nums[low], ans);    // store the minimum
                low = mid + 1;   // eliminate left half
            }
            else{       // right half is sorted:
                ans = min(nums[mid], ans);    // store the minimum
                high = mid - 1;  // eliminate right half
            }
        }

        return ans;
    }
};
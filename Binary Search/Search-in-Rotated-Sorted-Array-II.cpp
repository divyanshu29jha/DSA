// It's important to check whether left half or right half of mid is sorted so that target can be compared accordingly.
// For eg: nums = [6,0,1,2,3,4,5], target = 0. Here, mid = 2 and right half of mid is sorted since 2 <= 5, so check if target 0 lies there i.e 2 <= 0 <= 5. It's false, so check in left half by doing high = mid - 1.
// Always take <= sign and not just < to check if left part is sorted: Take eg: [2,1] & dry run to understand.
// Edge Case (when duplicates present) : if nums[low] == nums[mid] == nums[high], we cannot check whether left half or right half of mid is sorted. Eg: {3,1,2,3,3,3,3} and target = 2.

// T.C: O(log n) for the best and average case. O(n/2) for the worst case, S.C: O(1)
// For eg: {3, 3, 3, 3, 3, 3, 3} and target = 4, we continue to reduce the search space by adjusting the low and high pointers until they intersect. This worst-case situation incurs a time complexity of O(n/2).
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        bool found = false;
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){    // if mid points the target
                found = true;
                break;
            }

            
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {   // Edge case: {3,1,2,3,3,3,3} and target = 2
                low = low + 1;           
                high = high - 1;
                continue;
            }

            if(nums[low] <= nums[mid]){  // if left part is sorted:
                if(nums[low] <= target && target <= nums[mid]){     // target exist on left half of mid
                    high = mid - 1;
                }
                else{
                    low = mid + 1;  // target exist on right half of mid
                }
            }
            else{   // if right part is sorted:
                if(nums[mid] <= target && target <= nums[high]){    // target exist on right half of mid
                    low = mid + 1;
                }
                else{
                    high = mid - 1;     // target exist on left half of mid
                }
            }
        }

        return found;
    }
};
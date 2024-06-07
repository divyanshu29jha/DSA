// It's important to check whether left half or right half of mid is sorted so that target can be compared accordingly.
// For eg: nums = [6,0,1,2,3,4,5], target = 0. Here, mid = 2 and right half of mid is sorted since 2 <= 5, so check if target 0 lies there i.e 2 <= 0 <= 5. It's false, so check in left half by doing high = mid - 1.
// Always take <= sign and not just < to check if left part is sorted: Take eg: [2,1] & dry run to understand.

// T.C: O(log n), S.C: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = -1;
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){    // if mid points the target
                index = mid;
                break;
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

        return index;
    }
};
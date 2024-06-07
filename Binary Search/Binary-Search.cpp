// Binary Search is possible only in sorted array.
// If search space is from 0 to INT_MAX, then if suppose both low and high point at INT_MAX (last element) in worst case. Then, mid = (high+low)/2 will lead to integer overflow. To solve this :
// 1) Use long long for storing mid
// 2) Use mid = low + (high - low) / 2      [as (high - low) will become 0 then]

// M-1) Iterative approach --> T.C: O(log n); S.C: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;    // OR mid = low + (high - low) / 2 
            
            if(nums[mid] == target)
                return mid;
            else if (target > nums[mid]) 
                low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
};


// M-1) Recursive approach --> T.C: O(log n); S.C: O(1)
/*
int binarySearch(vector<int>& nums, int low, int high, int target) {

    if (low > high)  // Base case
        return -1; 

    int mid = (low + high) / 2;
    
    if (nums[mid] == target) 
        return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    else
        return binarySearch(nums, low, mid - 1, target);
}
*/
// M-1) Brute force (linear search) --> T.C: O(n); S.C: O(1)
/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int peak;
        if(n == 1){
            peak = 0;
        }
        else{
            if(nums[0] > nums[1])
                peak = 0;
            if(nums[n-1] > nums[n-2])
                peak = n-1;

            for(int i = 1; i < n-1; i++){
                if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                    peak = i;
                    break;
                }
            }
        }

        return peak;
    }
};
*/

// M-2) Another way to write M-1 --> T.C: O(n); S.C: O(1)
/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int peak;
        for (int i = 0; i < n; i++) {   // Checking for the peak:
            if ((i == 0 || nums[i-1] < nums[i]) && (i == n-1 || nums[i] > nums[i+1])) {
                peak = i;
                break;
            }
        }

        return peak;
    }
};
*/

// M-3) Binary Search -->T.C: O(log n), S.C: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // Edge cases:
        if (n == 1) 
            return 0;
        if (nums[0] > nums[1]) 
            return 0;
        if (nums[n-1] > nums[n-2]) 
            return n-1;

        int low = 1, high = n-2;
        while(low <= high){
            int mid = (low + high) / 2;

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])    // If nums[mid] is the peak
                return mid;

            // If we are in the left (i.e mid is on increasing slope), so eliminate the left half since atleast one 
            // peak will lie on the right half.
            if (nums[mid] > nums[mid - 1])   
                low = mid + 1;
            // If we are in the right (i.e mid is on decreasing  slope) Or, nums[mid] is a common point (trough), 
            // so eliminate the right half since atleast one peak will lie on the left half.
            else high = mid - 1;    // trough edge case: nums = {1,2,1,3,1}. Here numd[mid] = 2 which is trough.
        }             // So, atleast one peak will lie on both left and right half. better eliminate the right half.
        
        return -1;
    }
};




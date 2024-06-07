// M-1) Linear Search --> T.C: O(n); S.C: O(1)
/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans;
        for(int i = 0; i < n; i++){
		    if (nums[i] >= target) {	 // lower bound found  (return the first index)
                ans =  i;
                break;
            }
	    }

        return ans;
    }
};
*/

// M-2) Find lower bound --> T.C: O(logn); S.C: O(1)
/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = n;    // store n initially for the case that if index not exists in the array
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= target){    // maybe an answer but we need to find the smallest index
                ans = mid;
                high = mid - 1;     // look for smaller index on the left of mid
            }
            else{
                low = mid + 1;      // look on the right of mid
            }   
        }

        return ans;
    }
};
*/

// M-3) Using STL lower_bound --> T.C: O(logn); S.C: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();    // to return the index
    }
};



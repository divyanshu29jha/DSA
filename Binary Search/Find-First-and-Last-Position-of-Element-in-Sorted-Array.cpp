// M-1) Brute force (Linear search) -->  T.C: O(2*n); S.C: O(n) for ans
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);   // Initialize the vector with size 2 and values -1
        
        for(int i = 0; i < n; i++){     // first occurence
            if(nums[i] == target){
                ans[0] = i;
                break;
            }
        }
        for(int i = n-1; i >= 0; i--){  // last occurence
            if(nums[i] == target){
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};
*/


// M-2) Brute force (Linear search) -->  T.C: O(n); S.C: O(n) for ans
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        int ind1 = -1, ind2 = -1;
        for(int i = 0; i < n; i++){     
            if(nums[i] == target && ind1 == -1){    // first occurence
                ind1 = i;
            }

            if(nums[i] == target && ind1 != -1){    // last occurence
                ind2 = max(ind2, i);
            }
        }

        ans.push_back(ind1);
        ans.push_back(ind2);
        return ans;
    }
};
*/


// M-3) Binary Search --> T.C: O(logn); S.C: O(n) for ans
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;  
        int first = -1, last = -1;

        int low = 0, high = n-1;
        while(low <= high){     // search first ocuurence of target
            int mid = (low + high)/2;

            if(nums[mid] == target){
                first = mid;        // since array is sorted,   eg: [5,7,8,8,8,9,10] & target = 8
                high = mid - 1;     // search in left of mid to get first occurence of target, if exists
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        low = 0, high = n-1;
        while(low <= high){     // searh last ocuurence of target
            int mid = (low + high)/2;

            if(nums[mid] == target){
                last = mid;        // since array is sorted,   eg: [5,7,8,8,8,9,10] & target = 8
                low = mid + 1;     // search in right of mid to get last occurence of target, if exists
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
*/

// M-3) Lower & upper bound --> T.C: O(logn); S.C: O(1)
/*
class Solution {
public:
    int lowerBound(vector<int> arr, int x) {
        int n = arr.size();
	    int low = 0, high = n-1;
	    int ans = n;   // store n initially for the case that if index not exists in the array

	    while(low <= high){
		    int mid = (low + high) / 2;

		    if(arr[mid] >= x){	// maybe an answer but we need to find the smallest index
			    ans = mid;
			    high = mid - 1; // look for smaller index on the left
		    }
		    else{
			    low = mid + 1;  // look on the right
		    }
	    }

	    return ans;
    }

    int upperBound(vector<int> arr, int x) {
        int n = arr.size();
	    int low = 0, high = n - 1;
        int ans = n;  // Initialize ans to n for the case where no element is greater than or equal to x

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] > x) { // Maybe an answer but we need to find the smallest index
                ans = mid;
                high = mid - 1; // Look for a smaller index on the left
            } 
            else {
                low = mid + 1;  // Look on the right
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        
        if(lb == n || nums[lb] != target){  // check if target actually exists or not in nums
            return {-1,-1};
        }
        else{
            return {lb, ub - 1};
        }
        
    }
};
*/

// M-5) Using STL for lower and upper bound  --> T.C: O(log n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        auto lower = lower_bound(nums.begin(), nums.end(), target);  // stores the iterator
        int lb = lower - nums.begin();     // subtract v.begin() to get lower bound index 
        
        auto upper = upper_bound(nums.begin(), nums.end(), target);   // stores the iterator
        int ub = upper - nums.begin();     // subtract v.begin() to get upper bound index 

        if(lb == n || nums[lb] != target){  // check if target actually exists or not in nums
            return {-1,-1};
        }
        else{
            return {lb, ub - 1};
        }
        
    }
};


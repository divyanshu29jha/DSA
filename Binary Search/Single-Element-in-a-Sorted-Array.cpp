// M-1) Brute force (Linear Search)--> T.C: O(n), S.C: O(1)
/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int single = -1;

        for(int i = 0; i < n - 1; i += 2){      // i = i + 2 after each itertation
            if(nums[i] != nums[i+1]){
                single = nums[i];
                break;
            }

        }

        if(single == -1)      // Check for last index:
            single = nums[n-1];

        return single;
    }
};
*/


// M-2) Brute force (Map) --> T.C: O(n), S.C: O(m) where m is size of the map and m = (n/2)+1.
/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int single;

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {   // O(n) for n elements 
                m[nums[i]]++;   // O(1) for single element insertion
        }

        for (auto it : m) {
            if (it.second == 1){
                single = it.first;
                break;
            }   
        }

        return single;
    }
};
*/


// M-3) Brute force (XOR)  --> T.C: O(n), S.C: O(1)
/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;

        for(int i = 0; i < n; i++){     // XOR all the elements:
            xorr = xorr ^ nums[i];
        }

        int single = xorr;
        return single;
    }
};
*/


// NOTE 1: The index sequence of the duplicate numbers in the left half is always (even, odd). 
// If (i % 2 == 0 and nums[i] == nums[i+1]) or (i%2 == 1 and nums[i] == nums[i-1]), we are in the left half.
// If we are in the left half of the single element, we have to eliminate this left half (i.e. low = mid+1). Because our single element appears somewhere on the right side.

// NOTE 2: The index sequence of the duplicate numbers in the right half is always (odd, even). 
// If (i % 2 == 0 and nums[i] == nums[i-1]) or (i%2 == 1 and nums[i] == nums[i+1]), we are in the right half.
// If we are in the right half of the single element, we have to eliminate this right half (i.e. high = mid-1). Because our single element appears somewhere on the left side.

// Eg: nums = {1,1,2,2,3,3,4,5,5,6,6} for dry run.

// M-4) Optimal approach (Binary Search)  --> T.C: O(log n), S.C: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int single;
        
        // Edge cases:
        if(n == 1)
            return nums[0];
        if(nums[0] != nums[1])  // single element present on 0th index
            return nums[0];
        if(nums[n-1] != nums[n-2])  // single element present on last index
            return nums[n-1];

        int low = 1, high = n-2;
        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){    // if nums[mid] is single element
                single = nums[mid];
                break;
            }

            if((mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 == 1 && nums[mid] == nums[mid-1])) { // we are in the left
                low = mid + 1;  // eliminate the left half
            }
            else{   // we are in the right
                high = mid - 1;    // eliminate the right half
            }
        }
    
        return single;
    }
};
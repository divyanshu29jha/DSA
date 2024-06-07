// M-1) Brute force (Nested for-loop) --> T.C: O(N^2)
/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int miss, tempK = 0;
        bool foundK = false;

        for(int i = 1; i <= 2000; i++){     
            bool found = false;
            for(int j = 0; j < arr.size(); j++){
                if(i == arr[j]){
                    found = true;
                }
            }

            if(!found){
                tempK++;
                if(tempK == k){
                    miss = i;
                    break;
                }
            }
        }

        return miss;
    }
};
*/


// Ideally, kth missing no. will be k if no elements are present in arr that are less than k (i.e if nothing was missing.
// Whichever no. in arr is less than k, then that no. will increase the value of kth missing no. by one digit.
// Note: The main idea is to shift k by 1 step if the current element is smaller or equal to k. And whenever we get a number > k, we can conclude that k is the missing number.

// M-2) Brute force (Linear traversal) --> T.C: O(N)
/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) 
                k++;   // shifting k
            else 
                break;
        }
        
        return k;
    }
};
*/

// Keep track of how many positive numbers are missing as you scan the array.
// After the end of binary search, high will cross low, and kth missing no. will lie between arr[high] and arr[low]

// M-3) Binary Search --> T.C: O(log N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;

            int missing = arr[mid] - (mid+1);
            if(missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        } 

        // int missTillHigh = arr[high] - (high + 1);
        // int more = k - missTillHigh;
        // int kthMiss = arr[high] + more;

        return k + high + 1;  // k + low
    }
};
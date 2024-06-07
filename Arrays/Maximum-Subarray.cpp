// M-1) Brute force (find sum of all possible subarrays)  --> T.C: O(n^2) + O(n), S.C: O(n)
// WARNING : Gives TLE as 1 <= nums.length <= 10^5 and T.C is O(n^2)
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> subSum;
        int maxSum = INT_MIN;
        
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum > maxSum)
                    maxSum = sum;   // maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
*/


// A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
// M-2) Kadane's Algorithm  --> T.C: O(n), S.C: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;

        // int start = -1, end = -1;  // starting and ending index of subarray with max sum

        for(int i = 0; i < n; i++){

            // if (sum == 0)    // if sum == 0, then subarray will start from the next index
            //    start = i; 

            sum += nums[i];

            if(sum > maxSum){
                maxSum = sum;
                // end = i;     // each time maxSum is updated, the size of subarray will increase
            }

            if (sum < 0) {  // If sum < 0, discard the sum calculated
                sum = 0;
            }
        }

        return maxSum;        
    }
};

// printing the subarray with max sum:
    // cout << "The subarray with max sum is: [";
    // for (int i = start; i <= end; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << "]";
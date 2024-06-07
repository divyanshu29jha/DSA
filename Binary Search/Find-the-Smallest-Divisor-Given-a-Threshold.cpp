// M-1) Brute force (linear search) --> Gives TLE
// T.C: O(max(nums[])*N), where max(nums[]) = maximum element in the array, N = size of the array.
/*
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());
        
        for(int i = 1; i <= maxi; i++){     // Find the smallest divisor
            int sum = 0;
            for(int j = 0; j < nums.size(); j++){   // Find the summation result
                int num = ceil(double(nums[j]) / double(i));
                sum += num;
            }

            if(sum <= threshold)
                return i;
        }

        return -1;
    }
};
*/


// M-2) Binary Search 
// T.C: O(log(max(nums[])) * N), where max(nums[]) = maximum element in the array, N = size of the array.
class Solution {
public:
    int findSum(vector<int>& v, int divisor) {
        int sum = 0;
        for(int i = 0; i < v.size(); i++){   // Find the summation result
            int num = ceil(double(v[i]) / double(divisor));
            sum += num;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        int maxi = *max_element(nums.begin(), nums.end());
        
        int low = 1, high = maxi;
        while(low <= high){
            int mid = (low + high) / 2;

            int sum = findSum(nums, mid);
            if(sum <= threshold){
                ans = mid;  // mid may be ans. But search for smaller divisor than mid. 
                high = mid - 1;   // If divisor decreases, then sum increases. So check till sum <= threshold.
            }
            else{
                low = mid + 1;
            }
        }

        // return low;
        return ans;
    }
};
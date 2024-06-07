// M-1) Brute force --> T.C: O(nlogn) + O(n); S.C: O(n)  [all 3 for loops together have T.C of O(n)]
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;  // element as key and its frequency as value

        for(auto num : nums){
            m[num]++;
        }

        for(int i = 0; i < m[0]; i++){      // m[0] has frequnecy of 0
            nums[i] = 0;
        }

        for(int i = m[0]; i < m[0] + m[1]; i++){      // m[1] has frequnecy of 1
            nums[i] = 1;
        }

        for(int i = m[0] + m[1]; i < m[0] + m[1] + m[2]; i++){      // m[2] has frequnecy of2
            nums[i] = 2;
        }
    }
};
*/


// M-2) Better approach --> T.C: O(n) + O(n); S.C: O(1)
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n = nums.size();
       int cnt0 = 0, cnt1 = 0, cnt2 = 0;
       for(int i = 0; i < n; i++){
            if (nums[i] == 0) 
                cnt0++;
            else if (nums[i] == 1) 
                cnt1++;
            else 
                cnt2++;
       }

       //Replace the places in the original array:
        for (int i = 0; i < cnt0; i++)  // replacing 0's
            nums[i] = 0; 

        for (int i = cnt0; i < cnt0 + cnt1; i++)  // replacing 1's
            nums[i] = 1; 

        for (int i = cnt0 + cnt1; i < n; i++)   // replacing 2's
            nums[i] = 2; 
    }
};
*/


// This algorithm contains 3 pointers i.e. low = 0, mid = 0, and high = n-1. The rules are the following:
// nums[0...low-1] contains 0
// nums[low...mid-1] contains 1
// nums[mid...high] is the unsorted segment
// nums[high+1...n-1] contains 2, n = size of the array.

// M-3) Dutch National flag algorithm  --> T.C: O(n); S.C: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n = nums.size();
       int low = 0, mid = 0, high = n - 1;  // 3 pointers

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{   // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};
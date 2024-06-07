// M-1) Brute Force: Finding all possible permutations, T.C: O(n!xn). (In Recursion playlist of striver)


// M-2) Using STL --> O(n) time to find the next permutation
/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        next_permutation(nums.begin(), nums.begin()+n);//using in-built function of C++
    }
};
*/


// Eg: nums = [2,1,5,4,3,0,0]. Here break point is at index 1 since 1 < 5. So, swap 3 and 1. Now reverse the remaining portion from index+1 to end [2,3, || 5,4,1,0,0] --> [2,3,0,0,1,4,5].
// if we look at the array in the backward direction, it is sorted in increasing order up to index i (from n-1 to index i+1). The difference between the next and current permutation always starts at the index i i.e. the break-point.

// M-3) Two Pointers --> T.C: O(3n) Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each, where N is the number of elements in the input array; S.C: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;     // break point

        // Step 1: Find the break point:
        for(int i = n-2; i >= 0; i--){    
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        // reverse the whole array as nums does not have a lexicographical larger rearrangement.
        if (index == -1) {   // If break point does not exist, eg: when nums = [5,4,3,2,1,0,0]
            reverse(nums.begin(), nums.end());   
        }
        else{
            // Step 2: Find the next greater element and swap it with nums[index]:
            for(int i = n - 1; i > index; i--){
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
            // Step 3: reverse the right half:
            reverse(nums.begin()+index+1, nums.end());  // O(n)
        }

    }
};


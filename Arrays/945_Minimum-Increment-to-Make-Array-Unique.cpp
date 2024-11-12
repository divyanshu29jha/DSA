// Method-1 (Sorting)
// T.C: O(nlogn) + O(n) 
// In the worst case, the inner while loop can make a large number of increments, but each increment operation is constant time. 
/*
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // O(nlogn)
        int moves = 0;
        for(int i=1; i<nums.size(); i++){   // O(n)
            while(nums[i] <= nums[i-1]){    // NOT O(n)  
                nums[i]++; 
                moves++;
            }
        }

        return moves;
    }
};
*/


// Method-1 (Leetcode Editorial - Sorting)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int minIncrements = 0;

        sort(nums.begin(), nums.end());

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {   // Ensure each element is greater than its previous
                
                int increment = nums[i-1] + 1 - nums[i];  // Add the required increment to minIncrements
                minIncrements += increment;

                nums[i] = nums[i-1] + 1;   // Set the element to be greater than its previous
            }
        }

        return minIncrements;
    }
};







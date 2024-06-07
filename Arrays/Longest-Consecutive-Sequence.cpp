// M-1) Brute force (Gives TLE) --> T.C: O(n^2), S.C: O(1)
/*
class Solution {
public:
    bool linearSearch(vector<int>& nums, int target){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        int longest = 1;
        
        for(int i = 0; i < nums.size(); i++){   
            int x = nums[i];   // pick a element and search for its consecutive numbers
            int count = 1;
            
            while(linearSearch(nums, x+1)){   // O(n)
                x++;
                count++;
            }
            
            longest = max(longest, count);
        }

        return longest;    
    }
};
*/


// M-2) Better Approach(Using sorting) --> T.C: O(nlogn) + O(n), S.C: O(1)
// Corner cases --> When size of array is 0; Sorted array can contain duplicates; Handle the case when the longest sequence is the array itself
/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxCount = 1;   // length of longest consecutive sequence

        if(n == 0){
            return 0;
        }
        else{
            int count = 1;
            for(int i = 1; i < n; i++){
                if (nums[i - 1] == nums[i]){   // Skip duplicates
                    continue;  
                }

                if (nums[i - 1] + 1 == nums[i]){
                    count++;
                } 
                else{   // eg: [1,2,3,4,5], then else will never be executed. So, write again.
                    maxCount = max(maxCount, count);
                    count = 1;
                }
            }

            // Handle the case when the longest sequence is the array itself, eg: [1,2,3,4,5]
            maxCount = max(maxCount, count);  
        }

        return maxCount;
    }
};
*/

// M-3) Optimal Approach(Using Set) --> T.C: O(n) + O(2*n) ~ O(3*n), S.C: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 1;   // length of longest consecutive sequence
        unordered_set<int> s;

        if (n == 0){
            return 0;
        }

        for (int i = 0; i < n; i++) {   // O(n) // put all the array elements into set:
            s.insert(nums[i]);
        }

        for(auto it : s){   //O(2*n)
            if (s.find(it - 1) == s.end()) {   // if 'it' is a starting number of sequence:
                int count = 1;                 // i.e number 'it - 1' does not exist in set
                int x = it;
                
                while (s.find(x + 1) != s.end()) {    // find consecutive numbers:
                    x++;                                
                    count++;
                }
                
                maxCount = max(maxCount, count);
            }   
        }
        
        return maxCount;
    }
};


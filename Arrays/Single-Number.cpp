// M-1) Brute force (map) --> T.C: O(n), S.C: O(m) where m is size of the map and m = (n/2)+1.
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
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
// NOTE: Avoid using hashing as there can be negative numbers in nums




// M-2) Brute force (Sort & compare previous element)  --> T.C: O(nlogn) + O(n), S.C: O(1)
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int single = nums[0];

        sort(nums.begin(), nums.end());

        int i = n-1;
        while(i >= 0){
            if(i-1 >= 0 && nums[i] == nums[i-1]){
                i -= 2;
            }
            else{
                single = nums[i];
                break;
            }
        }

        return single;
    }
};
*/


// M-3) Optimal approach (XOR)  --> T.C: O(n), S.C: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;

        for(int i = 0; i < n; i++){     // XOR all the elements:
            xorr = xorr ^ nums[i];
        }

        int single = xorr;
        return single;
    }
};
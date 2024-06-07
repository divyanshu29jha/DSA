// M-1) Brute force --> Gives TLE 
// T.C: O(n^4 * log(no. of unique triplets)), where n = size of the array.
// S.C: O(2 * no. of the unique triplets), for storing in set s and vector ans.
/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;  // set of vectors (as duplicate triplets not allowed)

        for (int i = 0; i < n; i++) {    // check all possible triplets
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    for (int l = k+1; l < n; l++) {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            s.insert(temp); // set stores unique triplets (provided they are sorted before)
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());  //store the set elements in the answer
        
        return ans;
    }
};
*/


// M-2) Hasing and 3-Sum.
// T.C: O(n^3*log(m)), where n = size of the array, m = no. of elements in the set.
// S.C: O(2 * no. of the quadruplets) + O(n), for storing in set s and vector ans. Extra O(n) for storing the array elements in map.
// unordered_map must be inside the first for-loop since we generate it for each iteration for elements >i.
/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){   // use 3-Sum method from here
                set<long long> hashset;  // stores no. as key for using later (hashing)

                for(int k = j+1; k < n; k++){   // use 2-Sum method from here
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
                    long long rem = (long long)target - sum;  // Calculate the 4rd element

                    if(hashset.find(rem) != hashset.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)rem};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);   // O(log(no. of unique triplets))
                    }

                    hashset.insert(nums[k]);
                }
            }      
        }

        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
    }
};
*/


// M-4) Two-pointer and 2-Sum technique. But without extra space or using set.
// T.C: O(nlogn)+O(n^3), here O(nlogn) for sorting nums and O(n^3) for the two for-loops.  S.C: O(1).
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());   // O(nlogn)

        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;    // avoid the duplicates while moving i:
                
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // avoid the duplicates while moving j:
                   
                int k = j + 1;  // 2 pointers k and l
                int l = n - 1; 
                while(k < l){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    if(sum < target){
                        k++; 
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1])   //skip the duplicates
                            k++;
                        while(k < l && nums[l] == nums[l+1])   //skip the duplicates
                            l--;
                    }   
                }
            }
        }

        return ans;
    }
};
// M-1) Brute force --> T.C: O(n^2), S.C: O(1) 
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                int sum = nums[i] + nums[j];

                if(sum == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};
*/


// M-2) Hasing --> T.C: O(n*logn) for map or O(n) for unordered_map, S.C: O(n) for map m
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> m;  // current no. as key and index as value

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int rem = target - num;

            if(m.find(rem) != m.end()){
                ans.push_back(i);
                ans.push_back(m[rem]);
            }

            m[num] = i;     //O(logn) for ordered map and O(1) for unordered_map
        }

        return ans;
    }
};


// M-3) Hasing --> T.C: O(n*logn)+O(n) for map or O(n)+O(n) for unordered_map, S.C: O(n) for map m
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> m;  // current no. as key and index as value
        for(int i = 0; i < n; i++){
            m.insert({nums[i], i});
        }

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int rem = target - num;

            if(m.find(rem) != m.end() && m[rem] < i){    // m[rem] is the index of the 2nd no.
                ans.push_back(i);
                ans.push_back(m[rem]);
            }
        }

        return ans;
    }
};
*/



// M-4) Two-pointer (Greedy) approach --> T.C: O(n) + O(n*logn), S.C: O(n) for vector<pair<int, int>>
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numsIndex;
        for(int i = 0; i < n; i++){ // O(n)
            numsIndex.push_back({nums[i], i});
        }

        sort(numsIndex.begin(), numsIndex.end()); // O(n*logn) Sorts on basis on first value in pair i.e nums[i]
        vector<int> ans;
        int left = 0, right = n-1;

        while(left < right){    // O(n)
            int sum = numsIndex[left].first + numsIndex[right].first;

            if (sum == target) {
                ans.push_back(numsIndex[left].second);     // numsIndex[left].second stores index as in nums
                ans.push_back(numsIndex[right].second);
                break;
            } else if (sum < target) {
                left++;
            } else { // sum > target
                right--;
            }
        }
        
        return ans;
    }
};
*/




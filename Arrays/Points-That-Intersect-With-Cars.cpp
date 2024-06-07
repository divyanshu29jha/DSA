// M-1) Brute force --> T.C: O(N^2 * log N), S.C: O(unique elements)
/*
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){   // O(N^2)
            int first = nums[i][0];
            int second = nums[i][1];

            while(first <= second){
                s.insert(first);    // log N
                first++;
            }

        }

        return s.size();
    }
};
*/


// M-2) Merge Intervals --> O(N*logN) + O(N)
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // O(n logn)
        
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){     // O(n)
            // if the current interval does not lie in the last interval:
            if(ans.empty() || nums[i][0] > ans.back()[1]){
                ans.push_back(nums[i]);
            }
            // if the current interval lies in the last interval:
            else{
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
        }

        int points = 0;
        for(int i = 0; i < ans.size(); i++){
            points += ans[i][1] - ans[i][0] + 1;
        }
        return points;
    }
};


// M-1) T.C: O(n + n/2) { O(n) for traversing the array once for segregating positives and negatives and another O(n/2) for adding those elements alternatively to the array }; S.C: O(n/2 + n/2) for pos and neg vectors.
/*
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        for(auto num : nums){
            if(num > 0)   
                pos.push_back(num);
            else 
                neg.push_back(num);
        }

        for(int i = 0; i < n/2; i++){     // merge two arrays even and odd
            nums[i*2] = pos[i];
            nums[i*2 + 1] = neg[i];
        }

        return nums;
    }
};
*/

// M-2) Optimal approach --> T.C: O(N), S.C: O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int pos = 0, neg = 1;   // two-pointers in ans

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{    // nums[i] > 0
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;        
    }
};
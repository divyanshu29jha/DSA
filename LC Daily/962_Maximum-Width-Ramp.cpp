// Approach-1 (Using brute force) - Passes 95/101 test cases
// T.C : O(n^2)
// S.C : O(1)
/*
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ramp = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(nums[i] <= nums[j]) 
                    ramp = max(ramp, j - i);
            }
        }
        return ramp;
    }
};
*/


// Approach-2 (early termination) - Passes 97/101 test cases
// T.C : O(n^2) in worst case
// S.C : O(1)
/*
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        int ramp = 0;
        for(int i = 0; i < n; i++){
            for(int j = n-1; j > i; j--){
                if(nums[i] <= nums[j]){
                    ramp = max(ramp, j-i);
                    break;
                }
            }
        }
        return ramp;
    }
};
*/


// Approach-3 : Two Pointer (Making use of hint from Approach-2, storing max to the right)
// T.C : O(n)
// S.C : O(n)
/*
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxRight(n);
        
        maxRight[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            maxRight[i] = max(maxRight[i+1], nums[i]);
        }

        int ramp = 0;
        int i = 0, j = 0;
        while(j < n){
            if(maxRight[j] >= nums[i]){
                ramp = max(ramp, j-i);
                j++;
            } 
            else{
                i++;
            }
        }

        return ramp;
    }
};
*/

// Approach-4 : Custom Sorting
// T.C : O(n*logn)
// S.C : O(n)
/*
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);

        for(int i = 0; i < n; i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int i, int j){   // Sort indices based on corresponding values in nums and ensure stability
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });

        int minLeft = INT_MAX;
        int ramp = 0;
        for(int i = 1; i < n; i++){    // similar to 121. Best Time to Buy and Sell Stock
            minLeft = min(minLeft, indices[i-1]);
            ramp = max(ramp, indices[i] - minLeft);
        }

        return ramp;
    }
};
*/


// Approach-5 : Monotonic Stack 
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i = 0; i < n; i++){    // stack formation with indices
            if(st.empty() || nums[i] < nums[st.top()]) 
                st.push(i);
        }

        int ramp = 0;
        for(int j = n-1; j >= 0; j--){
            while(!st.empty() && nums[j] >= nums[st.top()]){
                ramp = max(ramp, j - st.top());
                st.pop();
            }
        }
        
        return ramp;
    }
};



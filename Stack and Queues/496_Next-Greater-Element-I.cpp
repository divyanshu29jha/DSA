// M-1) Brute force 
// T.C: O(n^2), S.C: O(n)
/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1); 
        for(int i = 0; i < nums1.size(); i++){
            int j = 0;
            while(nums2[j] != nums1[i]){
                j++;
            }
            
            for(int k = j + 1; k < nums2.size(); k++){  // search for the next greater element 
                if(nums2[k] > nums1[i]){
                    ans[i] = nums2[k];
                    break;
                }
            }
        }

        return ans;
    }
};
*/

// M-2) NGE using Monotonic Stack (striver)
// Monotonically decreasing stack
// T.C: O(nums1.length + nums2.length), S.C: O(n) (for nge, st, ans, mpp)
// The while loop inside the for loop pops elements from the stack. However, each element in the array can be pushed and popped from the stack only once during the entire execution of the algorithm. Therefore, the total number of push and pop operations combined across all iterations is at most n. This makes the time complexity for the entire algorithm O(n).
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size());    // calculate nge vector for nums1
        stack<int> st;
        unordered_map<int,int> mpp;   // stores nums2 elements as key and index as value
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();

            st.push(nums2[i]);

            mpp[nums2[i]] = i;
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int idx = mpp[nums1[i]];   
            ans.push_back(nge[idx]);
        }

        return ans;
    }
};
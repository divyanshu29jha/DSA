// Approach 1: Brute Force (using Double Length Array) [Time Limit Exceeded]
// we make use of an array doublenums which is formed by concatenating two copies of the given nums array one after the other.
// T.C : O(n^2). The complete doublenums array(of size 2n) is scanned for all the elements of nums in the worst case.
// S.C : O(n). doublenums array of size 2n is used. ans array of size n is used.
/*
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<int> doublenums(2 * n);

        for (int i = 0; i < n; ++i) {
            doublenums[i] = nums[i];
            doublenums[i + n] = nums[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < 2 * n; ++j) {
                if (doublenums[j] > doublenums[i]) {   
                    ans[i] = doublenums[j];
                    break;
                }
            }
        }

        return ans;
    }
};*/


// Approach 2: Better Brute Force - Circular array concept (hypothetically double the array using indices) [Accepted]
// T.C : O(n^2). The complete nums array of size n is scanned for all the elements of nums in the worst case.
// S.C : O(n). ans array of size n is used.
/*
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j <= i+n-1; j++){
                if(nums[j%n] > nums[i]){
                    ans[i] = nums[j%n];
                    break;
                }
            }
        }

        return ans;
    }
};
*/


// Approach 3: Using Stack (hypothetically double the array using indices)
// Monotonically decreasing stack
// T.C : O(4*n). Only two traversals of the nums array are done. Further, at most 2n elements are pushed and popped from the stack.
// S.C : O(n). A stack of size n is used. ans array of size n is used.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = 2*n-1; i >= 0; i--){   // hypothetically double the array using indices
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();  // O(2*n) for 2n elements
            }

            if(i < n){
                // if(st.empty()) nge[i] = -1;
                // else nge[i] = st.top();
                st.empty() ? nge[i] = -1 : nge[i] = st.top();
            }

            st.push(nums[i%n]);  // O(2*n) for 2n elements
        }

        return nge;
    }
};


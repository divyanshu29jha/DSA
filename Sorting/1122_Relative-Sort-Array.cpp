// M-1) Brute force
// 1. Traverse arr1 and for each element in arr2, append matching elements from arr1 to the result.
// 2. Mark appended elements in arr1 to avoid duplicates.
// 3. Append remaining elements from arr1 to the result and sort them.
// T.C: O(n1*n2) = O(n1*n2) + O(n1) + O(n1*logn1).
// S.C: O(n). Space for ans vector, in the worst case will be n1 elements long. Space used by the sort function will be O(n).
/*
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> ans;

        for(int i = 0; i < n2; i++){    // O(n1*n2)
            for(int j = 0; j < n1; j++){
                if(arr1[j] == arr2[i]){
                    ans.push_back(arr1[j]);
                    arr1[j] = -1;
                }
            }
        }

        int n = ans.size();
        for(int i = 0; i < n1; i++){   // O(n1)
            if(arr1[i] != -1)
                ans.push_back(arr1[i]);
        }

        sort(ans.begin()+n, ans.end());  // O(n1*logn1)

        return ans;
    }
};
*/

// M-2) Optimized approach
// 1. Use a hash map to count the occurrences of each element in arr1.
// 2. Append elements from arr2 to the result using the counts from the hash map.
// 3. Append remaining elements from the hash map to the result and sort them.
// T.C: O(n1*logn1), S.C: O(n1).
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int, int> mpp;

        for(int num : arr1){   // O(n1) // Count occurrences of each element in arr1  
            mpp[num]++;
        }

        for(int num : arr2){   // O(n2) // Add elements from arr2 in the required order
            while (mpp[num] > 0){
                ans.push_back(num);
                mpp[num]--;
            }
        }

        int n = ans.size();
        for(auto it : mpp){    // O(n1) // Collect the remaining elements in ans vector which are not in arr2 
            while (it.second > 0){
                ans.push_back(it.first);
                it.second--;
            }
        }

        sort(ans.begin()+n, ans.end());  // O(n1*logn1) // Sort the remaining elements in ans vector which are not in arr2 
        
        return ans;
    }
};


// M-1) Brute force (generate all possible subarrays) --> T.C: O(n^2), S.C: O(1)
// WARNING : will give "Time Limit Exceeded" as 1<=N<=10^5  and O(n^2) time complexity
/*
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) {
        int maxLen = 0;
        
        for(int i = 0; i < N; i++){  // generate all possible subarrays and check if sum == k
            int sum = 0;
            for(int j = i; j < N; j++){
                sum += A[j];
                int len = j - i + 1;    // length of current subarray
                
                if(sum == K && len > maxLen){
                    maxLen = len;
                }
            }
        }
        
        return maxLen;
        
    } 

};
*/

// The map::find() is a built-in function in C++ STL that returns an iterator or a constant iterator that refers to the position where the key is present in the map. 
// If the key is not present in the map container, it returns an iterator or a constant iterator which refers to map.end()

// M-2) Prefix Sum --> for n elements, T.C: O(n*logn) for ordered map & O(n) for unordered_map, S.C: O(n)
class Solution{
    public:
    int lenOfLongSubarr(int A[], int N, int K) {
        map<int, int> preSumMap;    // prefix sum map with sum as key and index as value
        int maxlen = 0;
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += A[i];     // calculate the prefix sum till index i
            
            if(sum == K){   // if the sum = k, update the maxLen
                int len = i + 1;
                if(len > maxlen)
                    maxlen = len;   // maxLen = max(maxLen, i + 1);
            }
            
            int rem = sum - K;   // calculate the sum of remaining part 
            
            if(preSumMap.find(rem) != preSumMap.end()){     // check if remaining part lies in prefix sum map
                int len = i - preSumMap[rem];
                if(len > maxlen)    // maxLen = max(maxLen, len);
                    maxlen = len;
            }
            
            
            // It is important to check if prefix sum does not lies in map bcoz we need the longest subarray
            // So, to increase the length in len = i - preSumMap[rem]; insert only the smaller subarray if two subarrays have same sum.
            // eg:[3,0,0,2,4].  If k=2, Here insert only [3] in map, not [3,0,0]. But maxlen will be updated if k=3.
            
            if(preSumMap.find(sum) == preSumMap.end()){  // if prefix sum does not lies in map
                preSumMap[sum] = i;   // sum is key and i is value
            }
            
        }
        
        return maxlen;
        
    } 
};

// M-3) Sliding window/ two-pointer  --> T.C: O(n), S.C: O(1)
// WARNING: only possible when all array elements are positive
// When adding a negative number to the sum, it might decrease the sum, causing the algorithm to overlook potential sub-arrays with a sum equal to K.
// When subtracting a negative number to reduce the sum, it might cause the algorithm to skip over valid sub-arrays since it's not certain whether removing the negative number will make the sum less than or equal to K.
/*
class Solution{
    public:
    int lenOfLongSubarr(int A[], int N, int K) {
        int left = 0, right = 0;  // 2 pointers
        int sum = 0;
        int maxLen = 0;
        
        while (right < N) {
            sum += A[right];    // Add the current element to sum
             
            if(sum < K){     // Move forward thw right pointer:
                right++;
            }
        
            else if(sum == K) {      // if sum = k, update the maxLen i.e. answer:
                int len = right - left + 1;
                if(len > maxLen)
                    maxLen = len;
                right++;
            }
        
            else{   // if sum > k, reduce the subarray from left until sum becomes less or equal to K
                while(sum > K && left <= right){
                    sum -= A[left]; 
                    left++;
                }
                right++;
            }
        }
        
        return maxLen;
    } 
};
*/
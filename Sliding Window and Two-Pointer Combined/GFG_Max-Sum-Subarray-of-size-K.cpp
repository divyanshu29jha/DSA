// M-1) Brute force: WARNING --> Gives TLE O(N^2)
/*
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxSum = INT_MIN;
        
        for(int i=0; i<N-K+1; i++){
            long sum = 0;
            for(int j=i; j<i+K; j++){
                sum += Arr[j];
            }
            
            maxSum = max(sum, maxSum);
        }
        
        return maxSum;
    }
};
*/


// M-2) Sliding Window (Constant Window i.e Window Size = K)
// T.C: O(N), S.C: O(1)
/*
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxSum = INT_MIN;
         
        long sum = 0;     // Initialize the sum with the first K elements (Sum of sliding window)
        int l = 0, r = K-1;
        for(int i=l; i<=r; i++){    // for(int i=0; i<k; i++)
            sum += Arr[i]; 
        }
        maxSum = max(sum, maxSum);   // Imp: If K == N, then while-loop will not run and maxSum will be returned
        
        // Slide the window
        while(r < N-1){       // Imp: r < N_!
            sum -= Arr[l];    // Remove the leftmost element of the window
            l++;              // Move left pointer one step forward
            r++;              // Move right pointer one step forward
            sum += Arr[r];    // Add the rightmost element of the window to sum
            
            maxSum = max(sum, maxSum);      
        }
       
        return maxSum;
    }
};
*/


// M-3) Another way to write M-2 (Sliding Window)
// T.C: O(N), S.C: O(1)
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxSum = INT_MIN;
         
        long sum = 0;     // Initialize the sum with the first K elements (Sum of sliding window)
        for(int i=0; i<N; i++){
            if(i >= K){   // start subtracting first element of window if i>=K (K is window size)
                sum -= Arr[i-K];
            }
            
            sum += Arr[i];
            maxSum = max(sum, maxSum);     
        }
       
        return maxSum;
    }
};
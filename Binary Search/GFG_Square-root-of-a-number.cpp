// M-1) Using in-built sqrt() function --> T.C: O(logn) since binary search takes place, S.C: O(1)
/*
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
         return sqrt(x);
    }
};
*/


// M-2) Brute force (Linear Search) --> T.C: O(n), S.C: O(1)
/*
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
         for(int i = 1; i <= x; i++){
             if(i*i == x)
                return i;
             if(i*i > x)
                return i-1;
         }
    }
};
*/

// M-3) Binary Search --> T.C: O(log n), S.C: O(1)
class Solution{
  public:
    long long int floorSqrt(long long int x) {
        int ans;
        
        long long int low = 1, high = x;
        while(low <= high){
            long long int mid = (low + high) / 2;
            
            if(mid*mid <= x){
                ans = mid;  
                low = mid + 1;   // eliminate the left half
            }
            else{
                high = mid - 1;  // eliminate the right half
            }
        }
        
        // return ans;
        return high;   // high will store the ans
    }
};
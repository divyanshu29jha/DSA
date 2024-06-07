// M-1) Brute force (Gives TLE) --> T.C: O(n^2); S.C: O(1)
/*
class Solution{
	public:
	int NthRoot(int n, int m)
	{   int root = -1;
	    for(int i = 1; i <= m; i++){
	        long long num = i;
	        for(int j = 2; j <= n; j++){
	            num *= i;
	        }
	        
	        if(num == m){
	            root = i;
	            break;
	        }
	    }
	    
	    return root;
	}
};
*/

class Solution {
public:
    //return 1, if == m:
    //return 0, if < m:
    //return 2, if > m:
    int power(int mid, int n, int m) {   // directly calculating (mid ^ n) leads to overflow
        long long ans = 1;
        
        for (int i = 1; i <= n; i++) {
            ans = ans * mid;
            if (ans > m) 
                return 2;
        }
        
        if (ans == m) 
            return 1;
            
        return 0;
    }

    int NthRoot(int n, int m) {
        long long ans;
        long long low = 1, high = m;
        
        while (low <= high) {
            long long mid = (low + high) / 2;
            
            if (power(mid, n, m) == 1){
                return mid;
            }
            else if(power(mid, n, m) == 2){
                high = mid - 1;  // eliminate the right half
            } 
            else{
                low = mid + 1;  // eliminate the left half
            }
        }
        
        return -1;
    }
};
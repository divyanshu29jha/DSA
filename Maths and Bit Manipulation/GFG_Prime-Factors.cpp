// M-1) Brute force
// T.C: O(sqrt(n) * 2*sqrt(n))
/*
class Solution{
	public:
	bool isPrime(int n){
	    if (n <= 1) return false;
	    
	    for(int i = 2; i*i <= n; i++){    
	        if(n % i == 0)
	            return false;
	    }
	    
	    return true;
	}
	
	vector<int>AllPrimeFactors(int N) {
	    vector<int> ans;
	    
	    for(int i=2; i*i <= N; i++){     // O(sqrt(n))
	        if(N % i == 0){  
                if(isPrime(i)){           // O(sqrt(n))
                    ans.push_back(i);
                }
                if(i != N/i && isPrime(N/i)){     // O(sqrt(n))  // Check if N/i is a different prime factor
                    ans.push_back(N/i);
                }
            }
	    }
	    
	    if(isPrime(N)){    // If N itself is prime 
            ans.push_back(N);
        }
	    
	    return ans;
	}
};
*/


// M-2) Optimal
// T.C: O(sqrt(N) * logN)
class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> ans;
	    
	    for(int i = 2; i*i <= N; i++){   // O(sqrt(N))
	        if(N % i == 0){
	            ans.push_back(i);
	            
	            while(N % i == 0)        // O (logN)
	                N = N / i;
	        }
	    }
	    
	    if(N != 1) ans.push_back(N);   // prime number is factor of itself
	    
	    return ans;
	}
	
};

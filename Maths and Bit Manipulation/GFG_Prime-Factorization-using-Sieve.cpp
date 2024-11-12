class Solution {
  public:
    void sieve() {}
    
    vector<bool> getSieve(int n){
        vector<bool> isPrime(n + 1, true);    // from 0 till including n
        isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime
        
        for(int i = 2; i*i <= n; i++){
            if(isPrime[i]){
                for(int j = i*i; j <= n; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        return isPrime;
    }

    vector<int> findPrimeFactors(int N) {
        vector<int> ans;
        
        vector<bool> isPrime = getSieve(N);
        for(int i = 2; i <= N; i++){
            while(N % i == 0 && isPrime[i]) {
                ans.push_back(i);
                N = N / i;
            }
        }
        
        if(N > 1)
            ans.push_back(N);
        
        return ans;
    }
};
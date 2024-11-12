// Time Complexity: O(n*log(logn))
// Space Complexity: O(n)
class Solution {
public:
    vector<bool> getSieve(int n){
        vector<bool> isPrime(n + 1, true);
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

    int countPrimes(int n) {
        vector<bool> isPrime = getSieve(n);
        int cnt = 0;
        for(int i=2; i < n ; i++){
            if(isPrime[i])
                cnt++;
        }

        return cnt;
    }
};
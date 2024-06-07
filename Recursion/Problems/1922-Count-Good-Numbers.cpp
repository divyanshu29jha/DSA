// WARNING : Below code will give - runtime error: signed integer overflow: 298023223876953152 * 1125899906842624 cannot be represented in type 'long long'
// We cannot use pow inbuilt-function directly. We need to write our own power function either recursively or iteratievy using binary exponentiation.
/*
class Solution {
public:
    int countGoodNumbers(long long n) {
       long long noOfOddIndices = n/2;
       long long noOfEvenIndices = ceil(n/2);

       long long mod = 1e9+7;   // pow(10,9) + 7;
       long long good = ((long long)(pow(5, noOfEvenIndices)) * (long long)(pow(4,noOfOddIndices))) % mod;

       return good;
    } 
};
*/

// M-1) Binary Exponentiation (using Recursion)
// We can calculate x^n using O log2(N) multiplications.
/*
class Solution {
public:
    long long myPow(long long x, long long n) {
        long long mod = 1e9+7;   // pow(10,9) + 7 = 1000000007

        if(n == 0){     // Base Condition
            return 1; 
        }

        if(n%2 == 0){
            return myPow((x*x)%mod, n/2);
        }
        else{
            return (x*myPow(x, n-1)) % mod;
        }
    }

    int countGoodNumbers(long long n) {
       long long noOfOddIndices = n/2;
       long long noOfEvenIndices = (n+1) / 2;

       long long mod = 1e9+7;   // pow(10,9) + 7 = 1000000007
       long long good = (myPow(5, noOfEvenIndices) * myPow(4,noOfOddIndices)) % mod;

       return good;
    } 
};
*/

// M-2) Binary Exponentiation (using Recursion)
// We can calculate x^n using O log2(N) multiplications.
class Solution {
public:
    long long myPow(long long x, long long n) {
        long long mod = 1e9+7;   // pow(10,9) + 7 = 1000000007

        if(n == 0){     // Base Condition
            return 1; 
        }

        long long ans = myPow(x, n/2);

        ans *= ans;
        ans %= mod;     // OR ans = (ans * ans) % mod;

        if(n%2 == 1){
            ans *= x;
            ans %= mod;     // OR ans = (ans * x) % mod;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
       long long noOfOddIndices = n/2;
       long long noOfEvenIndices = (n+1) / 2;

       long long mod = 1e9+7;   // pow(10,9) + 7 = 1000000007
       long long good = (myPow(5, noOfEvenIndices) * myPow(4,noOfOddIndices)) % mod;

       return good;
    } 
};
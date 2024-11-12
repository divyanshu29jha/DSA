#define MOD 1000000007
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> a(n,1);

        for(int i=0; i<k; i++){
            vector<int> newA(n);            
            newA[0] = 1;

            for(int i=1; i<n; i++){
                newA[i] += (a[i] + newA[i-1]) % MOD; 
            }

            a = newA;
        }

        return a[n-1];
    }
};
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);   // index as remainder (0 to k-1) and its frequency as value 
        
        for(int num : arr){
            int rem = num % k;
            if(rem < 0) rem += k;       // Ensure the remainder is positive
            // int rem = (num%k + k) % k;  // M-2) handling negative remainders
            freq[rem]++;
        }

        if (freq[0] % 2 != 0) return false;

        for(int i = 1; i <= k/2; i++){
            if(freq[i] != freq[k-i])
                return false;
        }

        return true;
    }
};
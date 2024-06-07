class Solution{
    public:
    int maxLen(vector<int>&A, int n){
        unordered_map<int, int> m;  // prefix-sum as key and index as value
        int maxlen = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += A[i];
            
            if(sum == 0){
                maxlen = i + 1;
            }
            
            int rem = sum - 0;
            if(m.find(rem) != m.end()){
                int len = i - m[rem];
                maxlen = max(maxlen, len);
            }
            
            if(m.find(rem) == m.end()){
                m[sum] = i;
            }
        }
        
        return maxlen;
    }
};
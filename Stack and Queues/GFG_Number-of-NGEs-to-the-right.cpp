// M-1) Brute force 
// T.C: O(N * queries), actually O((N-idx)*queries), S.C: O(1)
/*
class Solution{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> ans(queries);
        
        for(int i=0; i<queries; i++){
            int idx = indices[i];
            int j = idx + 1;
            
            int cnt = 0 ;
            while(j<n){
                if(arr[j] > arr[idx]) cnt++;
                j++;
            }
            
            ans[i] = cnt;
        }
        
        return ans;
    }
};
*/


// M-2) Optimized - Using Stack (NGE)  
// T.C: O(N * queries), S.C: O(1)
class Solution{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> ans(queries);
        for(int i = 0; i < queries; i++){
            int curr = arr[indices[i]];
            stack<int> st;
            int r = n - 1;
            while(r > indices[i]){
                if(arr[r] > curr){
                    st.push(arr[r]);
                }
                r--;
            }
            
            ans[i] = st.size();
        }
        
        return ans;
    }
};
// M-1) Brute force : O(n^2); S.C: O(n) for ans
/*
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            bool leader = true;
            for(int j = i+1; j < n; j++){
                if(a[j] > a[i]){
                    leader = false;
                    break;
                }
            }
            
            if (leader)
                ans.push_back(a[i]);
        }
        
        return ans;
        
    }
};
*/


// M-2) Similar to 121. Best Time to Buy and Sell Stock (in reverse manner) --> T.C: O(n), S.C: O(n)
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int max = a[n-1];
        ans.push_back(a[n-1]);
        
        for(int i = n-2; i >= 0; i--){
            if(a[i] >= max){
                ans.push_back(a[i]);
                max = a[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};



// } Driver Code Ends
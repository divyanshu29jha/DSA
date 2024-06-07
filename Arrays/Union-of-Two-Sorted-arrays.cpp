class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        // M-1) Using sets
        /*
        set < int > s;
        vector < int > ans;
        for (int i = 0; i < n; i++)
            s.insert(arr1[i]);
        for (int i = 0; i < m; i++)
            s.insert(arr2[i]);
        for (auto & it: s)
            ans.push_back(it);
        
        return ans;
        */
        
        
	// M-2 Two-pointer approach
        vector<int> ans;    // Uninon vector
        int i = 0, j = 0;   // Pointers
        while(i<n && j<m){  // Case 1 and 2
            if(arr1[i] <= arr2[j]){
                if(ans.size() == 0 || ans.back() != arr1[i])    // Write ans.size() before checking ans.back() or else segmentation fault occurs
                    ans.push_back(arr1[i]);
                i++;
            }
            else{           // Case 3
                if(ans.size() == 0 || ans.back() != arr2[j])
                    ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<n){     // IF any element left in arr1
            if(ans.size() == 0 || ans.back() != arr1[i])
                    ans.push_back(arr1[i]);
            i++;
        }
        
        while(j<m){     // IF any element left in arr2
            if(ans.size() == 0 || ans.back() != arr2[j])
                    ans.push_back(arr2[j]);
                j++;
        }
        
        return ans;
        
    }
};

-------------------------------------------------------------------

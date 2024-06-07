class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> pos;   
        vector<int> neg;
  
     
        for(int i=0; i<n; i++){     // Segregate the array into positives and negatives.
            if(arr[i] >= 0) 
                pos.push_back(arr[i]);
            else 
                neg.push_back(arr[i]);
        }
        
        
        if(pos.size() < neg.size()){    // If positives are lesser than the negatives.
            // First, fill array alternatively till the point where positives and negatives ar equal in number.
            for(int i=0; i<pos.size(); i++){
                arr[2*i] = pos[i];
                arr[2*i+1] = neg[i];
            }
    
            // Fill the remaining negatives at the end of the array.
            int index = pos.size()*2;
            for(int i = pos.size(); i<neg.size(); i++){
                arr[index] = neg[i];
                index++;
            }
        }
  
        
        else{   // If negatives are lesser than the positives.
            // First, fill array alternatively till the point where positives and negatives ar equal in number.
            for(int i=0; i<neg.size(); i++){
                arr[2*i] = pos[i];
                arr[2*i+1] = neg[i];
            }
    
            // Fill the remaining positives at the end of the array.
            int index = neg.size()*2;
            for(int i = neg.size(); i<pos.size(); i++){
                arr[index] = pos[i];
                index++;
            }
        }
	}
};


// } Driver Code Ends
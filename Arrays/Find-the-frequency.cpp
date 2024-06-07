//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*Function to find frequency of x
* x : element whose frequency is to be found
* v : input vector
*/
---------------------------------------------------------------------------------------
// M-1 (Map) --> O(n)

int findFrequency(vector<int> v, int x){    // o(n) for n elements
    unordered_map<int, int> m;  // takes O(1) time to insert single element
    for(auto i : v){
        if(i == x)
            m[i]++;     
    }
    
    return m[x];
}

----------------------------------------------------------------------------------------
// M-2 (Hasing)   --> O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 4, 1, 3, 5, 4, 2, 2};
    
    int max = *max_element(nums.begin(), nums.end());	
    int n = nums.size()+1;
    
    vector<int> freq(n);  // frequency array or hash array --> all frequency is initialised to 0
    
    for(auto i : nums){
        freq[i]++;
    }
    
    for(int i=0; i<freq.size(); i++){
        if(freq[i] != 0){
            cout<<"Freq of "<<i<<" is "<<freq[i]<<endl;
        }
    }

    return 0;
}

----------------------------------------------------------------
// M-3 (using two loops and visited bool vector)  --> O(n^2)

int findFrequency(vector<int> v, int x){
    int n = v.size();
    vector<bool> visited(n, false);
   
    int count = 0;
    for(int i=0; i<n; i++){
        if(v[i] == x){
            if (visited[i] == true)
                continue;
 
            count = 1;
       
            for(int j=i+1; j<n; j++){
                if(v[i] == v[j]){
                    visited[j] = true;
                    count++;
                }
            }
        }
    }
        
    return count;

-----------------------------------------------------------------
// Note: Frequency of most frequent element.

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 5, 10, 15, 10, 5};
    
    map<int,int> m;
    
    for(int i=0; i<v.size(); i++){
        m[v[i]]++;
    }
    
    int maxFreq = 0, elem = v[0];
    for(auto it : m){
        if(it.second > maxFreq){
            maxFreq = it.second;
            elem = it.first;
        }
    }
    
    cout<<elem<<" --> "<< maxFreq<<endl;

    return 0;
}
*/
-----------------------------------------------------------------------
}

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    // Declaring vector 
	    vector<int> v;
	        
	    // Taking vector element input
	    for(int i = 0;i<N;i++){
	        int k;
	        cin >> k;
	        v.push_back(k);
	    }
	    
	    // element whose frequency to be find
	    int x;
	    cin >> x;
	    cout << findFrequency(v, x) << endl;
	}
	
	return 0;
}
// } Driver Code Ends
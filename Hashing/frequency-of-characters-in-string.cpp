// M-1) Hashing --> T.C: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "classroom";
    
    // pre-compute
    int hash[26] = {0};  // initialise all frequency to 0 initially. If we take bigger hash size, hash[256], then no need to subtract 'a'
    for(int i=0; i<s.size(); i++){a
        hash[s[i] - 'a']++;	// s[i] - 'a' gets auto-cast to ascii value
    }
    
    for(int i = 0; i<s.size(); i++){
        if(hash[s[i] - 'a'] != 0)       // fetch the frequency
            cout<<"Frequency of "<<s[i]<<" is "<< hash[s[i] - 'a'] <<endl;  
    }

    return 0;
}


// M-2) Map --> T.C: O(n) for n elements (size of string)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "classroom";
    
    unordered_map<char,int> m;  // O(1) time to insert single key-value pair
    
    for(int i=0; i<s.size(); i++){
        m[s[i]]++;
    }
    
    for(auto i : m){
        // cout<<i<< " --> "<<m[i]<<endl;   // gives error in range-based for-loop
        cout << i.first << " --> " << i.second << endl;
    }
    
    cout<<m['o']<<endl; // eg: to find frequency of 'o'

    return 0;
}
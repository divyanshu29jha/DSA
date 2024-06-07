// M-1) Brute force (generate all subarrays & check if their xor == k)  --> T.C: O(n^2), S.C: O(1)
// WARNING gives TLE as 1 <= length of the array <= 10^5
/*
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int count = 0;
   
    for (int i = 0; i < n; i++) {     // Generating subarrays
        int xorr = 0;
        for (int j = i; j < n; j++) {
            xorr = xorr ^ A[j];       // calculate XOR of all elements
            if (xorr == B)            // check XOR and count
                count++;
        }
    }
    return count;
}
*/


// M-2) Using Prefix XOR  --> T.C: O(n *log n) or O(n) depending on which map used, S.C: O(n)
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int count = 0;
    int xr = 0;
    map<int, int> m;    // map to store prefix xor as key and no. of subarrays having same prefix xor as value
    
    for(int i = 0; i < n; i++){
        xr ^= A[i];    // prefix XOR till index i:
        
        if(xr == B){
            count++;
        }
        
        int rem = xr ^ B;   // By formula: x = xr ^ k
        
        if(m.find(rem) != m.end()){
            count += m[rem];    // add the occurrence of xr ^ k to the count
        }
        
        m[xr]++;    // Insert the prefix xor till index i into the map
    }
    
    return count;
}


// M-2) Using Prefix XOR (Striver's code)
/*
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int count = 0;
    int xr = 0;
    map<int, int> m;    // map to store prefix xor as key and no. of subarrays having same prefix xor as value
    m[xr]++; //setting the value of 0.
    
    for(int i = 0; i < n; i++){
        xr ^= A[i];    // prefix XOR till index i:
        
        int rem = xr ^ B;   // By formula: x = xr ^ k

        count += m[rem];    // add the occurrence of xr ^ k to the count. m[rem] = 0 if rem not found in map.
        
        m[xr]++;    // Insert the prefix xor till index i into the map
    }
    
    return count;
}
*/

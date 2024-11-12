/*
memset() Parameters:-
dest: Pointer to the object to copy the character.
ch: The character to copy.
count: Number of times to copy.

The memset() function returns dest, the pointer to the destination string.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5, -1);
    for(int i : v){
        cout<<i<<" ";    // prints [-1 -1 -1 -1 -1] 
    }
    cout<<endl;
    
    int arr[5];
    memset(arr, -1, sizeof(arr));    // better to use for arrays, not vectors
    for(int i : arr){
        cout<<i<<" ";   // prints [-1 -1 -1 -1 -1] 
    }

    return 0;
}
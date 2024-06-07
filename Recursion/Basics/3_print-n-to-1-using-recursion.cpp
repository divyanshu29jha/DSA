// M-1
/*
#include <bits/stdc++.h>
using namespace std;

void printNto1(int i, int n){
    if(i == 0)
        return;  // Base Condition

    cout<<i<<endl;

    printNto1(i-1, n);    // Recursive call
}

int main() {
    int n;
    cin>>n;
    printNto1(n, n);

    return 0;
}
*/

// M-2 (backtracking)
/*
#include <bits/stdc++.h>
using namespace std;

void printNto1(int i, int n){
    if(i > n)   // Base Condition
        return;

    printNto1(i+1, n);    // Recursive call

    cout<<i<<endl;
}

int main() {
    int n;
    cin>>n;
    printNto1(1, n);

    return 0;
}
*/

// M-3 (using single parameter - GFG)
/*
#include <bits/stdc++.h>
using namespace std;

void printNto1(int i, int n){
    if(i > n)   // Base Condition
        return;

    printNto1(i+1, n);    // Recursive call

    cout<<i<<endl;
}

int main() {
    int n;
    cin>>n;
    printNto1(1, n);

    return 0;
}
*/
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


// BEST
#include <bits/stdc++.h>
using namespace std;

void print1toN(int n){
    if(n == 0) return;
    
    print1toN(n-1);
    cout<<n<<" ";
}

void printNto1(int n){
    if(n == 0) return;
    
    cout<<n<<" ";
    printNto1(n-1);   // tail recursion
}

int main() {
    int n=5;
    print1toN(n);  // 1 2 3 4 5
    cout<<endl;
    printNto1(n);  // 5 4 3 2 1

    return 0;
}
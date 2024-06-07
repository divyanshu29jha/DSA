// M-1 (recursive way)  --> factorial(N) = N * factorial(N-1)
/*
#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 1)   // Base Condition
        return 1;

    return n * factorial(n-1);    // Recursive call
}

int main() {
    int n;
    cin>>n;
    cout<< factorial(n);

    return 0;
}
*/
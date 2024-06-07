// M-1 (Parameterised Recursion)
/*
#include <bits/stdc++.h>
using namespace std;

void func(int i, int sum){
    if(i == 0){   // Base Condition
        cout<< sum;
        return;
    }

    func(i-1, sum + i);    // Recursive call
}

int main() {
    int n;
    cin>>n;
    func(n, 0);

    return 0;
}
*/

// M-2 (Functional Recursion)  --> sumOfNaturalNumbers(N) = N + sumOfNaturalNumbers(N-1)
/*
#include <bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n == 0)   // Base Condition
        return 0;

    return n + sum(n-1);    // Recursive call
}

int main() {
    int n;
    cin>>n;
    cout<< sum(n);

    return 0;
}
*/
// A tail recursive function is a function where the only recursive call is the last one in the function. A non-tail recursive function is a function where that is not the case.
// A backward recursion is a recursion where in each recursive call the value of the parameter is less than in the previous step.
// A forward recursion is a recursion where in each recursive call the value of the parameter grows bigger with each step.

// M-1 (forward recursion)
/*
#include <bits/stdc++.h>
using namespace std;

void print1toN(int i, int n){
    if(i > n)
        return;  // Base Condition

    cout<<i<<endl;

    print1toN(i+1, n);    // Recursive call
}

int main() {
    int n;
    cin>>n;
    print1toN(1, n);

    return 0;
}
*/

// M-2 (backward recursion/ backtraking)
/*
#include <bits/stdc++.h>
using namespace std;

void print1toN(int i, int n){
    if(i == 0)  // Base Condition
        return;

    print1toN(i-1, n);    // Recursive call

    cout<<i<<endl;

}

int main() {
    int n;
    cin>>n;
    print1toN(n, n);

    return 0;
}
*/

// M-3 (using single parameter - GFG)
/*
class Solution
{
public:
    void printTillN(int N)
    {
        if(N == 0)  // base condition
            return;

        printTillN(N-1);

        cout<<N<<" ";

    }
};
*/
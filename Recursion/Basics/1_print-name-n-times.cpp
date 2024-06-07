// Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }
// Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.

//  M-1  (using a global variable)
/*
#include <bits/stdc++.h>
using namespace std;

int cnt = 0; // global variable

void myFunc(){
    if (cnt == 5)
        return; // Base Condition

    cout << "Raj" << endl;
    cnt++;
    myFunc(); // Recursive call
}

int main(){
    myFunc();

    return 0;
}
*/

//  M-2  (using 2 parameter)   --> Parametrized Recursion
/*
#include <bits/stdc++.h>
using namespace std;

void myFunc(int i,int n){
    if(i > n)
        return;  // Base Condition

    cout<<"Raj"<<endl;
    i++;
    myFunc(i, n);    // Recursive call
}

int main() {
    int n;
    cin>>n;
    myFunc(1,n);

    return 0;
}
*/

// M-3 (using single parameter)  --> Functional Recursion
/*
#include <bits/stdc++.h>
using namespace std;

void myFunc(int n){
    if(n == 0)
        return;  // Base Condition

    cout<<"Raj"<<endl;

    myFunc(n-1);    // Recursive call
}

int main() {
    int n;
    cin>>n;
    myFunc(n);

    return 0;
}
*/

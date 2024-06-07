// M-1
/*
#include <bits/stdc++.h>
using namespace std;

void rev(vector<int> &v, int i){    // pass by refererce, or else nos. won't swap
   int n = v.size();
   if(i >= n/2)
      return;

    swap(v[i], v[n-i-1]);
    rev(v, i+1);
}

int main() {
    vector<int> v = {1,2,3,4,5};
    rev(v, 0);
    for(auto i : v){
        cout<<i<<" ";
    }

    return 0;
}
*/

// M-2
/*
#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &v, int start, int end){    // pass by refererce, or else nos. won't swap
//   if (start < end) {
//       swap(v[start], v[end]);
//       reverseArray(v, start + 1, end - 1);
//   }

    if(start>= end)
        return;
    swap(v[start] , v[end]);
    reverseArray(v, start + 1, end - 1);
}

int main() {
    vector<int> v = {1,2,3,4,5};
    int n = v.size();

    reverseArray(v, 0, n - 1);

    for(auto i : v){
        cout<<i<<" ";
    }

    return 0;
}
*/
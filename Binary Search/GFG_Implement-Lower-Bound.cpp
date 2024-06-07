// Lower bound of x is the smallex index ind such that arr[ind] >= x. 
// But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

// M-1) Linear Search --> T.C: O(n), S.C: O(1)
/*
int lowerBound(vector<int> arr, int n, int x) {
	for(int i = 0; i < n; i++){
		if (arr[i] >= x) {	// lower bound found  (return the first index)
            return i;
        }
	}
}
*/

// M-2) Binary Search --> T.C: O(logn), S.C: O(1)
int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n-1;
	int ans = n;   // store n initially for the case that if index not exists in the array

	while(low <= high){
		int mid = (low + high) / 2;

		if(arr[mid] >= x){	// maybe an answer but we need to find the smallest index
			ans = mid;
			high = mid - 1; // look for smaller index on the left
		}
		else{
			low = mid + 1;  // look on the right
		}
	}

	return ans;
}

// M-3) Using STL --> T.C: O(logn), S.C: O(1)
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,3,3,4,5,7,9,9,11};
    int x = 7;
    auto it = lower_bound(v.begin(), v.end(), x);
    cout<< it - v.begin();  // subtract v.begin() to get the index

    return 0;
}
*/




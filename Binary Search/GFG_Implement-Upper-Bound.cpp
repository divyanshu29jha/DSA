// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
// The upper bound is the smallest index, ind, where arr[ind] > x.
// But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. The main difference between the lower and upper bound is in the condition. 
// For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.

// M-1) Linear Search --> T.C: O(n), S.C: O(1)
/*
int upperBound(vector<int> arr, int n, int x) {
	for(int i = 0; i < n; i++){
		if (arr[i] > x) {	// lower bound found  (return the first index)
            return i;
        }
	}
}
*/

// M-2) Binary Search --> T.C: O(logn), S.C: O(1)
int upperBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;   // Initialize ans to n for the case where no element is greater than or equal to x.

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) { // Maybe an answer but we need to find the smallest index
            ans = mid;
            high = mid - 1; // Look for a smaller index on the left
        } else {
            low = mid + 1;  // Look on the right
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
    auto it = upper_bound(v.begin(), v.end(), x);
	cout<< it - v.begin();  // subtract v.begin() to get the index

    return 0;
}
*/




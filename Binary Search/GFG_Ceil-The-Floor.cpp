// The floor of x is the largest element in the array which is smaller than or equal to x
//  ( i.e. largest element in the array <= x).
// The ceiling of x is the smallest element in the array greater than or equal to x
//  ( i.e. smallest element in the array >= x).

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr + n);
    
    int low = 0, high = n - 1;
	int floor = -1;
	while(low <= high) {
		int mid = (low + high) / 2;
		
		if (arr[mid] <= x) {    // maybe the floor
			floor = arr[mid];     // look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1;   // look on the right
		}
	}
	
	
	low = 0, high = n - 1;
	int ceil = -1;
	while(low <= high) {
	    int mid = (low + high) / 2;
	    
		if (arr[mid] >= x) {    // maybe the ceil
			ceil = arr[mid];
			high = mid - 1;     //look for smaller index on the left
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	
	pair<int, int> ans = {floor, ceil};
    return ans;
}
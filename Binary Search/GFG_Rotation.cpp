// M-1) Linear Search --> T.C: O(n), S.C: O(1)
/*
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int count = 0;
	    for(int i = 0; i < n-1; i++){
	        if(arr[i] > arr[i+1]){
	            count = i + 1;
	            break;
	        }
	    }
	    
	    if(count == n){     // eg: edge case: {1, 2, 3, 4, 5}
	        count = 0;
	    }
	    
	    return count;
	}

};
*/

// M-2) Binary Search --> T.C: O(log n), S.C: O(1)
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int ans = INT_MAX;   // ans is the minimum no. in the array 
	    int index;  // index of ans (minimum no. in the array) which is equal to the rotation count.
	    int low = 0, high = n-1;
	    
	    while(low <= high){
            int mid = (low + high) / 2;

            if(arr[low] <= arr[mid]){     // left half is sorted:
                if(arr[low] < ans){   // store the minimum
                    ans = arr[low];
                    index = low;
                }
                low = mid + 1;   // eliminate left half
            }
            else{       // right half is sorted:
                if(arr[mid] < ans){   // store the minimum
                    ans = arr[mid];
                    index = mid;
                }
                high = mid - 1;  // eliminate right half
            }
        }
	    
	    
	    return index;
	}

};
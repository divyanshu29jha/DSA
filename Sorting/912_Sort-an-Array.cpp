// https://leetcode.com/problems/sort-an-array/solutions/5531053/merge-sort-radix-sort-counting-sort-heap-sort-47ms-beats-99-41/
// Merge Sort -->  T.C:  Best & worst - O(N*log(N)),  S.C: O(N) for temp array;  where N = size of the array
// Divide and merge  // O(log n) time in dividing and O(n) time in merging back
// Merge sort and quick sort are examples of divide and conquer algorithms.

// Learn about merge, quick, heap, bucket, radix and counting sort.
class Solution {
public:
    void merge(vector<int> &v, int low, int mid, int high){
        vector<int> temp;   // temporary array
        int left = low;     // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
    
        //storing elements in the temporary array in a sorted manner//
        while(left <= mid && right <= high){
            if(v[left] <= v[right]){
                temp.push_back(v[left]);
                left++;
            }
        
            else{
                temp.push_back(v[right]);
                right++;
            }
        }
    
        // if elements on the left half are still left //
        while(left <= mid){
            temp.push_back(v[left]);
            left++;
        }
    
        // if elements on the right half are still left //
        while(right <= high){
            temp.push_back(v[right]);
            right++;
        }
    
        // transfering all elements from temporary to arr //
        for(int i=low; i <= high; i++){
            v[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &v, int low, int high){
        if(low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(v, low, mid);    // left half
        mergeSort(v, mid+1, high); // right half
        merge(v, low, mid, high);   // merging sorted halves
    }

    vector<int> sortArray(vector<int>& nums){
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};
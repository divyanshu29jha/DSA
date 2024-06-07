// M-1) Brute force (Linear Search) --> Gives TLE
// T.C: O((max(arr[])-min(arr[])+1) * N), S.C: O(1)
/*
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int days;
    
        if(m*k > n)
            return -1;

        for(int i = mini; i <= maxi; i++){
            int count = 0, bouquet = 0;
            for(int j = 0; j < n; j++){
                if(bloomDay[j] <= i){
                    count++;
                }
                else{
                    bouquet += count/k;
                    count = 0;
                }
            }

            bouquet += count/k;
            if(bouquet >= m){
                days = i;
                break;
            }
        }

        return days;
    }
};
*/

// M-1) Slight modification for M-1 --> Gives TLE 
// T.C: O((max(arr[])-min(arr[])+1) * N), S.C: O(1)
/*
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int days;
    
        if(m*k > n)
            return -1;

        for(int i = mini; i <= maxi; i++){
            int count = 0, noOfB = 0;
            for(int j = 0; j < n; j++){
                if(bloomDay[j] <= i){
                    count++;
                    if(count == k){
                        noOfB++;
                        count = 0;
                    }
                }
                else{
                    count = 0;
                }
            }

            if(noOfB >= m){
                days = i;
                break;
            }
        }

        return days;
    }
};
*/


// M-2) Binary Search --> T.C: O(log(max(arr[])-min(arr[])+1) * N), S.C: O(1)
/*
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * (long long)k > n) return -1;
        
        int days;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(low <= high){    
            int count = 0, bouquet = 0;
            int mid = (low + high) / 2;
            for(int j = 0; j < n; j++){
                if(bloomDay[j] <= mid){
                    count++;
                }
                else{
                    bouquet += count/k;
                    count = 0;
                }
            }

            bouquet += count/k;
            if(bouquet >= m){
                days = mid;     // days maybe an answer, but search for even smaller value of days
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return days;  // return low;
    }
};
*/


// M-2) Better code quality for M-2 --> T.C: O(log(max(arr[])-min(arr[])+1) * N), S.C: O(1)
class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int count = 0, noOfB = 0;

        for(int i = 0; i < n; i++){     // count the number of bouquets:
                if(bloomDay[i] <= day){
                    count++;
                }
                else{
                    noOfB += count/k;
                    count = 0;
                }
            }

            noOfB += count/k;
            return noOfB >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * (long long)k > n) return -1;
        
        int days;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(low <= high){    
            int mid = (low + high) / 2;

            if (possible(bloomDay, mid, m, k)){ 
                days = mid;  // days maybe an answer, but search for even smaller value of days
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }

        return days;  // return low;
    }
};



// M-1) Brute force --> Gives TLE 
// T.C:  O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array
/*
class Solution {
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        vector<int> ans;
        int maxDist = stalls[n-1] - stalls[0];
        
        for(int d = 1; d <= maxDist; d++){
            int cow = 1, j = 0;
            for(int i = 1; i < stalls.size(); i++){
                if(stalls[i] - stalls[j] >= d){
                    cow++;
                    j = i;
                }
                
                if(cow >= k){
                    ans.push_back(d);
                }
            }
        }
        
        return *max_element(ans.begin(), ans.end());
    }
};
*/


// M-1) Better way to write above M-1 --> Gives TLE 
// T.C:  O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array
/*
class Solution {
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows) {
        int n = stalls.size(); //size of array
        int cntCows = 1;    //no. of cows placed
        int last = stalls[0];   //position of last placed cow.
        
        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= dist) {
                cntCows++; //place next cow.
                last = stalls[i]; //update the last location.
            }
            if (cntCows >= cows) 
                return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());

        int limit = stalls[n - 1] - stalls[0];
        for (int i = 1; i <= limit; i++) {
            if (canWePlace(stalls, i, k) == false) {
                return (i - 1);
            }
        }
        return limit;
    }
};
*/


// Minimum possible distance between 2 cows: The minimum possible distance between two cows is 1 as the minimum distance between 2 consecutive stalls is 1.
// Maximum possible distance between 2 cows: The maximum possible distance between two cows is = max(stalls[])-min(stalls[]). This case occurs when we place 2 cows at two ends of the sorted stalls array.
// our answer lies in the range:  [1, max(stalls[])-min(stalls[])].
// M-2) Binary Search
class Solution {
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows) {
        int n = stalls.size(); //size of array
        int cntCows = 1;    //no. of cows placed
        int last = stalls[0];   //position of last placed cow.
        
        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= dist) {
                cntCows++; //place next cow.
                last = stalls[i]; //update the last location.
            }
            if (cntCows >= cows) 
                return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());

        int low = 1, high = stalls[n - 1] - stalls[0];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canWePlace(stalls, mid, k) == true) {
                low = mid + 1;
            }
            else high = mid - 1;
        }   
        
        return high;
    }   
};
// M-1) Brute force --> T.C: O(max(piles[]) * n), where n = piles.size(); S.C: O(1)
// WARNING: Gives TLE
// Check all possible answers from 1 to max(piles[]). The minimum number for which the required time <= h, is our answer.
// Start from k=1 and not k = min(piles[]) bcoz if h = 27 for piles = [3,6,7,11], then k = 1.
/*
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());    //find the maximum pile // O(n)

        for(int k = 1; k <= maxPile; k++){  // Find the minimum value of k (bananas/hour)
            int totalHours = 0;
            for(int i = 0; i < piles.size(); i++){
                totalHours += ceil((double)piles[i] / (double)k);
            }

            if (totalHours <= h) 
                return k;
        }
    
        return -1;
    }
};
*/

// M-2) Binary search --> T.C:  O(n * log(max(piles[]))), where n = piles.size(), S.C: O(1)
class Solution {
public:
    long long calculateTotalHours(vector<int>& piles, int k) {    // Eating speed =  k (bananas/hour) 
        long long totalHours = 0;
        for(int i = 0; i < piles.size(); i++){
            totalHours += ceil((double)piles[i] / (double)k);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());    //find the maximum  // O(n)
        int ans;    // we can avoid using ans variable by directly returning low since it stores min k.

        int low = 1, high = maxPile;
        while(low <= high){
            int mid = (low + high) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            
            if (totalH <= h) {
                ans = mid;          // ans can be one of the answers. But search for values of k less than ans.
                high = mid - 1;     // So, eliminate the right half since we need the minimum value of k. 
            }
            else {
                low = mid + 1; // eliminate the right half since we cannot find minimum value of k such that totalH <= h
            }
        }
    
        return ans;
    }
};
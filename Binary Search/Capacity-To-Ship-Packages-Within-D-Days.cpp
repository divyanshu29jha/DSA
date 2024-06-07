// Our answer lies in the range [max(weights[]), sum(weights[])]. Use BS on answers i.e weight.
// M-1) Linear Search --> Gives TLE - T.C: O(N * (sum(weights[]) – max(weights[]) + 1)), S.C: O(1)
/*
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = *max_element(weights.begin(), weights.end());
        int sumWeight = 0;
        for(auto i : weights){
            sumWeight += i;
        }

        int ans;
        for(int i = maxWeight; i <= sumWeight; i++){
            int load = 0, d = 1;

            for(int j = 0; j < weights.size(); j++){
                load += weights[j];
                if(load > i){
                    d++;
                    load = weights[j];
                }
            }

            if(d <= days){
                ans = i;
                break;
            }
        }

        return ans;
    }
};
*/


// M-2) Binary Search --> T.C: O(N * log(sum(weights[]) – max(weights[]) + 1)), S.C: O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = *max_element(weights.begin(), weights.end());
        int sumWeight = 0;
        for(auto i : weights){
            sumWeight += i;
        }

        int ans;
        int low = maxWeight, high = sumWeight;
        while(low <= high){
            int mid = (low + high) / 2;

            int load = 0, d = 1;

            for(int i = 0; i < weights.size(); i++){
                load += weights[i];
                if(load > mid){
                    d++;
                    load = weights[i];
                }
            }

            if(d <= days){
                ans = mid;
                high = mid - 1;  // eliminate right half (mid maybe an answer, but find even lesser no. of days)
            }
            else{
                low = mid + 1;  // eliminate left half  (as weight of ship increases, d decreases)                
            }
        }

        return ans;  // return low
    }
};
// Greeedy (Similar to Fractional Knapsack problem)
// We need max units in truck. So, sort the boxes by the number of units per box in descending order. This way, we can maximize the number of units loaded onto the truck by taking the most "valuable" boxes first.
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] >= b[1];  
        });

        int ans = 0;
        for(int i=0; i<boxTypes.size(); i++){
            if(boxTypes[i][0] <= truckSize){
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                ans += truckSize * boxTypes[i][1];
                break;
            }
        }

        return ans;
    }
};
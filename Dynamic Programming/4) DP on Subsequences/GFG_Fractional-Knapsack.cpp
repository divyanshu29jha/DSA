// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// Item arr[] is array of Item objects (i.e [value, weight] pairs)
// T.C: O(n log n + n). O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.
// S.C: O(1), no additional data structure has been used.
class Solution {
  public:
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Sort 'Item' objects in descending order according to value per weight
        sort(arr, arr + n, [](Item a, Item b){
            return double(a.value)/double(a.weight) >= double(b.value)/double(b.weight);   
        });
        
        double ans = 0.0;
        for(int i = 0; i < n; i++){   
            if(arr[i].weight <= w){
                ans += arr[i].value;
                w -= arr[i].weight;
            }
            else{
                ans += double(arr[i].value) / double(arr[i].weight) * w;
                break;
            }
        }
        
        return ans;
    }
};
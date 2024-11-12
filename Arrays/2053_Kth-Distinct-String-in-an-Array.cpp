class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;   // unordered map will not store elements in the same order as in array
        for(auto s : arr){                // ordered map will store in sorted order
            mpp[s]++;
        }

        int distinctCount = 0;
        for(auto s : arr){
            if(mpp[s] == 1){
                distinctCount++;
                if(distinctCount == k)
                    return s;
            }
        }

        return "";
    }
};
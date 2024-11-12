// M-1) Using frequency vectors
/*
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> v1(1001);
        vector<int> v2(1001);
        for (int i : target) {
            v1[i]++;
        }
        for (int i : arr) {
            v2[i]++;
        }
        
        return v1 == v2;
    }
};
*/

// M-2) Using sorting 
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        return arr == target;
    }
};
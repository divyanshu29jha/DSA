// Approach: Customized Sorting - Learn about customized sorting, comparators, anonymous functions and lamda functions in C++. 
// Time complexity: O(N⋅logN) 
// Sorting nums incurs a time complexity of O(N⋅logN). Iterating over nums when counting frequencies incurs a time complexity of O(N), which can be ignored since O(N⋅logN) is the dominating term.
// Space complexity: O(N). We define a hash map to count the frequencies of each element, which incurs a space complexity of O(N). Sorting also takes up some space, and the space complexity for that is detailed below:
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) {  // if freq of two nos. are equal, then sort them in decreasing order 
                return a > b;  
            }
            return freq[a] < freq[b];  // if freq of numbers are not equal, then sort by frequency in ascending order
        });

        return nums;
    }
};
// M-1) Brute force (Gives TLE) --> T.C: O(n^2); S.C: O(1)
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority;

        for (int i = 0; i < n; i++) {
            int cnt = 0;    //selected element is v[i]
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i])      // counting the frequency of v[i]
                    cnt++;
            }

            
            if (cnt > (n / 2)){ // check if frquency is greater than n/2
                majority =  nums[i];
                break;
            }
        }

        return majority;
    }
};
*/


// M-2) Better approach --> T.C: O(nlogn) + O(n) or O(n) + O(n), S.C: O(n)
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for(auto num : nums){
            m[num]++;
        }

        int majority;
        for(auto i : m){
            if(i.second > n/2){
                majority = i.first;
                break;
            }
        }

        return majority;
    }
};
*/

// The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.
// Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).

// M-3) Moore’s Voting Algorithm  --> T.C: O(n) + O(n), S.C: O(1) 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int elem;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                elem = nums[i];
                cnt = 1;
            }
            else if(nums[i] == elem){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        return elem;

        //checking if the stored element is the majority element:
        // int cnt1 = 0;
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == elem) 
        //         cnt1++;
        // }

        // if (cnt1 > (n / 2)) 
        //     return elem;
        // return -1;
        
    }
};


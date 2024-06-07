// M-1) Brute force --> T.C: O(n^2); S.C: O(1)
/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> majority;

        for (int i = 0; i < n; i++) {   //selected element is v[i]
            if(majority.size() == 0 || majority.back() != nums[i]){
                int cnt = 0;    
            
                for (int j = 0; j < n; j++){   // counting the frequency of v[i]
                    if (nums[j] == nums[i])      
                        cnt++;
                }

            
                if (cnt > n/3 ){    // check if frquency is greater than n/3
                        majority.push_back(nums[i]);
                }

                if (majority.size() == 2)   // there can be a maximum of 2 majority elements.
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
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> majority;
        map<int, int> m;

        for(auto num : nums){
            m[num]++;
        }

        for(auto i : m){
            if(i.second > n/3){
                majority.push_back(i.first);
            }
        }

        return majority;
    }
};
*/


// M-3) Extended Boyer Moore’s Voting Algorithm  --> T.C: O(n) + O(n), S.C: O(1) 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> majority;
        int count1 = 0, count2 = 0;
        int elem1, elem2;

        for(int i = 0; i < n; i++){
            if(count1 == 0 && nums[i] != elem2){
                elem1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && nums[i] != elem1){
                elem2 = nums[i];
                count2 = 1;
            }
            else if(nums[i] == elem1){
                count1++;
            }
            else if(nums[i] == elem2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        
        // Manually check if the stored elements elem1 and elem2 are the majority elements:
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == elem1) cnt1++;
            if (nums[i] == elem2) cnt2++;
        }

        if (cnt1 > n/3) 
            majority.push_back(elem1);
        if (cnt2 > n/3) 
            majority.push_back(elem2);

        return majority;
    }
};
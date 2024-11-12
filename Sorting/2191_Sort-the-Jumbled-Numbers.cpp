// Approach 1: Conversion using strings and Sorting
// The expression mapping[c - '0'] converts the character c to its corresponding integer index. [c - '0'] leads to subtraction of ascii values. Eg: if c is '3', its ASCII value is 51. '0' has an ASCII value of 48. So '3' - '0' is 51 - 48, which equals 3.
// The expression mapping[c - '0'] + '0' converts the mapped integer back to a character, which is then appended to the mapped_str. If you have the integer 3 and you add '0' (48) to it, you get 51, which is the ASCII value for the character '3'.
/*
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> pairs;

        for(int i=0; i<nums.size(); i++){
            string str = to_string(nums[i]);
            string mapped_str = "";
            // int mapped_str = 0;    // M-2)
            for(char c : str){
                mapped_str.push_back(mapping[c - '0'] + '0');
                // mapped_str = mapped_str * 10 + mapping[c - '0'];
            }
            int new_num = stoi(mapped_str);
            pairs.push_back({new_num, i});
            // pairs.push_back({mapped_str, i});
        }

        sort(pairs.begin(), pairs.end());   // Sort pairs based on the new_num (mapped value)

        vector<int> ans;
        for(auto& p : pairs){   // Prepare the result vector based on the original indices
            ans.push_back(nums[p.second]);
        }

        return ans;
    }
};
*/


// Approach 2: Conversion without using strings and Sorting
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> pairs;

        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            int mapped_n = 0;
            int base = 1;
            
            if(n == 0){
                mapped_n = mapping[n];
            } 
            else{
                while(n > 0){
                    int digit = n % 10;
                    n /= 10;
                    mapped_n += base * mapping[digit];
                    base *= 10;
                }
            }

            pairs.push_back({mapped_n, i});
        }

        sort(pairs.begin(), pairs.end());

        vector<int> ans;
        for(auto& p : pairs){
            ans.push_back(nums[p.second]);
        }

        return ans;
    }
};

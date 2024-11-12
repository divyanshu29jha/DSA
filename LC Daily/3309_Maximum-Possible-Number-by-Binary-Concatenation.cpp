class Solution {
public:
    string toBinaryString(int num){
        string ans = "";
        while(num > 0){
            ans = (num % 2 == 0 ? '0' : '1') + ans;
            num /= 2;
        }
        return ans;
    }
    
    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaries;
        
        for(int num : nums){
            binaries.push_back(toBinaryString(num));
        }
        
        sort(binaries.begin(), binaries.end(), [](string& a, string& b){
            return a + b > b + a;   // If a + b is greater than b + a, a should come before b in the sorted order.
        });
        
        string concatenatedBinary = "";
        for(string bin : binaries){
            concatenatedBinary += bin;
        }

        int ans = stoi(concatenatedBinary, 0, 2);
        return ans;
    }
};
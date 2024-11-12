// M-1) Brute force
// T.C: O(d^2), S.C: O(d), where d is the number of digits in the integer num.
/*
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);   // O(d)

        string str = s;
        sort(s.begin(), s.end(), greater<int>());   // O(dlogd)

        int j = 0;  // pointer to s
        for(int i=0; i<str.size(); i++){   // O(d^2)
            if(str[i] != s[j]){
                for(int k=str.size()-1; k>i; k--){    // rightmost occurence of s[j]
                    if(str[k] == s[j]){
                        swap(str[i], str[k]);
                        return stoi(str);
                    }
                }
            }
            j++;
        }

        return stoi(str);
    }
};
*/

// M-2) (using space to store maxRight Indices)
// T.C : O(n), S.C : O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num); //stoi 
        int n = s.length();

        vector<int> maxRight(n);   //stores the index of max element to right

        maxRight[n-1] = n-1;
        for(int i = n-2; i >= 0; i--){
            int rightMaxIdx = maxRight[i+1];
            int rightMaxElement = s[rightMaxIdx];

            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
        }

        for(int i = 0; i < n; i++){
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx];
            if(s[i] < maxRightElement) {
                swap(s[i], s[maxRightIdx]);
                return stoi(s);
            }
        }

        return num;
    }
};
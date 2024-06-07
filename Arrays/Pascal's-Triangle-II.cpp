// NOTE: For row r and column c in Pascal's triangle, the element will be rCc for 0-indexed rows and columns.
// nCr = Product of n consecutive integers / Product of r consecutive interges (in reverse manner). eg. 5C3 = 5*4*3 in numerator and 3*2*1 in denominator

// M-1) Brute force --> T.C: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1; S.C: O(1)
/*
class Solution {
public:
    int nCr(int n, int r){
        long long res = 1;
        for(int i = 0; i < r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        
        return res;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; i++){     // for 0-indexed row
            int num = nCr(rowIndex, i);
            ans.push_back(num);
        }   

        // for(int i = 1; i <= rowIndex; i++){
        //     int num = nCr(rowIndex-1, i-1);
        //     ans.push_back(num);
        // }

        return ans;
    }
};
*/


// Current element = prevElement * (rowNumber - colIndex) / colIndex
// M-2) Optimal approach (Good observation required)  --> T.C: O(n), S.C: O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long num = 1;
        ans.push_back(1);

    
        for (int i = 0; i < rowIndex; i++) {   //Printing the rest of the part:
            num *= (rowIndex - i);
            num /= (i+1);
            ans.push_back(num);
        }

        return ans;
    }
};
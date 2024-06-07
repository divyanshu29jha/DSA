// M-1) Brute force --> T.C: O(n^2), S.C: O(n) for temp vector
/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if(numRows >= 1){
            ans.push_back({1});
        }
        if(numRows >= 2){
            ans.push_back({1,1});
        }

        if(numRows >= 3){
            for(int i = 2; i < numRows; i++){
                vector<int> temp;
                temp.push_back(1);
                for(int j = 0; j < i-1; j++){
                    temp.push_back(ans[i-1][j] + ans[i-1][j+1]);
                }
                temp.push_back(1);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
*/


// NOTE: For row r and column c in Pascal's triangle, the element will be (r-1)C(c-1) for 0-indexed.

// M-2) Better approach --> T.C: O(n*n*r) ~ O(n3), where n = number of rows, and r = column index; S.C: O(1)
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

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int row = 1; row <= numRows; row++){
            vector<int> temp;   // temp stores each row
            for(int col = 1; col <= row; col++){
                int num = nCr(row-1, col-1);
                temp.push_back(num);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
*/


// Current element = prevElement * (rowNumber - colIndex) / colIndex

// M-3) Optimal approach (Good observation required)  --> T.C: O(n^2), S.C: O(1)
class Solution {
public:
    vector<int> generateRow(int row) {
        vector<int> ansRow;
        ansRow.push_back(1);    // inserting the 1st element

        long long res = 1;
        for (int col = 1; col < row; col++) {   // calculate the rest of the elements
            res *= (row - col);
            res /= col;
            ansRow.push_back(res);  // res is each element of a row
        }
        
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int row = 1; row <= numRows; row++){     // store all rows of pascal's triangle
            ans.push_back(generateRow(row));
        }
        
        return ans;
    }
};

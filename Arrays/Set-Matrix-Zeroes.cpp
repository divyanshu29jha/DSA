// M-1) Brute force --> T.C: O(m*n) + O((m*n)^2), S.C: O(m*n)
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v; //vector of pairs to store indices {i,j} when matrix[i][j]=0
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0)
                    v.push_back({i, j});
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                for(int k = 0; k < v.size(); k++){
                    if(v[k].first == i || v[k].second == j)
                        matrix[i][j] = 0;
                }
            }
        }

    }
};
*/


// M-2) Better Solution (Using two extra vectors) --> T.C: O(2*m*n), S.C: O(m) + O(n) for 2 vectors.
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();  // no. of rows
        int m = matrix[0].size();   // no. of columns
        vector<int> row(n, 1);   // Initialize row vector with size n to all 1's
        vector<int> col(m, 1);   // Initialize column vector with size m to all 1's

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;  // mark ith index of row wih 0 to indicate that it contains 0
                    col[j] = 0;  // mark jth index of col wih 0 to indicate that it contains 0
                }
            }
        }

        for(int i = 0; i < n; i++){ //mark all (i, j) as 0 if row[i] or col[j] is marked with 1
            for(int j = 0; j < m; j++){
                if(row[i] == 0 || col[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
*/


// M-3) Optimal solution M-2) modified with constant space --> T.C: O(2*m*n), S.C: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();  // no. of rows
        int m = matrix[0].size();   // no. of columns
        int col0 = 1;

        for(int i = 0; i < n; i++){   // step 1: Traverse the matrix and mark 1st row & col accordingly:
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;    // mark i-th row:
                    if(j != 0){
                        matrix[0][j] = 0;    // mark j-th col:
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1; i < n; i++){     // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Finally mark the 1st col & then 1st row:
        for(int j = 0; j < m; j++){
            if(matrix[0][0] == 0){
                matrix[0][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            if(col0 == 0){
                matrix[i][0] = 0;
            }
        }

    }
};

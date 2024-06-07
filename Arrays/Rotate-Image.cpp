// M-1) Brute force --> T.C: O(n*n); S.C: O(n*n)
/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // no. of rows =  no. of cols
        vector<vector<int>> temp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = matrix[n-1-j][i];
                // temp[j][n-1-i] = matrix[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = temp[i][j];
            }
        }
    }
};
*/

// M-2) Optimal inplace solution --> T.C: O(n/2 * n/2) + O(n * n/2); S.C: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // no. of rows =  no. of cols
        vector<vector<int>> temp(n, vector<int>(n, 0));

        for(int i = 0; i < n-1; i++){     // M-1) for transposing the matrix
            for(int j = i + 1; j < n; j++){
                if( i != j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }

        // for(int i = 0; i < n; i++){     // M-2) for transposing the matrix
        //     for(int j = 0; j < i; j++){
        //         if( i != j)
        //             swap(matrix[i][j], matrix[j][i]);
        //     }
        // }

        for(int i = 0; i < n; i++){    // reversing each row of the matrix
            reverse(matrix[i].begin(), matrix[i].end());    // O(n/2)
        }
    }
};
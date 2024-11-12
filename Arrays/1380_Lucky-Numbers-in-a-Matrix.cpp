class Solution{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();     // no. of rows 
        int n = matrix[0].size();  // no. of columns
        
        vector<int> minInRow;
        for(int i=0; i<m; i++){
            int minNo = *min_element(matrix[i].begin(), matrix[i].end());
            minInRow.push_back(minNo);
        }

        vector<int> maxInCol = matrix[0];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] > maxInCol[j])
                    maxInCol[j] = matrix[i][j];
            }
        }

        vector<int> lucky;   // stores ans
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == minInRow[i] && matrix[i][j] == maxInCol[j])
                    lucky.push_back(matrix[i][j]);
            }
        }

        return lucky;
    }
};


// Better way to write above method
/*
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowMin(m, INT_MAX);
        vector<int> colMax(n, INT_MIN);
        
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }
        
       
        vector<int> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
};
*/
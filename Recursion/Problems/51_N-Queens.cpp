// M-1) Recursion + Backtracking
// T.C: O (N! * N). Exponential in nature, since we are trying out all ways. 
// S.C: O(N^2)
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        // since we are placing only one Q in a col at a time, and placing from left to right col-wise,
        // only check upper and lower left diagonals and left rows
        int r = row;
        int c = col;
        while(row >= 0 && col >= 0){    // check for upper left diagonal for given board[row][col]
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = r;
        col = c;
        while(row < n && col >= 0){    // check for lower left diagonal for given board[row][col]
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        row = r;
        col = c;
        while(col >= 0){     // check for same row & left cols for given board[row][col]
            if(board[row][col] == 'Q') return false;
            col--;
        }

        return true;    // Should return true if no conflicts found
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){     // for a given col, iterate through the rows and place Q row-wise
            if(isSafe(row, col, board, n)){   // O(n)
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);    // once a Q is placed in a col, then check for next col
                board[row][col] = '.';     // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;   
        vector<string> board;   // contains one possible solution board
        string s(n, '.');    // single row of solution board

        for(int i=0; i<n; i++){
            board.push_back(s);    // n rows in board
        }

        // vector<string> board(n, string(n, '.'));  // Initialize the board with n rows of n '.' characters
        int col = 0;
        solve(col, board, ans, n);  // for a given col, place queens in each row and check

        return ans;
    }
};



// M-2) Optimal Backtracking (No isSafe function required). Use hashing to store leftRow, upperDiagonal and lowerDiagonal values.
// T.C: O (N! * N). Exponential in nature, since we are trying out all ways. 
// S.C: O(N^2)
/*
class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftrow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){
            if(leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[(n-1) + col - row] == 0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[(n-1) + col - row] = 1;
                
                solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                
                board[row][col] = '.';    // backtrack
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[(n-1) + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;   
        vector<string> board(n, string(n, '.'));  // Initialize the board with n rows of n '.' characters   //  // contains one possible solution board
        
        vector<int> leftrow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);
        
        int col = 0;
        solve(col, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);    // for a given col, place queens in each row and check

        return ans;
    }
};
*/

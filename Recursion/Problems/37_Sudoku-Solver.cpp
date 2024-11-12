// T.C: O(9(n^2)), in the worst case, for each cell in the n^2 board, we have 9 possible numbers.
// S.C: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
// 1) Our main recursive function(solve()) is going to just do a plain matrix traversal of the sudoku board. When we find an empty cell, we pause and try to put all available numbers(1 - 9) in that particular empty cell.
// 2) We need another loop to do that. We have another function(isValid()) which will check whether the number we have inserted into that empty cell will not violate any conditions.
// 3) If it is violating, we try with the next number. If it is not, we call the same function recursively, but this time with the updated state of the board. Now, as usual it tries to fill the remaining cells in the board in the same way.
// 4) Now we'll come to the returning values. If at any point we cannot insert any numbers from 1 to 9 in a particular cell, it means the current state of the board is wrong and we need to backtrack. An important point to follow is, we need to return false to let the parent function(which is called this function) know that we cannot fill this way. This will serve as a hint to that function, that it needs to try with the next possible number. 

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++){
            if(board[i][col] == ch)    // check in same row for duplicates
                return false;

            if(board[row][i] == ch)   // check in same col for duplicates
                return false;

            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch)    // check in same 3*3 subgrid for duplicates
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>> & board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;

                            if(solve(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;   // no possible ch can be filled in board[i][j]
                }
            }
        }

        return true;    // board traversed completely
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


// Another way to write
/*
class Solution {
public:
    // Function to find an empty location in the board, denoted by '.'
    bool findEmptyLocation(vector<vector<char>> &board, int &row, int &col) {
        for(row = 0; row < 9; row++) {
            for(col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    return true;  // Found an empty location
                }
            }
        }
        return false;  // No empty locations left
    }

    // Function to check if placing a character 'ch' at board[row][col] is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char ch) {
        // Check the row for duplicates
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == ch) return false;
        }
        // Check the column for duplicates
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == ch) return false;
        }
        // Check the 3x3 subgrid for duplicates
        int rf = row - (row % 3);  // Row offset for the subgrid
        int cf = col - (col % 3);  // Column offset for the subgrid
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i + rf][j + cf] == ch) return false;
            }
        }
        return true;  // Valid placement
    }


    // Main function to solve the Sudoku
    bool solveSudoku(vector<vector<char>>& board) {
        int row, col;
        if(!findEmptyLocation(board, row, col)) {     // If no empty location is found, the board is solved
            return true;   
        }
        
        for(char c = '1'; c <= '9'; c++){    // Try placing numbers 1 to 9 in the empty cell
            if(isValid(board, row, col, c)){
                board[row][col] = c;  // Place the number
                if(solveSudoku(board)) return true;  // Recursively solve the rest of the board
                board[row][col] = '.';  // Backtrack if needed
            }
        }
        
        return false;  // Trigger backtracking
    }
};
*/
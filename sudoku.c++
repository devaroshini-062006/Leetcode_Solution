#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                // Find an empty cell
                if (board[r][c] == '.') {
                    // Try digits '1' through '9'
                    for (char val = '1'; val <= '9'; val++) {
                        if (isValid(board, r, c, val)) {
                            board[r][c] = val; // Tentatively place the digit
                            
                            // Recursively try to solve the rest of the board
                            if (solve(board)) {
                                return true; 
                            }
                            
                            board[r][c] = '.'; // Backtrack if choice failed
                        }
                    }
                    return false; // Triggers backtracking to previous choices
                }
            }
        }
        return true; // Whole board is filled successfully
    }

    bool isValid(const vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            // Check row constraint
            if (board[row][i] == val) return false;
            
            // Check column constraint
            if (board[i][col] == val) return false;
            
            // Check 3x3 sub-box constraint
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == val) return false;
        }
        return true;
    }
};


class Solution {// Time Complexity ---> Worst case = O(9^81)                            Space Complexity ---> O(1)
public:
    // Function to check whether placing 'digit' at board[row][col] is valid
    bool isValid(int row, int col, char digit, vector<vector<char>>& board) {
        // Check the entire column for the same digit
        for (int i = 0; i < 9; i++) 
        {
            if (board[i][col] == digit)
            {
                return false;
            } 
        }

        // Check the entire row for the same digit
        for (int j = 0; j < 9; j++) 
        {
            if (board[row][j] == digit) 
            {
                return false;
            }
        }

        // Find the starting index of the 3x3 subgrid
        // startRow, startCol → top-left corner of the 3x3 subgrid containing (row, col).
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        // Check inside the 3x3 subgrid
        for (int r = 0; r < 3; r++) 
        {
            for (int c = 0; c < 3; c++) 
            {
                if (board[startRow + r][startCol + c] == digit)
                {
                    return false;
                }
            }
        }
        
        // digit can be placed
        return true; 
    }

    // Recursive backtracking function to solve the Sudoku
    bool solve(vector<vector<char>>& board) 
    {
        // Loop over each cell of the Sudoku board
        for (int row = 0; row < 9; row++) 
        {
            for (int col = 0; col < 9; col++) 
            {    
                // If the cell is empty ('.')
                if (board[row][col] == '.') 
                {
                    // Try placing digits from '1' to '9'
                    for (char digit = '1'; digit <= '9'; digit++) 
                    {
                        // Check if placing 'digit' is valid
                        if (isValid(row, col, digit, board)) 
                        {
                            // Place the digit
                            board[row][col] = digit; 
                            
                            // Recursively try solving with this placement
                            if (solve(board) == true)
                            {
                                return true;
                            } 
                            
                            // Backtrack (undo placement if it fails later)
                            board[row][col] = '.';
                        }
                    }

                    // If no digit works in this cell, return false (backtrack)
                    return false;
                }
            }
        }

        // If no empty cells are left, Sudoku is solved
        return true;
    }

    // Main function called to solve Sudoku
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

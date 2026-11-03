*********************************************APPROACH 1st*************************************************************

class Solution {// Time: O(N! * N)                             Space : O(N)
public:

    // Checks whether we can safely place a queen at (row, col)
    bool isValid(int row, int col, vector<string>& board, int n)
    {
        // 1. Check the same column in the previous rows
        for(int i = row; i >= 0; i--)
        {
            if(board[i][col] == 'Q')
            {
                return false; // Another queen exists in this column
            }
        }

        // 2. Check the upper-left diagonal
        // Move one row up and one column left
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if(board[i][j] == 'Q')
            {
                return false; // Another queen exists on this diagonal
            }
        }

        // 3. Check the upper-right diagonal
        // Move one row up and one column right
        for(int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if(board[i][j] == 'Q')
            {
                return false; // Another queen exists on this diagonal
            }
        }

        // No attacking queen found, so this position is safe
        return true;
    }

    // Places queens row by row using backtracking
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans)
    {
        // Base case: all N queens have been placed successfully
        if(row >= n)
        {
            ans.push_back(board); // Store this valid arrangement
            return;
        }

        // Try placing a queen in every column of the current row
        for(int col = 0; col < n; col++)
        {
            // Check whether the current position is safe
            if(isValid(row, col, board, n))
            {
                // Choose: place the queen
                board[row][col] = 'Q';

                // Explore: move to the next row
                solve(row + 1, n, board, ans);

                // Backtrack: remove the queen to try another column
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Initially, create an empty N x N chessboard
        // Every cell contains '.'
        vector<string> board(n, string(n, '.'));

        // Start placing queens from row 0
        solve(0, n, board, ans);

        // Return all valid arrangements
        return ans;
    }
};

************************************************APPROACH 2nd(OPTIMAL)*****************************************************

class Solution {// Time Complexity: O(N!)                           Space Complexity: O(N)
public:
    // Stores columns where queens are already placed
    unordered_set<int> column;

    // Stores occupied diagonals (row + col)
    unordered_set<int> diagonal;

    // Stores occupied anti-diagonals (row - col)
    unordered_set<int> antiDiagonal;

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans)
    {
        // Base case: all N queens have been placed successfully
        if(row >= n)
        {
            ans.push_back(board); // Store the valid board arrangement
            return;
        }

        // Try placing a queen in every column of the current row
        for(int col = 0; col < n; col++)
        {
            // Every main diagonal has a constant row + col value
            int diagonalConst = row + col;

            // Every anti-diagonal has a constant row - col value
            int antiDiagonalConst = row - col;

            // Check whether the column or either diagonal is already occupied
            if(column.find(col) != column.end() ||
               diagonal.find(diagonalConst) != diagonal.end() ||
               antiDiagonal.find(antiDiagonalConst) != antiDiagonal.end())
            {
                continue; // Position is unsafe, try the next column
            }

            // Mark the current column and both diagonals as occupied
            column.insert(col);
            diagonal.insert(diagonalConst);
            antiDiagonal.insert(antiDiagonalConst);

            // Place the queen at the current position
            board[row][col] = 'Q';

            // Recursively place a queen in the next row
            solve(row + 1, n, board, ans);

            // Backtrack: remove the queen and free its column and diagonals
            column.erase(col);
            diagonal.erase(diagonalConst);
            antiDiagonal.erase(antiDiagonalConst);

            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Create an initially empty N x N chessboard
        vector<string> board(n, string(n, '.'));

        // Start placing queens from row 0
        solve(0, n, board, ans);

        // Return all valid arrangements
        return ans;
    }
};

/*

╔══════════════════════════════════════╗
║          N-QUEENS (BACKTRACKING)     ║
╠══════════════════════════════════════╣
║ KEY LOGIC:                           ║
║ • One queen per row                  ║
║ • column      → row/col-independent  ║
║ • diagonal    → row + col            ║
║ • antiDiagonal→ row - col            ║
║                                      ║
║ STEPS:                               ║
║ 1. Check column and both diagonals   ║
║ 2. Place queen ('Q')                 ║
║ 3. Recur for next row                ║
║ 4. Backtrack (remove queen)          ║
║ 5. Store board when row == n         ║
╠══════════════════════════════════════╣
║ TIME:  O(N! × N²) including copying  ║
║ SPACE: O(N²) auxiliary               ║
║ OUTPUT: O(S × N²)                    ║
╚══════════════════════════════════════╝

*/

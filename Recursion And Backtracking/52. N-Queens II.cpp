
class Solution {// TC ---> O(N!)                                     SC ---> O(N)
public:

    // Tries to place queens row by row
    void solve(int row, int n,unordered_set<int>& column,unordered_set<int>& diagonal,unordered_set<int>& antiDiagonal,int &ans)
    {
        // Base case: All N queens have been placed successfully
        if(row == n)
        {
            ans++;  // Found one valid arrangement
            return;
        }

        // Try placing a queen in every column of the current row
        for(int col = 0; col < n; col++)
        {
            // Identify the main diagonal using row - col
            int diag_id = row - col;

            // Identify the anti-diagonal using row + col
            int antiDiag_id = row + col;

            // Check whether the current position is already occupied
            // by another queen in the same column or either diagonal
            if(column.find(col) != column.end() ||
               diagonal.find(diag_id) != diagonal.end() ||
               antiDiagonal.find(antiDiag_id) != antiDiagonal.end())
            {
                continue; // Position is unsafe, try the next column
            }

            // STEP 1: Make the choice
            // Mark the current column and both diagonals as occupied
            column.insert(col);
            diagonal.insert(diag_id);
            antiDiagonal.insert(antiDiag_id);

            // STEP 2: Explore
            // Move to the next row and try placing another queen
            solve(row + 1, n, column, diagonal, antiDiagonal, ans);

            // STEP 3: Undo the choice (Backtracking)
            // Remove the current queen's occupied column and diagonals
            // so that other possible arrangements can be explored
            column.erase(col);
            diagonal.erase(diag_id);
            antiDiagonal.erase(antiDiag_id);
        }
    }

    int totalNQueens(int n) {

        // Stores the total number of valid arrangements
        int ans = 0;

        // Stores columns that already contain a queen
        unordered_set<int> column;

        // Stores occupied main diagonals (row - col)
        unordered_set<int> diagonal;

        // Stores occupied anti-diagonals (row + col)
        unordered_set<int> antiDiagonal;

        // Start placing queens from the first row (row = 0)
        solve(0, n, column, diagonal, antiDiagonal, ans);

        // Return the total number of valid arrangements
        return ans;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│                  N-QUEENS II (LC 52)                 │
├──────────────────────────────────────────────────────┤
│ APPROACH: Backtracking + Hash Sets                   │
│                                                      │
│ KEY IDEA:                                            │
│ • Place exactly one queen in each row.               │
│ • column → col                                       │
│ • Main diagonal → row - col                          │
│ • Anti-diagonal → row + col                          │
│ • Use 3 sets to track occupied positions.            │
│                                                      │
│ STEPS:                                               │
│ • Try every column in the current row.               │
│ • Skip if column or diagonal is occupied.            │
│ • Place queen and mark all 3 sets.                   │
│ • Recursively move to the next row.                  │
│ • Backtrack by removing marked positions.            │
│ • If row == n, increment ans.                        │
│                                                      │
│ BASE CASE:                                           │
│ if(row == n) ans++;                                  │
│                                                      │
│ COMPLEXITY:                                          │
│ • Time:  O(N!) upper bound                           │
│ • Space: O(N)                                        │
│ • Extra: O(N) — Sets + Recursion Stack               │
│                                                      │
│ PATTERN: Choose → Explore → Undo                     │
└──────────────────────────────────────────────────────┘

*/

***************************************************APPROACH 1st(USING EXTRA SPACE)***************************************

class Solution {// Time  : O(n × m)                         Space : O(n × m)
public:

    // These two arrays represent the 8 possible directions
    // around the current cell.
    //
    // Example:
    //
    // (-1,-1)  (-1,0)  (-1,1)
    // ( 0,-1)   CELL   ( 0,1)
    // ( 1,-1)  ( 1,0)  ( 1,1)
    //
    vector<int> delRow = {-1,-1,0,1,1,1,0,-1};
    vector<int> delCol = {0,1,1,1,0,-1,-1,-1};


    // This function calculates the next state
    // of one particular cell.
    //
    // row, col -> current cell
    // n, m     -> dimensions of the board
    // board    -> original board
    // ans      -> board containing the next generation
    void solve(int row, int col,int n, int m,vector<vector<int>>& board,
               vector<vector<int>>& ans)
    {
        // Safety check:
        // Make sure the current cell is inside the board.
        if(row < 0 || col < 0 || row >= n || col >= m)
        {
            return;
        }


        // Number of live neighbors around the current cell
        int liveCells = 0;


        // There are exactly 8 possible neighbors
        for(int k = 0; k < 8; k++)
        {
            // Calculate the neighbor's row
            int newRow = row + delRow[k];

            // Calculate the neighbor's column
            int newCol = col + delCol[k];


            // Make sure the neighbor is inside the board
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
            {
                // If the neighbor is alive,
                // increase the live neighbor count.
                if(board[newRow][newCol] == 1)
                {
                    liveCells++;
                }
            }
        }


        // Now apply the Game of Life rules
        // to the current cell.


        // CASE 1:
        // Current cell is ALIVE
        if(board[row][col] == 1)
        {
            // If it has fewer than 2 live neighbors,
            // it dies because of underpopulation.
            if(liveCells < 2)
            {
                ans[row][col] = 0;
            }

            // If it has exactly 2 or 3 live neighbors,
            // it survives.
            else if(liveCells == 2 || liveCells == 3)
            {
                ans[row][col] = 1;
            }

            // If it has more than 3 live neighbors,
            // it dies because of overpopulation.
            else if(liveCells > 3)
            {
                ans[row][col] = 0;
            }
        }
        // CASE 2:
        // Current cell is DEAD
        else
        {
            // A dead cell becomes alive
            // if it has exactly 3 live neighbors.
            if(liveCells == 3)
            {
                ans[row][col] = 1;
            }

            // Otherwise, it remains dead.
            else
            {
                ans[row][col] = 0;
            }
        }
    }


    // Main function
    void gameOfLife(vector<vector<int>>& board)
    {
        // Number of rows
        int n = board.size();

        // Number of columns
        int m = board[0].size();


        // Create a new board to store the NEXT generation.
        //
        // We cannot directly modify board because
        // every cell's next state must be calculated
        // using the ORIGINAL board.
        vector<vector<int>> ans(n, vector<int>(m));


        // Visit every cell of the board
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Calculate the next state of
                // the current cell.
                solve(i, j, n, m, board, ans);
            }
        }


        // After calculating all cells,
        // replace the original board with
        // the next generation.
        board = ans;
    }
};

/*

┌────────────────────────────────────┐
│           GAME OF LIFE             │
├────────────────────────────────────┤
│ Matrix + Simulation problem        │
│                                    │
│ For every cell:                    │
│ → Check all 8 neighbors            │
│ → Count live neighbors             │
│ → Apply Game of Life rules         │
│                                    │
│ ALIVE CELL (1):                    │
│ < 2 neighbors → DEAD               │
│ 2 or 3 neighbors → ALIVE           │
│ > 3 neighbors → DEAD               │
│                                    │
│ DEAD CELL (0):                     │
│ Exactly 3 neighbors → ALIVE        │
│ Otherwise → DEAD                   │
│                                    │
│ Use separate ans matrix            │
│ because updates are simultaneous.  │
│                                    │
│ No BFS / DFS / visited needed.     │
│                                    │
│ Time  : O(n × m)                   │
│ Space : O(n × m)                   │
└────────────────────────────────────┘

*/

***********************************************APPROACH 2nd(INPLACE-->OPTIMAL)******************************************

class Solution {// Time  : O(n × m)                                 Space : O(1)
public:

    // 8 possible directions around a cell
    //
    // (-1,-1)  (-1,0)  (-1,1)
    // ( 0,-1)   CELL   ( 0,1)
    // ( 1,-1)  ( 1,0)  ( 1,1)
    //
    vector<int> delRow = {-1,-1,0,1,1,1,0,-1};
    vector<int> delCol = {0,1,1,1,0,-1,-1,-1};


    // Checks whether a cell is inside the board
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }


    void gameOfLife(vector<vector<int>>& board)
    {
        int n = board.size();
        int m = board[0].size();


        // First pass:
        // Calculate the next state of every cell.
        //
        // We cannot simply change 0 -> 1 or 1 -> 0
        // because later cells still need the ORIGINAL state.
        //
        // Therefore, we use temporary values:
        //
        //  0  = originally dead  -> stays dead
        //  1  = originally alive -> stays alive
        // -1  = originally alive -> becomes dead
        //  2  = originally dead  -> becomes alive
        //
        // This allows us to store both the old and new
        // state inside the same cell.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int liveCells = 0;


                // Check all 8 neighbors
                for(int k = 0; k < 8; k++)
                {
                    int newRow = i + delRow[k];
                    int newCol = j + delCol[k];


                    // Check if neighbor is inside the board
                    //
                    // abs(value) == 1 means:
                    //
                    //  1  -> originally alive
                    // -1  -> originally alive but will die
                    //
                    // So both 1 and -1 should be counted
                    // as LIVE neighbors from the original board.
                    if(isValid(newRow, newCol, n, m) && abs(board[newRow][newCol]) == 1)
                    {
                        liveCells++;
                    }
                }


                // ------------------------------------------------
                // CASE 1: Current cell is originally ALIVE
                // ------------------------------------------------
                if(board[i][j] == 1)
                {
                    // Fewer than 2 live neighbors:
                    // Cell dies because of underpopulation.
                    //
                    // More than 3 live neighbors:
                    // Cell dies because of overpopulation.
                    if(liveCells < 2 || liveCells > 3)
                    {
                        // -1 means:
                        // Originally ALIVE -> becomes DEAD
                        board[i][j] = -1;
                    }
                    // Exactly 2 or 3 live neighbors:
                    // Cell survives.
                    else
                    {
                        // Remains alive
                        board[i][j] = 1;
                    }
                }


                // ------------------------------------------------
                // CASE 2: Current cell is originally DEAD
                // ------------------------------------------------
                else if(board[i][j] == 0)
                {
                    // A dead cell becomes alive
                    // if it has exactly 3 live neighbors.
                    if(liveCells == 3)
                    {
                        // 2 means:
                        // Originally DEAD -> becomes ALIVE
                        board[i][j] = 2;
                    }
                    // Otherwise it remains dead.
                    else
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }


        // Second pass:
        //
        // Convert temporary states into the final
        // Game of Life values.
        //
        //  1  -> 1 (alive)
        // -1  -> 0 (dead)
        //  2  -> 1 (alive)
        //  0  -> 0 (dead)
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // 1 and 2 represent cells that are
                // ALIVE in the next generation.
                if(board[i][j] >= 1)
                {
                    board[i][j] = 1;
                }
                // 0 and -1 represent cells that are
                // DEAD in the next generation.
                else
                {
                    board[i][j] = 0;
                }
            }
        }
    }
};

/*

⭐ The most important trick

Your whole O(1) solution depends on this:

abs(board[newRow][newCol]) == 1

Because:

┌────────────────────────────────────┐
│ ORIGINAL → NEXT STATE              │
├────────────────────────────────────┤
│  0 → 0    Dead  → Dead             │
│  1 → 1    Alive → Alive            │
│  1 → -1   Alive → Dead             │
│  0 → 2    Dead  → Alive            │
└────────────────────────────────────┘

┌────────────────────────────────────┐
│      GAME OF LIFE — OPTIMAL        │
├────────────────────────────────────┤
│ Category: Matrix + Simulation      │
│                                    │
│ Check all 8 neighbors              │
│ for every cell.                    │
│                                    │
│ IN-PLACE ENCODING                  │
│                                    │
│  0 → Dead  → Dead   = 0            │
│  1 → Alive → Alive  = 1            │
│  1 → Alive → Dead   = -1           │
│  0 → Dead  → Alive  = 2            │
│                                    │
│ Count ORIGINAL live cells:         │
│ abs(board[nr][nc]) == 1            │
│                                    │
│ ALIVE (1):                         │
│ < 2 → DEAD                         │
│ 2 or 3 → ALIVE                     │
│ > 3 → DEAD                         │
│                                    │
│ DEAD (0):                          │
│ exactly 3 → ALIVE                  │
│ otherwise → DEAD                   │
│                                    │
│ Why -1 and 2?                      │
│ Store old + new state together.    │
│                                    │
│ Final conversion:                  │
│ >= 1 → 1                           │
│ < 1  → 0                           │
│                                    │
│ No BFS / DFS / visited / ans.      │
│                                    │
│ Time  : O(n × m)                   │
│ Space : O(1)                       │
└────────────────────────────────────┘

*/

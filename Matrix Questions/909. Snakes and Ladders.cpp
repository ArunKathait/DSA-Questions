class Solution {// Time: O(n²)                                 Space: O(n²)
public:

    // Converts a square number (1, 2, 3, ..., n*n)
    // into its corresponding matrix coordinates (row, col).
    pair<int, int> getCoordinates(int num, int n)
    {
        // Find which row the square belongs to,
        // assuming rows are counted from the TOP.
        //
        // Example for n = 6:
        // 1-6   -> rowFromTop = 0
        // 7-12  -> rowFromTop = 1
        // 13-18 -> rowFromTop = 2
        int rowFromTop = (num - 1) / n;

        // The board matrix starts from the top,
        // but Snakes and Ladders numbering starts from the bottom.
        //
        // So convert rowFromTop into rowFromBottom.
        int rowFromBottom = (n - 1) - rowFromTop;

        // Find the column assuming the row is numbered
        // from left to right.
        //
        // Example:
        // num = 1, n = 6
        // col = (1 - 1) % 6 = 0
        //
        // num = 6
        // col = (6 - 1) % 6 = 5
        int col = (num - 1) % n;

        // The board follows a zig-zag pattern.
        //
        // Some rows are numbered:
        // left -> right
        //
        // while the next row is:
        // right -> left
        //
        // This condition identifies the rows where
        // we need to reverse the column.
        if((rowFromBottom % 2 == 0 && n % 2 == 0) || (rowFromBottom % 2 != 0 && n % 2 != 0))
        {
            // Reverse the column.
            //
            // Example:
            // col = 0 -> n-1
            // col = 1 -> n-2
            // col = 2 -> n-3
            col = (n - 1) - col;
        }

        // Return the final matrix coordinates.
        return {rowFromBottom, col};
    }


    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();

        // visited[row][col] tells us whether we have
        // already reached this board square.
        //
        // We use visited because BFS can reach the same
        // square through multiple paths.
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // BFS queue.
        //
        // Instead of storing (row, col), we store the
        // actual Snakes and Ladders square number.
        queue<int> q;

        // We start from square 1.
        q.push(1);

        // Square 1 corresponds to the bottom-left corner.
        // Mark it as visited.
        visited[n - 1][0] = true;

        // Number of dice throws made so far.
        int steps = 0;


        // BFS continues while there are squares to process.
        while(!q.empty())
        {
            // Number of nodes/squares at the current BFS level.
            //
            // Every node at this level requires the same
            // number of dice throws.
            int size = q.size();

            while(size--)
            {
                // Take the current square from the queue.
                int x = q.front();
                q.pop();

                // If we reached the final square,
                // return the number of dice throws.
                if(x == n * n)
                {
                    return steps;
                }


                // From the current square, we can roll
                // the dice from 1 to 6.
                for(int k = 1; k <= 6; k++)
                {
                    // Calculate the square we can reach
                    // using this dice value.
                    int val = x + k;

                    // We cannot move beyond the final square.
                    if(val > n * n)
                    {
                        break;
                    }


                    // Convert the square number into
                    // board matrix coordinates.
                    pair<int, int> p = getCoordinates(val, n);

                    int row = p.first;
                    int col = p.second;


                    // If we have already visited this square,
                    // there is no need to process it again.
                    if(visited[row][col] == true)
                    {
                        continue;
                    }


                    // Mark this square as visited.
                    visited[row][col] = true;


                    // If board[row][col] == -1,
                    // there is no snake or ladder.
                    //
                    // So we simply stay at 'val'.
                    if(board[row][col] == -1)
                    {
                        q.push(val);
                    }

                    // Otherwise, there is a snake or ladder.
                    //
                    // board[row][col] contains the destination
                    // square.
                    //
                    // Example:
                    // val = 14
                    // board[14] = 35
                    //
                    // We move directly:
                    // 14 -> 35
                    else
                    {
                        q.push(board[row][col]);
                    }
                }
            }

            // We have finished processing one BFS level.
            //
            // Therefore, one more dice throw is required
            // to reach the next level.
            steps++;
        }

        // If the final square cannot be reached,
        // return -1.
        return -1;
    }
};

/*

┌────────────────────────────────────────────┐
│          SNAKES & LADDERS — BFS            │
├────────────────────────────────────────────┤
│ PATTERN                                    │
│ BFS + Zig-Zag Coordinate Conversion        │
│                                            │
│ START                                      │
│ q.push(1)                                  │
│ visited[n-1][0] = true                     │
│ steps = 0                                  │
│                                            │
│ COORDINATES                                │
│ rowFromTop = (num-1) / n                   │
│ rowFromBottom = (n-1) - rowFromTop         │
│ col = (num-1) % n                          │
│                                            │
│ REVERSE COLUMN:                            │
│ if((rowFromBottom % 2 == 0 && n % 2 == 0)  │
│ || (rowFromBottom % 2 != 0 && n % 2 != 0)) │
│                                            │
│ Meaning:                                   │
│ → row and n have SAME parity               │
│ → both EVEN OR both ODD                    │
│ → reverse the column                       │
│                                            │
│ col = (n-1) - col                          │
│                                            │
│ BFS                                        │
│ Try dice k = 1 → 6                         │
│ val = x + k                                │
│ if(val > n*n) → break                      │
│                                            │
│ Convert val → (row, col)                   │
│ if visited → continue                      │
│ visited[row][col] = true                   │
│                                            │
│ SNAKE / LADDER                             │
│ board[row][col] == -1 → q.push(val)        │
│ otherwise → q.push(board[row][col])        │
│                                            │
│ STEPS                                      │
│ 1 BFS level = 1 dice throw                 │
│ x == n*n → return steps                    │
│ Cannot reach → return -1                   │
│                                            │
│ TC: O(n²)                                  │
│ SC: O(n²)                                  │
└────────────────────────────────────────────┘

🔑 Condition to remember
(rowFromBottom % 2 == 0 && n % 2 == 0)
||
(rowFromBottom % 2 != 0 && n % 2 != 0)

Meaning:

Both rowFromBottom and n are either even or odd → same parity → reverse the column.

*/

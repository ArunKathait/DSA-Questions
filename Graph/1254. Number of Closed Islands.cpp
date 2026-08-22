
class Solution {
public:

    // DFS to visit the complete island
    void dfs(int row, int col, int n, int m, vector<vector<int>>& grid)
    {
        // Stop DFS if:
        // 1. We go outside the grid
        // 2. Current cell is not land (0)
        //    This also handles already visited cells (1)
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] != 0)
        {
            return;
        }

        // Mark current land cell as visited
        // We change 0 -> 1
        grid[row][col] = 1;

        // Four possible directions:
        // Up    -> (-1, 0)
        // Right -> (0, 1)
        // Down  -> (1, 0)
        // Left  -> (0, -1)
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Explore all 4 neighbouring cells
        for(int k = 0; k < 4; k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Continue DFS from the neighbour
            dfs(newRow, newCol, n, m, grid);
        }
    }


    int closedIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();


        // ------------------------------------------------
        // STEP 1:
        // Remove all islands connected to the boundary.
        //
        // Any island touching the boundary cannot be
        // a closed island.
        // ------------------------------------------------

        // Check first and last column
        for(int i = 0; i < n; i++)
        {
            // First column
            dfs(i, 0, n, m, grid);

            // Last column
            dfs(i, m - 1, n, m, grid);
        }


        // Check first and last row
        for(int j = 0; j < m; j++)
        {
            // First row
            dfs(0, j, n, m, grid);

            // Last row
            dfs(n - 1, j, n, m, grid);
        }


        // ------------------------------------------------
        // STEP 2:
        // Now all boundary-connected islands have been
        // converted from 0 -> 1.
        //
        // Therefore, any remaining 0 represents a
        // closed island.
        // ------------------------------------------------

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Found a remaining land cell
                if(grid[i][j] == 0)
                {
                    // This is the starting cell of
                    // one closed island.
                    ans++;

                    // Visit the complete closed island
                    // and mark all its cells as visited.
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return ans;
    }
};

/*    

╔══════════════════════════════════════╗
║          🏝️ CLOSED ISLAND DFS        ║
╠══════════════════════════════════════╣
║                                      ║
║  💡 INTUITION                        ║
║  Remove boundary-connected islands   ║
║  first. Remaining 0s are closed.     ║
║                                      ║
║  🔹 0 → Land                         ║
║  🔹 1 → Water / Visited              ║
║                                      ║
║  STEP 1:                             ║
║  DFS from boundary 0s                ║
║       ↓                              ║
║  Convert connected 0 → 1             ║
║       ↓                              ║
║  They cannot be closed islands       ║
║                                      ║
║  STEP 2:                             ║
║  Scan entire grid                    ║
║       ↓                              ║
║  Find remaining 0                    ║
║       ↓                              ║
║  ans++                               ║
║       ↓                              ║
║  DFS entire island                   ║
║                                      ║
║  🔑 KEY IDEA                         ║
║  Boundary island → Remove it         ║
║  Remaining island → Closed island    ║
║                                      ║
║  ⏱️ TIME                             ║
║  O(n × m)                            ║
║                                      ║
║  💾 SPACE                            ║
║  O(n × m) worst case                 ║
║  → DFS recursion stack               ║
║                                      ║
╚══════════════════════════════════════╝

*/

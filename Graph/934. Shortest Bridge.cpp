
class Solution {// TC: O(n × m)                                            SC: O(n × m)
public:

    // DFS is used to find and mark the COMPLETE first island.
    // Every cell belonging to the first island is also pushed
    // into the BFS queue.
    void dfs(int row, int col, int n, int m,vector<vector<int>>& grid,vector<vector<bool>>& visited,queue<pair<int,int>>& q)
    {
        // Stop DFS if:
        // 1. We go outside the grid
        // 2. Current cell is water (0)
        // 3. Current cell is already visited
        if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || visited[row][col] == true)
        {
            return;
        }

        // Mark current island cell as visited
        visited[row][col] = true;

        // Put this cell into the BFS queue.
        // Later, BFS will start expanding from ALL
        // cells of the first island simultaneously.
        q.push({row, col});

        // Directions:
        //        (-1,0)
        //          ↑
        // (0,-1) ←   → (0,1)
        //          ↓
        //        (1,0)
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Visit all 4 neighbouring cells
        for(int k = 0; k < 4; k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Continue DFS from the neighbour
            dfs(newRow, newCol, n, m, grid, visited, q);
        }
    }


    // Checks whether a cell can be processed by BFS.
    bool isValid(int row, int col, int n, int m,vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
        // Invalid if:
        // 1. Outside the grid
        // 2. Already visited
        if(row < 0 || col < 0 || row >= n || col >= m || visited[row][col] == true)
        {
            return false;
        }

        return true;
    }


    int shortestBridge(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // visited tells us whether a cell has already
        // been processed by DFS or BFS.
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Queue used for Multi-Source BFS.
        // Initially it will contain ALL cells
        // belonging to the first island.
        queue<pair<int,int>> q;


        // ------------------------------------------------
        // STEP 1: FIND THE FIRST ISLAND
        // ------------------------------------------------

        bool found = false;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Find the first land cell
                if(grid[i][j] == 1)
                {
                    // DFS marks the complete first island.
                    //
                    // For example:
                    //
                    // 1 1
                    // 1 0
                    //
                    // DFS will mark all three 1s
                    // and put them into q.
                    dfs(i, j, n, m, grid, visited, q);

                    found = true;

                    // No need to search more cells
                    // in this row.
                    break;
                }
            }

            // If q is not empty, it means DFS has already
            // found and processed the first island.
            //
            // We MUST stop here because we don't want
            // to process the second island.
            if(!q.empty())
            {
                break;
            }
        }


        // ------------------------------------------------
        // STEP 2: MULTI-SOURCE BFS
        // ------------------------------------------------

        int steps = 0;

        // Four possible directions
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};


        // BFS starts with ALL cells of the first island.
        while(!q.empty())
        {
            // Number of nodes currently present in this
            // BFS level.
            //
            // All these cells have the same distance
            // from the first island.
            int size = q.size();


            while(size--)
            {
                auto front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;


                // Explore all 4 neighbours
                for(int k = 0; k < 4; k++)
                {
                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];


                    // First check whether the cell is valid.
                    //
                    // IMPORTANT:
                    // We do this BEFORE accessing
                    // grid[newRow][newCol].
                    //
                    // Otherwise newRow/newCol could be
                    // outside the grid.
                    if(!isValid(newRow, newCol,n, m, grid, visited))
                    {
                        continue;
                    }


                    // If we reach a cell containing 1,
                    // we have reached the SECOND island.
                    //
                    // Therefore, the number of water cells
                    // crossed so far is the answer.
                    if(grid[newRow][newCol] == 1)
                    {
                        return steps;
                    }


                    // Otherwise this cell is water (0).
                    //
                    // Mark it visited so that we don't
                    // add the same water cell multiple times.
                    visited[newRow][newCol] = true;

                    // Add this water cell to the next
                    // BFS level.
                    q.push({newRow, newCol});
                }
            }


            // We have finished processing one complete
            // BFS level.
            //
            // Moving to the next level means crossing
            // one more layer of water.
            steps++;
        }


        // Normally we will always reach the second island.
        return -1;
    }
};

/*

              GRID
                │
                ▼
         Find first 1
                │
                ▼
          DFS first island
                │
                ├── mark visited
                └── push cells into queue
                         │
                         ▼
                  Multi-source BFS
                         │
                  expand through 0s
                         │
                         ▼
              Reach second island?
                    /       \
                  YES        NO
                   │          │
                   ▼          ▼
               return      continue
                steps

╔══════════════════════════════════════════════╗
║              SHORTEST BRIDGE                 ║
╠══════════════════════════════════════════════╣
║ 🎯 Pattern: DFS + Multi-Source BFS           ║
║                                              ║
║ 1. Find the first `1`                        ║
║ 2. DFS → mark complete first island          ║
║ 3. Push all first-island cells into queue    ║
║ 4. BFS → expand through `0`s                 ║
║ 5. If next cell is `1` → return `steps`      ║
║                                              ║
║ 💡 Key Idea:                                 ║
║ DFS identifies Island-1.                     ║
║ BFS finds minimum water cells to cross.      ║
║                                              ║
║ 🔑 Why Multi-Source BFS?                     ║
║ Every cell of Island-1 can be a starting     ║
║ point, so put all of them in the queue.      ║
║                                              ║
║ ⏱ TC: O(n × m)                              ║
║ 💾 SC: O(n × m)                             ║
╚══════════════════════════════════════════════╝

*/

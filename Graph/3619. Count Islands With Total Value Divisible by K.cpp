************************************************APPROACH 1st(DFS)******************************************************

class Solution {// TC ---> O(N * M)                               SC ---> O(N * M)
public:
    // DFS visits every cell belonging to the current island
    // and calculates the total sum of that island.
    // sum is passed by reference so all recursive calls
    // update the same sum variable.
    void dfs(int row, int col, int n, int m, vector<vector<int>>& grid, long long &sum) 
    {
        // Base case:
        // Stop if the cell is outside the grid
        // or the cell is water (0) or already visited.
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0) 
        {
            return;
        }

        // Add the current cell's value to the island sum.
        sum += grid[row][col];

        // Mark this cell as visited so we don't count it again.
        // We use 0 to mark it because 0 represents water.
        grid[row][col] = 0;

        // These arrays represent the four possible directions:
        // Up, Right, Down, Left.
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Explore all four neighboring cells.
        for (int i = 0; i < 4; i++) 
        {
            // Calculate the coordinates of the neighboring cell.
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            // Recursively visit the neighboring cell.
            // All calls update the same sum because it is a reference.
            dfs(newRow, newCol, n, m, grid, sum);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        // Get the number of rows and columns.
        int n = grid.size();
        int m = grid[0].size();

        // Stores the number of islands whose sum is divisible by k.
        int ans = 0;

        // Visit every cell in the grid.
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // A non-zero cell that hasn't been visited
                // means we have found a new island.
                if (grid[i][j] != 0) 
                {
                    // Start calculating the sum of this island.
                    // long long prevents overflow for large sums.
                    long long sum = 0;

                    // Explore the entire connected island.
                    dfs(i, j, n, m, grid, sum);

                    // After DFS finishes, sum contains the
                    // total value of all cells in this island.
                    // Count the island only if its sum is divisible by k.
                    if (sum % k == 0) 
                    {
                        ans++;
                    }
                }
            }
        }

        // Return the total number of qualifying islands.
        return ans;
    }
};

/*

┌──────────────────────────────────────────┐
│ Count Islands Divisible by K             │
├──────────────────────────────────────────┤
│ Approach: DFS (Depth-First Search)       │
│                                          │
│ 1. Traverse every cell in the grid.      │
│ 2. If a cell is non-zero, a new island   │
│    has been found.                       │
│ 3. Use DFS to visit all connected        │
│    non-zero cells of that island.        │
│ 4. Add each visited cell's value to      │
│    sum using long long &sum.             │
│ 5. Mark visited cells as 0 to avoid      │
│    counting the same island again.       │
│ 6. After DFS finishes, check sum % k.    │
│ 7. If sum % k == 0, increment ans.       │
├──────────────────────────────────────────┤
│ Key Trick:                               │
│ Pass sum by reference so all recursive   │
│ calls update the same island sum.        │
│                                          │
│ Time Complexity:       O(n × m)          │
│ Auxiliary Space:       O(n × m)          │
│ Extra Space:           O(1)              │
└──────────────────────────────────────────┘

*/

************************************************APPROACH 2nd(BFS)*****************************************************


class Solution {
public:
    void bfs(int row, int col, int n, int m, vector<vector<int>>& grid, long long& sum) {

        // Store cells waiting to be visited.
        queue<pair<int, int>> q;

        // Add the starting cell to the queue.
        q.push({row, col});

        // Mark it visited when adding it to the queue.
        sum += grid[row][col];
        grid[row][col] = 0;

        // Up, right, down, left.
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Process cells until the queue becomes empty.
        while (!q.empty()) 
        {
            auto [currRow, currCol] = q.front();
            q.pop();

            // Explore all four neighboring cells.
            for (int i = 0; i < 4; i++) {
                int newRow = currRow + delRow[i];
                int newCol = currCol + delCol[i];

                // Check boundaries and ensure the cell is unvisited land.
                if (newRow >= 0 && newCol >= 0 &&
                    newRow < n && newCol < m &&
                    grid[newRow][newCol] != 0) 
                {

                    // Include this cell in the island sum.
                    sum += grid[newRow][newCol];

                    // Mark visited before adding to the queue.
                    grid[newRow][newCol] = 0;

                    q.push({newRow, newCol});
                }
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // A non-zero cell starts a new island.
                if (grid[i][j] != 0) 
                {
                    long long sum = 0;

                    // Visit the complete island and calculate its sum.
                    bfs(i, j, n, m, grid, sum);

                    // Count only islands whose sum is divisible by k.
                    if (sum % k == 0) 
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};

/*

┌──────────────────────────────────────────┐
│ Count Islands Divisible by K — BFS       │
├──────────────────────────────────────────┤
│ Approach: Breadth-First Search           │
│                                          │
│ 1. Traverse every cell in the grid.      │
│ 2. If grid[i][j] != 0, start a new BFS.  │
│ 3. Push the cell into a queue and mark   │
│    it visited by setting it to 0.        │
│ 4. Explore all 4 directions:             │
│    Up, Right, Down, Left.                │
│ 5. Add each connected cell's value to    │
│    the island sum.                       │
│ 6. After BFS, check sum % k == 0.        │
│ 7. If true, increment ans.               │
├──────────────────────────────────────────┤
│ Key Trick:                               │
│ Use a queue to explore connected cells   │
│ and mark them visited when enqueued.     │
│ Use long long for the island sum.        │
├──────────────────────────────────────────┤
│ Time Complexity:       O(n × m)          │
│ Auxiliary Space:       O(n × m)          │
│ Extra Space:           O(1)              │
└──────────────────────────────────────────┘

*/

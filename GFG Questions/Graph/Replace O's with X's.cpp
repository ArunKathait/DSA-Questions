*************************************************APPROACH 1st(WITH VISITED VECTOR)**************************************

class Solution {// TC ---> O(N*M)                               SC ---> O(N*M)
public:

    // Depth First Search (DFS) to mark all 'O's connected to the boundary
    void dfs(int row, int col, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        // Base conditions: stop DFS if out of bounds, 
        // cell is 'X', or already visited
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 'X' || visited[row][col]) 
        {
            return;
        }

        // Mark current cell as visited (safe 'O' connected to boundary)
        visited[row][col] = true;

        // Move in 4 directions — up, right, down, left
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Explore all 4 directions recursively
        for (int k = 0; k < 4; k++) 
        {
            dfs(row + delRow[k], col + delCol[k], n, m, grid, visited);
        }
    }

    void fill(vector<vector<char>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        // Visited matrix to keep track of 'O's connected to boundary
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Step 1: Call DFS for all boundary 'O's
        // These 'O's and any 'O' connected to them cannot be converted to 'X'
        
        // Left and Right boundaries
        for (int i = 0; i < n; i++) 
        {
            dfs(i, 0, n, m, grid, visited);      // First column
            dfs(i, m - 1, n, m, grid, visited);  // Last column
        }

        // Top and Bottom boundaries
        for (int j = 0; j < m; j++) 
        {
            dfs(0, j, n, m, grid, visited);      // First row
            dfs(n - 1, j, n, m, grid, visited);  // Last row
        }

        // Step 2: Convert all unvisited 'O's (i.e., enclosed regions) to 'X'
        // Because these 'O's are not connected to any boundary
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // If 'O' is not visited (not connected to boundary)
                if (grid[i][j] == 'O' && !visited[i][j]) 
                {
                    grid[i][j] = 'X';  // Flip to 'X'
                }
            }
        }
    }
};

************************************************APPROACH 2nd(WITHOUT VISITED VECTOR)*********************************

class Solution {// TC ---> O(N*M)                      SC ---> O(1)
public:
    // DFS function to mark connected 'O's as safe ('T')
    void dfs(int row, int col, int n, int m, vector<vector<char>>& grid) {
        // Base case: if out of bounds or not an 'O', stop
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] != 'O')
        {
            return;
        }

        grid[row][col] = 'T';  // Temporarily mark this cell as safe (connected to border)

        // Move in all 4 directions (up, right, down, left)
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Explore all adjacent cells that are 'O'
        for (int k = 0; k < 4; k++) 
        {
            dfs(row + delRow[k], col + delCol[k], n, m, grid);
        }
    }

    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1️⃣: Mark all 'O's connected to boundary as 'T' (safe)
        // Because boundary 'O's and their connected regions cannot be flipped.
        for (int i = 0; i < n; i++) 
        {
            // Left boundary
            if (grid[i][0] == 'O') 
            {
                dfs(i, 0, n, m, grid);
            }
            
            // Right boundary
            if (grid[i][m-1] == 'O')
            {
                dfs(i, m-1, n, m, grid);
            }
        }
        
        for (int j = 0; j < m; j++) 
        {
            // Top boundary
            if (grid[0][j] == 'O') 
            {
                dfs(0, j, n, m, grid);
            }
            
            // Bottom boundary
            if (grid[n-1][j] == 'O') 
            {
                dfs(n-1, j, n, m, grid);
            }
        }

        // Step 2️⃣: Flip remaining cells
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // These 'O's were not connected to the boundary, so they are enclosed
                if (grid[i][j] == 'O') 
                {
                    grid[i][j] = 'X';
                }
                
                // These 'T's were marked safe earlier, restore them back to 'O'
                if (grid[i][j] == 'T')
                {
                    grid[i][j] = 'O';
                }
            }
        }
    }
};

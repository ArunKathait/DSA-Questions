***************************************************APPROACH 1st(BRUTE FORCE)****************************************

class Solution {// Time Complexity = O(n⁴)                               Space Complexity = O(n²)
public:
    // DFS function to calculate the area of an island (connected 1s)
    int dfs(int row, int col, int n, vector<vector<int>>& grid, vector<vector<int>>& visited) 
    {
        // Base case: check if we are out of bounds or at water (0) or already visited
        if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == 0 || visited[row][col] == 1) 
        {
            return 0;
        }

        // Mark current cell as visited
        visited[row][col] = 1;

        // Each land cell contributes area = 1
        int area = 1;

        // Define directions for Up, Right, Down, Left
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Explore all 4 directions
        for (int k = 0; k < 4; k++) 
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Recursively calculate area of connected land
            area += dfs(newRow, newCol, n, grid, visited);
        }
        
        // Return total area for this island
        return area; 
    }

    int largestIsland(vector<vector<int>>& grid) {
        // Size of the NxN grid
        int n = grid.size(); 
        
        // To track the largest possible island area
        int maxArea = 0; 

        // Step 1: Try flipping each 0 → 1 one by one
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                // Only process water cells
                if (grid[i][j] == 0) {

                    // Flip current 0 to 1 (simulate making land)
                    grid[i][j] = 1;

                    // Create a visited matrix to track visited cells for DFS
                    vector<vector<int>> visited(n, vector<int>(n, 0));
                    
                    // To store max island area for this configuration
                    int area = 0; 

                    // Step 2: Find the largest island area after flipping this cell
                    for (int x = 0; x < n; x++) 
                    {
                        for (int y = 0; y < n; y++) 
                        {
                            // Perform DFS on unvisited land cells
                            if (grid[x][y] == 1 && !visited[x][y]) 
                            {
                                area = max(area, dfs(x, y, n, grid, visited));
                            }
                        }
                    }

                    // Revert the change (backtrack)
                    grid[i][j] = 0;

                    // Step 3: Update the global maximum area
                    maxArea = max(maxArea, area);
                }
            }
        }

        // Step 4: Handle edge case — if there are no 0s, the whole grid is land
        return (maxArea == 0) ? n * n : maxArea;
    }
};

*************************************************APPROACH 2nd(BETTER)************************************************

class Solution { // ✅ Time Complexity = O(n⁴), Space Complexity = O(n²)
public:
    // ----------------------------
    // Helper DFS function
    // ----------------------------
    // This function recursively explores all connected '1's (land cells)
    // starting from (row, col) and returns the total area of that island.
    int dfs(int row, int col, int n, vector<vector<int>>& grid, vector<vector<int>>& visited) 
    {
        // ✅ Base conditions:
        // Stop if we go out of grid boundaries OR
        // encounter a water cell (0) OR already visited cell.
        if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == 0 || visited[row][col] == 1) 
        {
            return 0;
        }

        // ✅ Mark this cell as visited to avoid revisiting
        visited[row][col] = 1;

        // ✅ Each land cell contributes an area of 1
        int area = 1;

        // ✅ Direction vectors for 4-directional movement: Up, Right, Down, Left
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // ✅ Explore all 4 adjacent cells
        for (int k = 0; k < 4; k++) 
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Recursively add area of connected land cells
            area += dfs(newRow, newCol, n, grid, visited);
        }
        
        // ✅ Return total area of this island
        return area; 
    }

    // ----------------------------
    // Main function
    // ----------------------------
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(); // ✅ Get the size of the grid (n x n)
        
        int maxArea = 0;     // ✅ To store the maximum island area found so far

        // ✅ Visited matrix to track visited land cells during DFS
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // ✅ Step 1: Calculate the area of existing islands (without any flip)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the current cell is land (1) and not visited, perform DFS
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    // Compute island area and update maximum
                    maxArea = max(maxArea, dfs(i, j, n, grid, visited));
                }
            }
        }

        // ✅ Step 2: Try flipping each '0' → '1' one by one
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                // Only process water cells
                if (grid[i][j] == 0) 
                {
                    // Temporarily flip current cell to land (simulate making it '1')
                    grid[i][j] = 1;

                    // Re-initialize visited matrix for fresh DFS
                    visited = vector<vector<int>>(n, vector<int>(n, 0));
                    
                    // ✅ Perform DFS from this flipped cell to find the island area
                    int size = dfs(i, j, n, grid, visited);

                    // ✅ Revert the change (backtrack to original grid)
                    grid[i][j] = 0;

                    // ✅ Update the global maximum area
                    maxArea = max(maxArea, size);
                }
            }
        }

        // ✅ Step 3: Handle special case
        // If there were no zeros in the grid, the entire grid is one big island.
        // So the area = n * n
        return (maxArea == 0) ? n * n : maxArea;
    }
};

*************************************************APPROACH 3rd(OPTIMAL)***********************************************

class Solution {// TC ---> O(N^2)  + O(N^2) ~ O(N^2)                                    SC ---> O(N^2)
public:
    // DFS function to mark connected land cells with a unique island ID
    int dfs(int row, int col, int n, vector<vector<int>>& grid, int uniqueId)
    {
        // Base case: if out of bounds or cell is not land (1), stop recursion
        if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != 1)
        {
            return 0;
        }

        // Mark this land cell with the current island's unique ID
        grid[row][col] = uniqueId;

        // Start counting the size of this island
        int size = 1;

        // Directions: up, right, down, left
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Explore all 4 possible directions recursively
        for (int k = 0; k < 4; k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Add the size of connected land cells
            size += dfs(newRow, newCol, n, grid, uniqueId);
        }

        // Return total size of this island
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        // Grid dimension (n x n)
        int n = grid.size();  

        // To store the largest island size found 
        int maxArea = 0; 

        // Start island IDs from 2 (since grid already has 0 and 1)      
        int uniqueId = 2; 

        // Maps unique island ID → island size     
        unordered_map<int, int> ump;  

        // Step 1: Identify all islands and label them uniquely
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Found an unvisited island cell
                if (grid[i][j] == 1)  
                {
                    // DFS marks the island and returns its size
                    int size = dfs(i, j, n, grid, uniqueId);

                    // Update max area if this island is the largest so far
                    maxArea = max(maxArea, size);

                    // Store the size of this island using its unique ID
                    ump[uniqueId] = size;

                    // Move to next unique ID for the next island
                    uniqueId++;
                }
            }
        }

        // Step 2: Try flipping each water cell (0) to land (1)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    // Set to store unique neighboring island IDs (avoid double counting)
                    unordered_set<int> uniqueIds;

                    // 4 directions: up, right, down, left
                    vector<int> delRow = {-1, 0, 1, 0};
                    vector<int> delCol = {0, 1, 0, -1};

                    // Check all 4 neighbors
                    for (int k = 0; k < 4; k++)
                    {
                        int newRow = i + delRow[k];
                        int newCol = j + delCol[k];

                        // If within bounds and not water
                        if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && grid[newRow][newCol] != 0)
                        {
                            // Add this island's ID
                            uniqueIds.insert(grid[newRow][newCol]);
                        }
                    }

                    // Step 3: Calculate combined size if this 0 were changed to 1
                    int overAllSize = 1;  // include the flipped cell itself

                    // Add sizes of all distinct neighboring islands
                    for (auto &id : uniqueIds)
                    {
                        overAllSize += ump[id];
                    }

                    // Update max area with the new potential island size
                    maxArea = max(maxArea, overAllSize);
                }
            }
        }

        // Return the largest island size possible (after at most one flip)
        return maxArea;
    }
};

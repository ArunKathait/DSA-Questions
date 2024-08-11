
class Solution {// TC--->O((N*M)^2)                        SC--->O(N*M)
public:
    
    // Helper function to perform Depth-First Search (DFS) to explore an island.
    // It marks all the connected land (1's) from the given starting point (row, col) as visited.
    void dfs(vector<vector<int>>&grid,int row,int col,vector<vector<bool>>&visited)
    {
        // Base conditions: check if the current position is out of bounds, if it's water (0),
        // or if it's already visited. If any of these is true, return from the function.
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col])
        {
            return;
        }
        
        // Mark the current cell as visited
        visited[row][col] = true;
        
         // Arrays to help explore the four possible directions (up, right, down, left)
        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};
        
        // Explore all four directions from the current cell
        for(int k=0;k<4;k++)
        {
            // Calculate new row index
            int newRow = row + delRow[k];
            
            // Calculate new column index
            int newCol = col + delCol[k];
            
            // Recursively perform DFS on the adjacent cell
            dfs(grid,newRow,newCol,visited);
        }
        
        
    }
    
    // Function to count the number of islands in the grid.
    // An island is defined as a group of connected 1's (land) surrounded by water (0's).
    int numberOfIslands(vector<vector<int>>&grid,int n,int m)
    {
        // Initialize a 2D vector to track visited cells, initially all false (unvisited)
        vector<vector<bool>>visited(n,vector<bool>(m));
        
        // Initialize a counter for islands
        int islands = 0;
        
        // Traverse the entire grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // If the current cell is land (1) and hasn't been visited yet, it's a new island
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    // Perform DFS to mark the entire island as visited
                    dfs(grid,i,j,visited);
                    
                    // Increment the island counter
                    islands++;
                }
            }
        }
        // Return the total number of islands found
        return islands;
    }
    
    // Function to determine the minimum number of days to disconnect the grid (i.e., split into multiple islands)
    int minDays(vector<vector<int>>& grid) {
        // Number of rows in the grid
        int n = grid.size();
        
        // Number of columns in the grid
        int m = grid[0].size();
        
        // First, count the number of islands initially present in the grid
        int islands = numberOfIslands(grid,n,m);
        
        // If there are already 0 or more than 1 islands, the grid is already disconnected, so return 0 days
        if(islands == 0 || islands > 1)
        {
            return 0;
        }
        else
        {
            // Traverse the entire grid to check each land cell (1)
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    // If the cell is land (1)
                    if(grid[i][j] == 1)
                    {
                        // Temporarily change the land to water (0)
                        grid[i][j] = 0;
                        
                        // Recalculate the number of islands after changing the current cell
                        islands = numberOfIslands(grid,n,m);
                        
                        // Revert the cell back to land (1)
                        grid[i][j] = 1;
                        
                        // If changing this cell results in more than 1 island or no islands, return 1 day
                        if(islands > 1 || islands == 0)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
        
        // If no single cell change can split the grid, it takes 2 days to disconnect the grid
        return 2;
        
    }
};

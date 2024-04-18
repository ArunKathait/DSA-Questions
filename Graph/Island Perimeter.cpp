*****************************************APPROACH 1st(EFFICIENT APPROACH)***********************************************

class Solution {// TC--->O(n*m)           SC--->O(1)
public:
    // Function to calculate the perimeter of the island
    int islandPerimeter(vector<vector<int>>& grid) {
        
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize perimeter counter
        int perimeter = 0;
        
        // Iterate through each cell of the grid
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                
                // Check if the current cell is part of the island (value = 1)
                if(grid[row][col] == 1)
                {
                    // Increment the perimeter by 4 for each land cell
                    perimeter += 4;
                    
                    // Check if there's a land cell above of the current cell
                    if(row > 0 && grid[row-1][col] == 1)
                    {
                        // If there's a land cell above, decrement the perimeter by 2
                        perimeter -= 2;
                    }
                    
                    // Check if there's a land cell to the left of the current cell
                    if(col > 0 && grid[row][col-1] == 1)
                    {
                        // If there's a land cell to the left, decrement the perimeter by 2
                        perimeter -= 2;
                    }
                }
            }
        }
        
        // Return the total perimeter of the island
        return perimeter;
    }
};
*****************************************APPROACH 1st(USING DFS)****************************************************

class Solution {// TC--->O(m*n)           SC--->O(m*n)
public:
    // Function to perform Depth-First Search (DFS) to calculate perimeter
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m,int &perimeter)
    {
        // Base case: if the current cell is out of bounds or water (0), increment perimeter and return
        if(i<0 || i>n-1 || j<0 || j>m-1 || grid[i][j] == 0)
        {
            perimeter++;
            return ;
        }
        
        // If the current cell is already visited (-1), return without further exploration
        if(grid[i][j] == -1)
        {
            return ;
        }
        
        // Mark the current cell as visited (-1)
        grid[i][j] = -1;
        
        // Explore adjacent cells recursively
        dfs(grid,i+1,j,n,m,perimeter);// down
        dfs(grid,i-1,j,n,m,perimeter);// up
        dfs(grid,i,j+1,n,m,perimeter);// right
        dfs(grid,i,j-1,n,m,perimeter);// left
    }
    
     // Function to find the first island and initiate DFS traversal
    int islandPerimeter(vector<vector<int>>& grid) {
        
        // Initialize perimeter counter
        int perimeter = 0;
        
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();
        
        // Iterate through the grid to find the first cell of the island
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    // If an island cell is found, initiate DFS traversal from that cell
                    dfs(grid,i,j,n,m,perimeter);
                    return perimeter;
                }
            }
        }
        
        // Return -1 if no island is found (this shouldn't happen if the grid is properly formatted)
        return -1;
    }
};
************************************************APPROACH 2nd(USING BFS)***********************************************
class Solution {// TC--->O(m*n)              SC--->O(m*n)
public:
    
    // Function to perform Breadth-First Search (BFS) to calculate perimeter
    int bfs(vector<vector<int>>&grid,int i,int j,int n,int m)
    {
        // Initialize perimeter counter
        int perimeter = 0;
        
        // Initialize a queue for BFS traversal
        queue<pair<int,int>>q;
        
        // Add the starting cell to the queue and mark it as visited (-1)
        q.push({i,j});
        grid[i][j] = -1;
        
        // Perform BFS traversal
        while(!q.empty())
        {
            // Get the front element of the queue
            auto front = q.front();
            q.pop();
            
            // Extract row and column indices of the current cell
            int row = front.first;
            int col = front.second;
            
            // Arrays to represent possible movements: down, right, up, left
            int delRow[4] = {1,0,-1,0};
            int delCol[4] = {0,1,0,-1};
            
            // Explore each direction
            for(int i=0;i<4;i++)
            {
                // Calculate new row index
                int newRow = row + delRow[i];
                
                // Calculate new column index
                int newCol = col + delCol[i];
                
                 // Check if the new cell is out of bounds or water (0)
                if(newRow < 0 || newRow > n-1 || newCol < 0 || newCol > m-1 ||grid[newRow][newCol] == 0)
                {
                    // Increment perimeter if out of bounds or adjacent cell is water
                    perimeter++;
                }
                
                // Check if the new cell is already visited (-1)
                else if(grid[newRow][newCol] == -1)
                {
                    // Continue to the next iteration if the cell is already visited
                    continue;
                }
                
                // Otherwise, the cell is part of the island
                else
                { 
                    // Add the cell to the queue for further exploration and mark it as visited (-1)
                    q.push({newRow,newCol});
                    grid[newRow][newCol] = -1;
                }
            }
        }
        
        // Return the total perimeter of the island
        return perimeter;
    }
    
    // Function to find the first island and initiate BFS traversal
    int islandPerimeter(vector<vector<int>>& grid) {
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();
        
        
        // Iterate through the grid to find the first cell of the island
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    
                    // If an island cell is found, initiate BFS traversal from that cell
                    return bfs(grid,i,j,n,m);
                }
            }
        }
        
        // Return -1 if no island is found (this shouldn't happen if the grid is properly formatted)
        return -1;
    }
};

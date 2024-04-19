*********************************************APPROACH 1st(USING DFS)*****************************************

class Solution {// TC--->O(n*m)            SC--->O(n*m)
public:
    // Depth-first search function to explore the island
    void dfs(vector<vector<char>>&grid,int row,int col,int n,int m)
    {
        // Base case: if the current cell is out of bounds or not part of the island ('1')
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col] != '1' )
        {
            // Exit the function
            return ;
        }
        
        // Mark the current cell as visited (set it to '0')
        grid[row][col] = '0';
        
        // Array to represent the four possible directions: down, right, up, left
        int delRow[4] = {1,0,-1,0};
        int delCol[4] = {0,1,0,-1};
        
        // Explore all four directions from the current cell
        for(int k=0;k<4;k++)
        {
            // Calculate the new row
            int newRow = row + delRow[k];
            
            // Calculate the new column
            int newCol = col + delCol[k];
            
            // Recursively call dfs for the new cell
            dfs(grid,newRow,newCol,n,m);
        }
    }
    
    // Function to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        
        // Variable to store the number of islands
        int island = 0;
        
        // Number of rows in the grid
        int n = grid.size();
        
        // Number of columns in the grid
        int m = grid[0].size();
        
        // Loop through each cell in the grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // If the current cell is part of an unvisited island
                if(grid[i][j] == '1')
                {
                    // Increment the island count
                    island++;
                    
                    // Explore the island using dfs
                    dfs(grid,i,j,n,m);
                }
            }
        }
        
        // Return the total number of islands
        return island;
    }
};

/* 
NOTE:
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col] != '1' )
        {
            
            return ;
        }

This is base condition means if we reach any invalid index and invalid cell then we simply return our dfs function(i.e exit).

Otherwise we just visit that cell in the matrix.

*/



**********************************************APPROACH 2ND (USING BFS)*****************************************

  class Solution {// TC--->O(n*m)            SC--->O(n*m)
public:
    
    // BFS function to explore the island starting from a given cell (row, col)
    void bfs(vector<vector<char>>&grid,int row,int col,int n,int m)
    {
        // Create a queue to store pairs of (row, col) representing cells to be visited
        queue<pair<int,int>>q;
        
         // Push the starting cell (row, col) into the queue
        q.push({row,col});
        
        // Mark the starting cell as visited by changing its value to '0'
        grid[row][col] = '0';
        
        // Continue the BFS until the queue is empty
        while(!q.empty())
        {
            // Get the front element of the queue
            auto front = q.front();
            q.pop();
            
            // Extract row and column indices of the current cell
            int r = front.first;
            int c = front.second;
            
            // Array to represent the four possible directions: down, right, up, left
            int delRow[4] = {1,0,-1,0};
            int delCol[4] = {0,1,0,-1};
            
            // Explore each neighbor of the current cell
            for(int k=0;k<4;k++)
            {
                // Calculate the new row and column indices for the neighbor
                int newRow = r + delRow[k];
                int newCol = c + delCol[k];
                
                // If the neighboring cell is out of bounds or not part of an unvisited island:
                if(newRow<0 || newRow>=n || newCol<0 || newCol>=m || grid[newRow][newCol] != '1')
                {
                    // If any of these conditions are true, the neighboring cell cannot be explored further.
                    continue;
                }
                // If the neighboring cell is within bounds and part of an unvisited island:
                else
                {
                    // Push the neighbor into the queue to explore its neighbors in the next iteration
                    q.push({newRow,newCol});
                    
                    // Mark the neighboring cell as visited by changing its value to '0'.
                    grid[newRow][newCol] = '0';
                }
                
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();
        
        // Variable to store the count of islands
        int island = 0;
        
        // Iterate through each cell in the grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                // If the current cell represents an unvisited island, increment the count and start BFS from this cell
                if(grid[i][j] == '1')
                {
                    island++;
                    bfs(grid,i,j,n,m);
                }
            }
        }
        
        // Return the count of islands
        return island;
    }
};

/*
NOTE:
The below code lines means----->
if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] != '1')
{
    // If the neighboring cell is out of bounds or not part of an unvisited island:
    // - newRow < 0: Check if the new row index is less than 0, indicating it's outside the grid boundaries.
    // - newRow >= n: Check if the new row index is greater than or equal to the number of rows 'n',indicating it's outside the grid boundaries.
    // - newCol < 0: Check if the new column index is less than 0, indicating it's outside the grid boundaries.
    // - newCol >= m: Check if the new column index is greater than or equal to the number of columns 'm', indicating it's outside the grid boundaries.
    // - grid[newRow][newCol] != '1': Check if the neighboring cell is not part of an unvisited island (marked as '1').
    // If any of these conditions are true, the neighboring cell cannot be explored further.
    
    continue;
} 
else
{
     // If the neighboring cell is within bounds and part of an unvisited island:
     // - Push the coordinates of the neighboring cell into the queue for further exploration.
     // - Mark the neighboring cell as visited by changing its value to '0' in the grid.
    
    q.push({newRow, newCol}); // Enqueue the coordinates of the neighboring cell.
    grid[newRow][newCol] = '0'; // Mark the neighboring cell as visited.
}

*/


class Solution {// TC--->O(rows*cols)                     SC--->O(rows*cols)
public:
    // This helper function uses DFS to explore all connected regions of 0s.
    void numberOfIslandsDfs(vector<vector<int>>&matrix,int row,int col)
    {
        // Base case: if the cell is out of bounds or already marked (1), return.
        if(row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] == 1)
        {
            return ;
        }
        
        // Mark the current cell as visited by setting it to 1.
        matrix[row][col] = 1;
        
        // Define the possible directions to move: up, right, down, and left.
        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};
        
        // Explore all 4 possible directions.
        for(int k=0;k<4;k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];
            
            // Recursively call DFS for the next cell in the grid.
            numberOfIslandsDfs(matrix,newRow,newCol);
        }
    }
    
    // This function calculates the number of distinct regions separated by slashes.
    int regionsBySlashes(vector<string>& grid) {
        // Number of rows in the grid
        int rows = grid.size();
        
        // Number of columns in the grid
        int cols = grid[0].size();
        
        // Create a new matrix with 3 times the size of the original grid to represent finer details.
        vector<vector<int>>matrix(3*rows,vector<int>(3*cols,0));
        
        // Populate the matrix based on the slashes in the input grid.
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                // If there's a '/', mark the corresponding cells in the matrix.
                if(grid[i][j] == '/')
                {
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                // If there's a '\', mark the corresponding cells in the matrix.
                else if(grid[i][j] == '\\')
                {
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }
        
        // Initialize the counter for the number of regions.
        int regions = 0;
        
        // Traverse the entire matrix to find unvisited regions
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                // If the cell is unvisited (0), it's part of a new region.
                if(matrix[i][j] == 0)
                {
                    // Use DFS to mark the entire region.
                    numberOfIslandsDfs(matrix,i,j);
                    
                    // Increment the region counter.
                    regions++;
                }
            }
        }
        
        // Return the total number of regions found.
        return regions;
    }
};

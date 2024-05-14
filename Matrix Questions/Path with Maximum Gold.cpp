class Solution {// TC--->O(m*n * 4^(cells with gold))           SC--->O(cells with gold) 
public:
     // Arrays to represent the four possible directions: up, right, down, left
     vector<int>delRow = {-1,0,1,0};// Changes in row
     vector<int>delCol = {0,1,0,-1};// Changes in column
    
    // This function performs Depth First Search (DFS) to explore the grid and find the maximum amount of gold
    int dfs(vector<vector<int>>&grid,int row,int col,int n,int m)
    {
        // Base case: If the current cell is out of bounds or has no gold, return 0
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col] == 0)
        {
            return 0;
        }
        
        // Store the original gold value of the current cell and mark it as visited (set to 0)
        int originalGoldValue = grid[row][col];
        grid[row][col] = 0;
        
        // Initialize the maximum gold that can be obtained from the current cell to 0
        int maxGold = 0;
        
        // Explore each neighbor of the current cell
        for(int k=0;k<4;k++)
        {
            int newRow = delRow[k] + row;
            int newCol = delCol[k] + col;
            
            // Recursively call DFS on each valid neighbor and update maxGold with the maximum value obtained
            maxGold = max(maxGold,dfs(grid,newRow,newCol,n,m));
        }
        
        // Restore the original gold value of the current cell
        grid[row][col] = originalGoldValue;
        
        // Return the sum of the original gold value of the current cell and the maximum gold obtainable from its neighbors
        return originalGoldValue + maxGold;
    }
    
    // This function calculates the maximum amount of gold that can be obtained from the grid
    int getMaximumGold(vector<vector<int>>& grid) {
        
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize a variable to store the maximum amount of gold found
        int ans = 0;
        
        // Iterate through each cell in the grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // If the current cell contains gold, find the maximum amount of gold obtainable                         // starting from this cell
                if(grid[i][j] != 0)
                {
                    ans = max(ans,dfs(grid,i,j,n,m));
                }
            }
        }
        
        // Return the maximum amount of gold that can be obtained from the grid
        return ans;
    }
};

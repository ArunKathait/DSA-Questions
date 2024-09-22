**********************************************APPROACH 1st(DFS)**********************************************************
  

class Solution {// TC--->O(N*M)                                  SC--->O(N*M)
  public:
  // This function performs Depth-First Search (DFS) to explore an island and store its relative coordinates
  // 'row' and 'col' are the current cell coordinates being explored
  // 'grid' is the 2D matrix representing the land (1) and water (0)
  // 'visited' keeps track of which cells have been visited
  // 'vec' stores the relative coordinates of the current island
  // 'n' and 'm' are the dimensions of the grid
  // 'row0' and 'col0' store the starting point of the island to calculate relative positions
  void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited,
  vector<pair<int,int>>&vec,int n,int m,int row0,int col0)
  {
      // Base case: If out of bounds, already visited, or water (grid[row][col] == 0), stop DFS
      if(row < 0 || row >= n || col < 0 || col >= m || visited[row][col]
      || grid[row][col] == 0)
      {
          return ;
      }
      
      // Mark the current cell as visited
      visited[row][col] = 1;
      
      // Store the relative position of this cell with respect to the starting point of the island
      vec.push_back({row0 - row , col0 - col});
      
      // Arrays to help explore the 4 directions: up, right, down, left
      int delRow[4] = {-1,0,1,0};
      int delCol[4] = {0,1,0,-1};
      
      // Explore all 4 neighboring cells (up, right, down, left)
      for(int k=0;k<4;k++)
      {
          int newRow = row + delRow[k];
          int newCol = col + delCol[k];
          
          // Recursively perform DFS for the neighboring cell
          dfs(newRow,newCol,grid,visited,vec,n,m,row0,col0);
      }
  }
  
    // Function to count the number of distinct islands
    int countDistinctIslands(vector<vector<int>>& grid) {
        // Number of rows
        int n = grid.size();
        
        // Number of columns
        int m = grid[0].size();
        
        // 2D vector to keep track of visited cells (initially all unvisited)
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        // Set to store unique island shapes based on their relative positions
        set<vector<pair<int,int>>>distinctIslands;
        
        // Iterate through the entire grid to find islands
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 // Vector to store the relative shape of the current island
                vector<pair<int,int>>vec;
                
                // If the cell is land (1) and has not been visited, it's the start of a new island
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    // Perform DFS to explore the entire island and store its shape in 'vec'
                    dfs(i,j,grid,visited,vec,n,m,i,j);
                    
                    // Insert the relative shape of this island into the set
                    // The set ensures that only distinct island shapes are stored
                    distinctIslands.insert(vec);
                }
            }
        }
        
        // The number of distinct island shapes is the size of the set
        return distinctIslands.size();
    }
};


***************************************************APPROACH 2nd(BFS)***************************************************

class Solution {
public:
    // Helper function to perform BFS and collect the shape of an island
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, 
             vector<pair<int, int>>& shape, int row0, int col0, int n, int m) {
        // Queue for BFS, which stores the cells of the current island
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        // Array to move in the 4 possible directions: up, right, down, left
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        // Start the BFS loop
        while (!q.empty()) 
        {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            // Store the relative position of the current cell
            shape.push_back({row0 - currRow, col0 - currCol});

            // Explore the 4 neighboring cells
            for (int k = 0; k < 4; k++) {
                int newRow = currRow + delRow[k];
                int newCol = currCol + delCol[k];

                // Check if the new cell is within bounds, is land (1), and has not been visited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                    !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                    visited[newRow][newCol] = 1; // Mark the new cell as visited
                    q.push({newRow, newCol});    // Add the new cell to the BFS queue
                }
            }
        }
    }

    // Main function to count distinct islands
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));  // Keeps track of visited cells
        set<vector<pair<int, int>>> distinctIslands;  // Stores distinct island shapes

        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {  // If we find unvisited land
                    vector<pair<int, int>> shape;  // To store the shape of the current island
                    bfs(i, j, grid, visited, shape, i, j, n, m);  // Perform BFS to find the entire island
                    distinctIslands.insert(shape);  // Insert the island's shape into the set
                }
            }
        }

        // The number of distinct islands is the size of the set
        return distinctIslands.size();
    }
};

*******************************************APPROACH 1st(USING DFS)*********************************************

class Solution {// TC--->O(m*n)              SC--->O(m*n)
public:
    // DFS function to explore the farmland and update max_i and max_j
    void dfs(vector<vector<int>>&land,int row,int col,int n,int m,int &max_i,int &max_j)
    {
        // Base case: if the current cell is out of bounds or is water, return
        if(row<0 || col<0 || row>=n || col>=m || land[row][col] == 0)
        {
            return ;
        }
        
        // Mark the current cell as visited (by setting it to 0)
        land[row][col] = 0;
        
        // Update max_i and max_j with the current cell's coordinates
        max_i = max(row,max_i);
        max_j = max(col,max_j);
        
        // Array to represent the four possible directions: up, down, left, right
        int delRow[4] = {-1,1,0,0};
        int delCol[4] = {0,0,-1,1};
        
        // Explore each direction
        for(int k=0;k<4;k++)
        {
            // Calculate the new row and column indices for the next cell
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];
            
            // Recursive call to explore the next cell 
            dfs(land,newRow,newCol,n,m,max_i,max_j);
        }
    }
    
    // Main function to find farmland
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        // Get the number of rows and columns in the land grid
        int n = land.size();
        int m = land[0].size();
        
        // Initialize a result vector to store the farmland coordinates and dimensions
        vector<vector<int>>ans;
        
        // Loop through each cell in the land grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // If the cell represents farmland
                if(land[i][j] == 1)
                {
                    // Initialize max_i and max_j with the current cell's coordinates
                    int max_i = i;
                    int max_j = j;
                    
                    // Call the DFS function to explore the farmland and update max_i and max_j
                    dfs(land,i,j,n,m,max_i,max_j);
                    
                    // Push the farmland coordinates and dimensions to the result vector 
                    ans.push_back({i,j,max_i,max_j});
                }
            }
        }
        
         // Return the result vector containing farmland coordinates and dimensions
        return ans;
    }
};

*******************************************APPROACH 2nd(USING DFS)*********************************************

class Solution {
public:
    // DFS function to explore the farmland and update max_i and max_j
    void dfs(vector<vector<int>>&land,int row,int col,int n,int m,int &max_i,int &max_j,vector<vector<int>>&visited)
    {
        
//Base case:if the current cell is out of bounds or is forested land or has already been visited, return
        if(row<0 || col<0 || row>=n || col>=m ||  land[row][col] == 0 || visited[row][col] == 1)
        {
            return ;
        }
        
        // Mark the current cell as visited
        visited[row][col] = 1;
        
        // Update max_i and max_j with the current cell's coordinates
        max_i = max(max_i,row);
        max_j = max(max_j,col);
        
        // Array to represent the four possible directions: up, down, left, right
        int delRow[4] = {-1,1,0,0};
        int delCol[4] = {0,0,-1,1};
        
        // Explore each direction
        for(int k=0;k<4;k++)
        {
            // Calculate the new row and column indices for the next cell
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];
           
            
            // Recursive call to explore the next cell  
            dfs(land,newRow,newCol,n,m,max_i,max_j,visited);
        }
    }
    
    
    // Main function to find farmland
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        // Get the number of rows and columns in the land grid
        int n = land.size();
        int m = land[0].size();
        
        // Initialize a visited array to keep track of visited cells
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        // Initialize a result vector to store the farmland coordinates and dimensions
        vector<vector<int>>res;
        
        // Loop through each cell in the land grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 // If the cell represents farmland and has not been visited yet
                if(land[i][j] == 1 && visited[i][j] == 0)
                {
                    // Initialize a vector to store the current farmland coordinates and dimensions
                    vector<int>ans;
                    
                    // Push the row index
                    ans.push_back(i);
                    
                    // Push the column index
                    ans.push_back(j);
                    
                    // Initialize max_i and max_j with the current cell's coordinates
                    int max_i = i;
                    int max_j = j;
                   
                    // Call the DFS function to explore the farmland and update max_i and max_j
                    dfs(land,i,j,n,m,max_i,max_j,visited);
                    
                    // Push max_i and max_j to the answer vector
                    ans.push_back(max_i);
                    ans.push_back(max_j);
                    
                    // Push the answer vector to the result vector
                    res.push_back(ans);
                }
            }
        }
        
        // Return the result vector containing farmland coordinates and dimensions
        return res;
    }
};
*******************************************APPROACH 3rd(USING BFS)*********************************************

class Solution {// TC--->O(n*m)            SC--->O(n*m)
public:
    // Breadth-first search (BFS) function to explore the farmland and update max_i and max_j
    void bfs(vector<vector<int>>&land,int row,int col,int n,int m,int &max_i,int &max_j)
    {
        // Create a queue to store the coordinates of cells to visit
        queue<pair<int,int>>q;
        
        // Push the starting cell's coordinates into the queue
        q.push({row,col});
        
        // Mark the starting cell as visited (set it to 0)
        land[row][col] = 0;
        
        // Continue until the queue is empty
        while(!q.empty())
        {
            // Get the front cell from the queue
            auto front = q.front();
            q.pop();
            
            // Extract row and column indices of the current cell
            int r = front.first;
            int c = front.second;
            
            // Update max_i and max_j with the current cell's coordinates
            max_i = max(max_i,r);
            max_j = max(max_j,c);
            
            // Array to represent the four possible directions: up, down, left, right
            int delRow[4] = {-1,1,0,0};
            int delCol[4] = {0,0,-1,1};
            
            // Explore each direction
            for(int k=0;k<4;k++)
            {
                // Calculate the new row and column indices for the next cell
                int newRow = r + delRow[k];
                int newCol = c + delCol[k];
                
                // Check if the new indices are out of bounds or the cell is not farmland
                if(newRow<0 || newCol<0 || newRow>=n || newCol>=m || land[newRow][newCol] != 1)
                {
                    // Skip this iteration if conditions are not met
                    continue;
                }
                else 
                {
                    // Push the coordinates of the new farmland cell into the queue
                    q.push({newRow,newCol});
                    
                    // Mark the new farmland cell as visited (set it to 0)
                    land[newRow][newCol] = 0;
                }
            }
        }
        
    }
    
    // Main function to find farmland
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        // Get the number of rows and columns in the land grid
        int n = land.size();
        int m = land[0].size();
        
        // Initialize a vector to store the coordinates and dimensions of farmland
        vector<vector<int>>ans;
        
        // Loop through each cell in the land grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // If the current cell represents farmland (1)
                if(land[i][j] == 1)
                {
                    // Initialize max_i and max_j with the current cell's coordinates
                    int max_i = i;
                    int max_j = j;
                    
                    // Call the BFS function to explore the farmland and update max_i and max_j
                    bfs(land,i,j,n,m,max_i,max_j);
                    
                    // Push the coordinates and dimensions of the farmland into the result vector 
                    ans.push_back({i,j,max_i,max_j});
                }
            }
        }
        
        // Return the result vector containing the coordinates and dimensions of farmland
        return ans;
    }
};
*******************************************APPROACH 4th(USING GREEDY)******************************************

class Solution {// TC--->O(n*m)             SC--->O(1)
public:
    // Function to find farmland in the given 2D grid
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        // Get the number of rows and columns in the land grid
        int n = land.size();
        int m = land[0].size();
        
        // Initialize a vector to store the coordinates and dimensions of farmland
        vector<vector<int>>ans;
        
        // Iterate through each cell in the land grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // If the current cell represents farmland (1)
                if(land[i][j] == 1)
                {
                    // Initialize coordinates for the bottom-right corner of the farmland
                    int r1 = i;
                    int c1 = j;
                    
                    // Find the bottom-right corner of the farmland by incrementing row index
                    while(r1<n && land[r1][j] == 1)
                    {
                        r1++;
                    }
                    
                    // Find the bottom-right corner of the farmland by incrementing column index
                    while(c1<m && land[i][c1] == 1)
                    {
                        c1++;
                    }
                    
                    // Adjust the row and column indices to represent the bottom-right corner
                    r1 = (r1 == 0) ? 0 : r1 - 1;
                    c1 = (c1 == 0) ? 0 : c1 - 1;
                    
                    // Push the coordinates and dimensions of the farmland into the result vector
                    ans.push_back({i,j,r1,c1});
                    
                    // Mark the cells of the current farmland as visited (set them to 0)
                    for(int k=i;k<=r1;k++)
                    {
                        for(int l=j;l<=c1;l++)
                        {
                            land[k][l] = 0;
                        }
                    }
                }
            }
        }
        
        // Return the result vector containing the coordinates and dimensions of farmland
        return ans;
    }
};

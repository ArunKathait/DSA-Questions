
class Solution {// TC--->O(N*M)                         SC--->O(N*M)
public:
    // Function to check if the cell (row, col) is within bounds and has a fresh orange (value 1)
    bool isSafe(int row, int col, int n, int m, vector<vector<int>>& grid) 
    {
        if(row >= 0 && col >= 0 && row < n && col < m && grid[row][col] == 1) 
        {
            return true;
        } 
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // number of rows
        int n = grid.size(); 

        // number of columns       
        int m = grid[0].size();     

        // to count fresh oranges
        int freshOranges = 0;       
        
        // queue to perform BFS on rotten oranges
        queue<pair<int, int>> q;    

        // Step 1: Count fresh oranges and enqueue positions of rotten ones
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) 
            {
                // if the orange is already rotten
                if(grid[i][j] == 2) 
                {           
                    // add it to the queue
                    q.push({i, j});             
                }
                // if the orange is fresh
                else if(grid[i][j] == 1) 
                {      
                    // count it
                    freshOranges++;            
                }
            }
        }

        // If no fresh oranges, no time is needed
        if(freshOranges == 0) 
        {
            return 0;
        }
        
        // to keep track of minutes passed
        int time = 0;   

        // Step 2: BFS to simulate rotting process minute by minute
        while(!q.empty())
         {
            // number of rotten oranges at this level (this minute)
            int size = q.size();  

            // Process all rotten oranges at current time level
            while(size--) 
            {
                int row = q.front().first;
                int col = q.front().second;
                // process current rotten orange
                q.pop();   

                // directions: up, right, down, left
                vector<int> delRow = {-1, 0, 1, 0};
                vector<int> delCol = {0, 1, 0, -1};

                // Try all 4 directions
                for(int k = 0; k < 4; k++) 
                {
                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];

                    // if adjacent cell has a fresh orange
                    if(isSafe(newRow, newCol, n, m, grid)) 
                    {
                        // make it rotten
                        grid[newRow][newCol] = 2;  

                        // add it to queue to rot others       
                        q.push({newRow, newCol}); 

                        // reduce fresh count        
                        freshOranges--;                   
                    }
                }
            }
            // increase time after each level
            time++;    
        }

        // If all oranges are rotten, return time - 1 (because we incremented extra after last level)
        if(freshOranges == 0) 
        {
            return time - 1;
        } 
        else 
        {
            // Some fresh oranges couldn't be rotted
            return -1;    
        }
    }
};

/* 
NOTE:
We subtract 1 from the total time because the time variable is incremented even after the last orange has rotted — giving 
us an extra, unnecessary minute in the count.
*/


class Solution {// TC--->O(log(N) * N^2)                    SC--->O(N^2)
public:

    // Arrays to represent movements in 4 directions: up, right, down, left
    vector<int>delRow = {-1,0,1,0};
    vector<int>delCol = {0,1,0,-1};
    
    // Function to check if a given safeness factor is sufficient
    bool check(int safenessFactor,vector<vector<int>>&distanceNearestThief,int n)
    {
        // Visited array to keep track of visited cells
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        // Queue for BFS traversal
        queue<pair<int,int>>q;
        
        // Pushing the starting cell (0,0) onto the queue and marking it as visited
        q.push({0,0});
        visited[0][0] = true;
        
        // If the nearest thief to the starting cell is closer than the safeness factor, return false
        if(distanceNearestThief[0][0] < safenessFactor)
        {
            return false;
        }
        
        // BFS traversal
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // If reached the destination cell (n-1, n-1), return true
            if(row == n-1 && col == n-1)
            {
                return true;
            }
            
            // Check neighboring cells
            for(int k=0;k<4;k++)
            {
                int newRow = delRow[k] + row;
                int newCol = delCol[k] + col;
                
                // Check if the neighboring cell is within bounds and not visited
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && !visited[newRow][newCol])
                {
                    // If the distance to the nearest thief from the neighboring cell is greater than or equal to the safeness factor, continue BFS
                    if(distanceNearestThief[newRow][newCol] < safenessFactor)
                    {
                        continue;
                    }
                    q.push({newRow,newCol});
                    visited[newRow][newCol] = true;
                }
                
            }
        }
        
         // If BFS completes without reaching the destination, return false
        return false;
    }
    
    // Function to find the maximum safeness factor
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
       // 2D array to store the distance to the nearest thief for each cell
        vector<vector<int>>distanceNearestThief(n,vector<int>(n,-1));
        
        // Queue for BFS traversal
        queue<pair<int,int>>q;
        
         // Visited array to keep track of visited cells
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        // Pushing thief cells onto the queue and marking them as visited
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        
        // Current level of BFS
        int level = 0;
        
        // BFS traversal to compute distance to nearest thief for each cell
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                distanceNearestThief[row][col] = level;
                
                // Check neighboring cells
                for(int k=0;k<4;k++)
                {
                    int newRow = delRow[k] + row;
                    int newCol = delCol[k] + col;
                    
                    // Check if neighboring cell is within bounds and not visited
                    if(newRow<0 || newRow>=n || newCol<0 || newCol>=n || visited[newRow][newCol])
                    {
                        continue;
                    }
                    
                    q.push({newRow,newCol});
                    visited[newRow][newCol] = true;
                }
            }
            
            // Move to the next level of BFS
            level++;
        }
        
        // Binary search to find the maximum safeness factor
        int low = 0;
        int high = INT_MAX;// We can also do high = 400 because in constraints grid.length is given upto 400
        
        int ans = 0;
        while(low <= high)
        {
            int safenessFactor = low + (high - low)/2; 
         
            // If the current safeness factor is sufficient, update answer and search in the higher range    
            if(check(safenessFactor,distanceNearestThief,n))
            {
                ans = safenessFactor;
                low = safenessFactor + 1;
            }
            else
            {
                // If not, search in the lower range
                high = safenessFactor - 1;
            }
        }
        
        // Return the maximum safeness factor
        return ans;
    }
};

/* NOTE:

        There are following steps are required to solve this problem:
        
        (1) Pre-Calculate ManHattan Distance of each cell.
        (2) Apply binary search on each safeness Factor in range---> low = 0 and high = INT_MAX(We can do high = 400 because in constraints grid.lenght is upto 400) 
        (3) Check for each safeness Factor in 0 to INT_MAX
        (4) (0,0) cell to (n-1,n-1) cell --->If there is a path in which all cell have value >= safeness Factor then we take that safeness Factor
        (5) In last we return maximum safeness Factor
            
*/

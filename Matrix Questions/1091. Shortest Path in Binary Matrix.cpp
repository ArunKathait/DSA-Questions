
class Solution {// TC ---> O(n × m)                                   SC ---> O(n × m)
public:

    // Function to check if a cell is valid to visit
    bool isValid(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<bool>>&visited)
    {
        // Invalid if:
        // 1. Out of grid bounds
        // 2. Cell is blocked (1)
        // 3. Cell already visited
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 1 || visited[row][col] == true)
        {
            return false;
        }

        // Otherwise the cell is valid
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        // n = rows, m = columns
        int n = grid.size();
        int m = grid[0].size();

        // If start or end cell is blocked, path is impossible
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
        {
            return -1;
        }

        // Queue for BFS traversal (stores cell coordinates)
        queue<pair<int,int>> q;

        // Visited matrix to avoid revisiting cells
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        // Start BFS from top-left cell
        q.push({0,0});
        visited[0][0] = true;

        // Path length (starting cell counts as length = 1)
        int length = 1;

        // BFS loop
        while(!q.empty())
        {
            // Number of nodes at current level
            int size = q.size();

            // Process all nodes of this level
            while(size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // If we reached bottom-right cell
                // return the shortest path length
                if(row == n - 1 && col == m - 1)
                {
                    return length;
                }

                // 8 possible directions (including diagonals)
                vector<int>delRow = {-1,-1,0,1,1,1,0,-1};
                vector<int>delCol = {0,1,1,1,0,-1,-1,-1};

                // Explore all 8 neighbours
                for(int k=0;k<8;k++)
                {
                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];

                    // If neighbour cell is valid
                    if(isValid(newRow,newCol,n,m,grid,visited))
                    {
                        // Add it to queue for next BFS level
                        q.push({newRow,newCol});

                        // Mark as visited
                        visited[newRow][newCol] = true;
                    }
                }
            }

            // After finishing one BFS level
            // increase path length
            length++;
        }

        // If destination never reached
        return -1;
    }
};

/*   

1️⃣ When to Use BFS

Use BFS when:

Grid + Shortest Path + Equal weight moves

Because BFS explores level by level, the first time you reach the destination = shortest path.

  */

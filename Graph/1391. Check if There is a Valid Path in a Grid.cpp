
class Solution { // TC ---> O(n × m)                           SC ---> O(n × m)
public: 

    // DFS function to check whether we can reach
    // the bottom-right cell from the current cell.
    bool solve(int row, int col, int n, int m,vector<vector<int>>& grid,vector<vector<bool>>& visited,
unordered_map<int, vector<vector<int>>>& ump) 
    { 
        // If the current cell is outside the grid
        // OR we have already visited this cell,
        // then this path is not valid.
        if(row < 0 || col < 0 || row >= n || col >= m || visited[row][col]) 
        { 
            return false; 
        } 

        // If we have reached the bottom-right cell,
        // then a valid path exists.
        if(row == n - 1 && col == m - 1) 
        { 
            return true; 
        } 

        // Mark the current cell as visited
        // to avoid visiting it again and getting stuck in a cycle.
        visited[row][col] = true; 
 
        // ump[grid[row][col]] contains all possible directions
        // in which the current street can go.
        //
        // For example:
        // grid[row][col] = 1
        // ump[1] = {{0,-1}, {0,1}}
        // means we can move LEFT or RIGHT.
        for(auto neighbor : ump[grid[row][col]]) 
        { 
            // Calculate the coordinates of the neighboring cell.
            int newRow = row + neighbor[0]; 
            int newCol = col + neighbor[1]; 
 
            // If the neighboring cell is outside the grid
            // or has already been visited, skip it.
            if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= m || visited[newRow][newCol]) 
            { 
                continue; 
            } 
 
            // Now we need to check whether the neighboring street
            // also connects BACK to the current cell.
            //
            // This is important because just because the current
            // street points toward the neighbor doesn't mean
            // the neighbor's street connects to the current cell.
            for(auto dir : ump[grid[newRow][newCol]]) 
            { 
                // dir represents one possible direction of the neighbor.
                //
                // If:
                // dir[0] + newRow == row
                // dir[1] + newCol == col
                //
                // then the neighboring cell has a street that
                // connects back to the current cell.
                if(dir[0] + newRow == row &&
                   dir[1] + newCol == col &&
                   visited[newRow][newCol] == false) 
                { 
                    // Recursively explore the neighboring cell.
                    //
                    // If we can eventually reach the destination,
                    // return true immediately.
                    if(solve(newRow, newCol, n, m, grid, visited, ump)) 
                    { 
                        return true; 
                    } 
                } 
            } 
        } 
 
        // None of the possible neighboring cells could lead
        // to the destination.
        return false; 
    } 
 
    bool hasValidPath(vector<vector<int>>& grid) { 

        // Number of rows.
        int n = grid.size(); 

        // Number of columns.
        int m = grid[0].size(); 
 
        // Map each street type to the directions
        // in which that street can connect.
        //
        // Direction format:
        // {row change, column change}
        //
        // Example:
        // {0, -1} = LEFT
        // {0,  1} = RIGHT
        // {-1, 0} = UP
        // {1,  0} = DOWN

        unordered_map<int, vector<vector<int>>> ump; 

        // Street 1 -> LEFT and RIGHT
        ump[1] = {{0,-1}, {0,1}}; 

        // Street 2 -> UP and DOWN
        ump[2] = {{-1,0}, {1,0}}; 

        // Street 3 -> LEFT and DOWN
        ump[3] = {{0,-1}, {1,0}}; 

        // Street 4 -> RIGHT and DOWN
        ump[4] = {{0,1}, {1,0}}; 

        // Street 5 -> LEFT and UP
        ump[5] = {{0,-1}, {-1,0}}; 

        // Street 6 -> RIGHT and UP
        ump[6] = {{0,1}, {-1,0}}; 
         
        // visited[row][col] tells us whether we have already
        // explored this cell.
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 

        // Start DFS from the top-left cell (0,0).
        // If DFS reaches (n-1,m-1), return true.
        return solve(0, 0, n, m, grid, visited, ump); 
    } 
};

/* 

┌──────────────────────────────────────────┐
│       VALID PATH IN GRID - DFS           │
├──────────────────────────────────────────┤
│                                          │
│ 1. Treat each cell as a STREET           │
│                                          │
│ 2. Map each street type → directions     │
│                                          │
│    1 → LEFT, RIGHT                       │
│    2 → UP, DOWN                          │
│    3 → LEFT, DOWN                        │
│    4 → RIGHT, DOWN                       │
│    5 → LEFT, UP                          │
│    6 → RIGHT, UP                         │
│                                          │
│ 3. From current street, try each         │
│    possible direction                    │
│                                          │
│ 4. Move to the next cell                 │
│                                          │
│ 5. Check TWO-WAY connection:             │
│    next street must connect BACK         │
│    to the current street                 │
│                                          │
│ 6. If connected → DFS on next cell      │
│                                          │
│ 7. Mark cells visited                    │
│    → prevents cycles                     │
│                                          │
│ 8. Reach bottom-right?                   │
│    → return true                         │
│                                          │
│ Pattern:                                 │
│ Grid + DFS + Direction Mapping           │
│                                          │
│ Time  : O(n × m)                         │
│ Space : O(n × m)                         │
└──────────────────────────────────────────┘

*/

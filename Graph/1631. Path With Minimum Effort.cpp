**************************************************APPROACH 1st(DFS)******************************************************
 // It will give TLE. 

class Solution {// Time  : O(4^(n × m))   // exponential                        Space : O(n × m)
public:

    // solve() returns the minimum possible effort from the
    // current cell (row, col) to the destination.
    //
    // effort = maximum height difference encountered
    //          in the current path so far.
    int solve(int row, int col, int n, int m,
              vector<vector<int>>& heights,
              vector<vector<bool>>& visited,
              int effort)
    {
        // If we go outside the grid OR visit a cell that is
        // already present in the current path, this path is invalid.
        if(row < 0 || col < 0 || row >= n || col >= m || visited[row][col])
        {
            return INT_MAX;
        }

        // If we reach the bottom-right cell, we have found
        // one complete path.
        //
        // 'effort' already contains the maximum height difference
        // encountered in this path.
        if(row == n - 1 && col == m - 1)
        {
            return effort;
        }

        // Mark current cell as visited.
        //
        // This prevents us from going in a cycle like:
        // (0,0) -> (0,1) -> (0,0) -> ...
        visited[row][col] = true;

        // Four possible directions:
        //       UP
        //        ↑
        // LEFT ←   → RIGHT
        //        ↓
        //       DOWN
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // We want the minimum effort among all possible paths.
        int ans = INT_MAX;

        // Try all 4 neighboring cells.
        for(int k = 0; k < 4; k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Check whether the next cell is inside the grid
            // and has not already been visited in the current path.
            if(newRow >= 0 && newRow < n &&
               newCol >= 0 && newCol < m &&
               !visited[newRow][newCol])
            {
                // Calculate the height difference between
                // the current cell and the next cell.
                int currentDiff = abs(heights[row][col] -
                                      heights[newRow][newCol]);

                // Path effort is the maximum difference encountered
                // anywhere on this path.
                //
                // Example:
                // Previous effort = 5
                // Current difference = 3
                // New effort = max(5,3) = 5
                //
                // Previous effort = 5
                // Current difference = 8
                // New effort = max(5,8) = 8
                int newEffort = max(effort, currentDiff);

                // Recursively explore the next cell.
                //
                // Among all possible paths, keep the one
                // having minimum effort.
                ans = min(ans,
                          solve(newRow, newCol, n, m,
                                heights, visited, newEffort));
            }
        }

        // BACKTRACKING:
        //
        // We are done exploring this cell for the current path.
        // Unmark it so that another different path can use it.
        visited[row][col] = false;

        return ans;
    }


    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        // visited is used to avoid cycles in the current path.
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Start from (0,0).
        //
        // Initially effort = 0 because we haven't moved anywhere yet.
        return solve(0, 0, n, m, heights, visited, 0);
    }
};

********************************************APPROACH 2nd(PRIORITY QUEUE)*********************************************

class Solution {// Time  : O(n × m × log(n × m))                              Space : O(n × m)
public:

    // P stores:
    // first  -> effort required to reach a cell
    // second -> coordinates {row, col}
    //
    // Example:
    // {5, {2, 3}}
    // means:
    // effort = 5
    // cell   = (2,3)
    typedef pair<int, pair<int,int>> P;


    // Checks whether (row, col) is inside the grid.
    bool isValid(int row, int col, int n, int m)
    {
        if(row < 0 || col < 0 || row >= n || col >= m)
        {
            return false;
        }

        return true;
    }


    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int n = heights.size();
        int m = heights[0].size();


        // ans[row][col] stores the minimum effort required
        // to reach cell (row, col) from (0,0).
        //
        // Initially, we don't know the effort for any cell,
        // so we initialize everything with INT_MAX.
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));


        // Min-heap priority queue.
        //
        // The cell with the smallest effort will come out first.
        //
        // P = {effort, {row, col}}
        priority_queue<P, vector<P>, greater<P>> pq;


        // Start from the source cell (0,0).
        //
        // No movement has happened yet,
        // therefore initial effort is 0.
        pq.push({0, {0, 0}});

        ans[0][0] = 0;


        // Keep processing cells until the priority queue is empty.
        while(!pq.empty())
        {
            // Get the smallest effort currently available.
            int diff = pq.top().first;

            // Get the coordinates of that cell.
            auto coord = pq.top().second;

            // Remove the current element from the priority queue.
            pq.pop();


            int row = coord.first;
            int col = coord.second;


            // Four possible directions:
            //
            //        UP
            //         ↑
            // LEFT ← CELL → RIGHT
            //         ↓
            //       DOWN
            vector<int> delRow = {-1, 0, 1, 0};
            vector<int> delCol = {0, 1, 0, -1};


            // Try all 4 neighboring cells.
            for(int k = 0; k < 4; k++)
            {
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];


                // Check whether the neighboring cell
                // is inside the grid.
                if(isValid(newRow, newCol, n, m))
                {
                    // Calculate the height difference between
                    // the current cell and the neighboring cell.
                    int absDiff = abs(heights[row][col] - heights[newRow][newCol]);


                    // IMPORTANT:
                    //
                    // The effort of a path is NOT the sum
                    // of all height differences.
                    //
                    // It is the maximum height difference
                    // encountered along the path.
                    //
                    // Example:
                    //
                    // differences = 3, 7, 2
                    //
                    // effort = max(3,7,2) = 7
                    int maxDiff = max(diff, absDiff);


                    // If this path reaches the neighboring cell
                    // with less effort than the best effort
                    // we previously found, update it.
                    if(ans[newRow][newCol] > maxDiff)
                    {
                        // Store the better effort.
                        ans[newRow][newCol] = maxDiff;


                        // Add the neighboring cell to the
                        // priority queue.
                        //
                        // The priority queue will process the
                        // cell with the smallest effort first.
                        pq.push({maxDiff,{newRow, newCol}});
                    }
                }
            }
        }


        // Return the minimum effort required to reach
        // the bottom-right cell.
        return ans[n - 1][m - 1];
    }
};

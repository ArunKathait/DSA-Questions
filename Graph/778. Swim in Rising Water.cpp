**************************************************************************************************************************
⏱️ Time Complexity

DFS check (possibleToReach):
Visits each cell at most once ⇒ O(n²)

Binary Search range:
From 0 to n²−1 ⇒ O(log n²) = O(log n)

🧮 Space Complexity

Visited matrix: n × n ⇒ O(n²)

DFS recursion stack (worst case): O(n²)

**************************************************************************************************************************
class Solution {// TC ---> O(N^2 * LogN)                                   SC ---> O(N^2)
public:
    // DFS to check if we can reach bottom-right with water level = T
    bool possibleToReach(int row, int col, int n, int m, int T, vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
        // Out of bounds OR already visited OR cell height > water level
        if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] || grid[row][col] > T)
        {
            return false;
        }

        // Mark current cell as visited
        visited[row][col] = true;

        // If destination is reached
        if (row == n - 1 && col == m - 1)
        {
            return true;
        }

        // Direction vectors: up, right, down, left
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Explore all 4 directions
        for (int k = 0; k < 4; k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // If any path leads to destination, return true
            if (possibleToReach(newRow, newCol, n, m, T, grid, visited))
            {
                return true;
            }
        }

        // No valid path found
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Binary search range for time (0 to n*n - 1)
        int low = grid[0][0];
        int high = n * n - 1;
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Fresh visited matrix for every mid
            vector<vector<bool>> visited(n, vector<bool>(m, false));

            // Check if reachable at time = mid
            if (possibleToReach(0, 0, n, m, mid, grid, visited))
            {
                ans = mid;          // mid is a valid answer
                high = mid - 1;     // try smaller time
            }
            else
            {
                low = mid + 1;      // need more time
            }
        }

        return ans;
    }
};

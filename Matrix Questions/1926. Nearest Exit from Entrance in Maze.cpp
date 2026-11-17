
class Solution {// Time Complexity: O(n * m)                Space Complexity: O(n * m)
public:

    // Checks whether the given cell is valid or not.
    // A cell is valid if:
    // 1. It is inside the maze boundaries.
    // 2. It is not a wall ('+').
    bool isValid(int row, int col, int n, int m, vector<vector<char>>& maze)
    {
        // Check if the cell is outside the maze or is a wall.
        if(row < 0 || col < 0 || row >= n || col >= m || maze[row][col] == '+')
        {
            return false;
        }

        return true;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        // Get the number of rows and columns in the maze.
        int n = maze.size();
        int m = maze[0].size();

        // Queue is used for BFS traversal.
        // It stores the coordinates (row, col) of each cell.
        queue<pair<int,int>> q;

        // Push the entrance position into the queue.
        q.push({entrance[0], entrance[1]});

        // Mark the entrance as visited by converting it into a wall.
        // This prevents us from visiting it again.
        maze[entrance[0]][entrance[1]] = '+';

        // Stores the number of steps taken from the entrance.
        int steps = 0;

        // Directions to move:
        // Up    -> (-1, 0)
        // Right -> (0, 1)
        // Down  -> (1, 0)
        // Left  -> (0, -1)
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Continue BFS until the queue becomes empty.
        while(!q.empty())
        {
            // Get the number of cells present at the current BFS level.
            // All these cells are at the same distance from the entrance.
            int size = q.size();

            // Process all cells belonging to the current level.
            while(size--)
            {
                // Get the front cell from the queue.
                auto front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                // Check whether the current cell is on the boundary.
                // If it is a boundary cell and NOT the entrance,
                // we have found the nearest exit.
                if((row == 0 || col == 0 || row == n - 1 || col == m - 1) &&
                   !(row == entrance[0] && col == entrance[1]))
                {
                    // Return the minimum number of steps.
                    return steps;
                }

                // Explore all four possible directions.
                for(int k = 0; k < 4; k++)
                {
                    // Calculate the coordinates of the neighbouring cell.
                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];

                    // Check whether the neighbouring cell is valid.
                    if(isValid(newRow, newCol, n, m, maze))
                    {
                        // Add the valid neighbouring cell to the queue.
                        q.push({newRow, newCol});

                        // Mark it as visited immediately.
                        // This prevents duplicate insertion into the queue.
                        maze[newRow][newCol] = '+';
                    }
                }
            }

            // After processing all cells at the current level,
            // move to the next BFS level.
            // Each new level represents one additional step.
            steps++;
        }

        // If BFS finishes without finding an exit, return -1.
        return -1;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Nearest Exit in a Maze (LC 1926)    │
├──────────────────────────────────────────────┤
│ • Approach: BFS (Queue + Level Order)        │
│                                              │
│ • Key Idea:                                  │
│   Start BFS from the entrance.               │
│   Explore all 4 directions (Up, Right,       │
│   Down, Left) at each step.                  │
│   Mark visited cells as '+' to avoid         │
│   revisiting the same cell.                  │
│   Each BFS level represents one step.        │
│   Return steps when the nearest boundary     │
│   cell (excluding entrance) is reached.      │
│                                              │
│ • Pattern: Shortest Path in Unweighted Grid  │
│   (Level Order BFS)                          │
├──────────────────────────────────────────────┤
│ • isValid(): Checks boundaries and walls.    │
│ • Queue: Stores row and column coordinates.  │
│ • Visited: Marks cells by changing '.' to '+'.│
│                                              │
│ • Time Complexity:       O(n * m)            │
│ • Space Complexity:      O(n * m)            │
│ • Auxiliary Space:      O(n * m) (Queue)     │
└──────────────────────────────────────────────┘

*/

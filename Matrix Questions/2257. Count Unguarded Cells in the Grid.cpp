**********************************************APPROACH 1st(ITERATIVE)***********************************************

class Solution {// TC ---> O(g × (m + n) + m × n)                                 SC ---> O(m × n)
public:
    // Function to mark all cells that are guarded by a guard positioned at (row, col)
    void solve(int row, int col, int m, int n, vector<vector<int>>& grid)
    {
        // ---------------------------
        // Move UP from the guard’s position
        // ---------------------------
        for (int i = row - 1; i >= 0; i--)
        {
            // Stop if we encounter another guard (2) or wall (3)
            if (grid[i][col] == 2 || grid[i][col] == 3)
            {
                break;
            }

            // Mark this cell as guarded (1)
            grid[i][col] = 1;
        }

        // ---------------------------
        // Move DOWN from the guard’s position
        // ---------------------------
        for (int i = row + 1; i < m; i++)
        {
            if (grid[i][col] == 2 || grid[i][col] == 3)
            {
                break;
            }

            grid[i][col] = 1;
        }

        // ---------------------------
        // Move LEFT from the guard’s position
        // ---------------------------
        for (int j = col - 1; j >= 0; j--)
        {
            if (grid[row][j] == 2 || grid[row][j] == 3)
            {
                break;
            }

            grid[row][j] = 1;
        }

        // ---------------------------
        // Move RIGHT from the guard’s position
        // ---------------------------
        for (int j = col + 1; j < n; j++)
        {
            if (grid[row][j] == 2 || grid[row][j] == 3)
            {
                break;
            }

            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        // Create a grid of size m x n initialized with 0
        // 0 → unguarded empty cell
        // 1 → guarded cell
        // 2 → guard position
        // 3 → wall position
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // -------------------------------------
        // Step 1: Mark all guard positions as 2
        // -------------------------------------
        for (auto &x : guards)
        {
            int i = x[0];
            int j = x[1];
            grid[i][j] = 2;
        }

        // -------------------------------------
        // Step 2: Mark all wall positions as 3
        // -------------------------------------
        for (auto &x : walls)
        {
            int i = x[0];
            int j = x[1];
            grid[i][j] = 3;
        }

        // -------------------------------------
        // Step 3: For each guard, mark all the cells it can watch
        // -------------------------------------
        for (auto &vec : guards)
        {
            int i = vec[0];
            int j = vec[1];
            solve(i, j, m, n, grid); // Spread guard’s view in all 4 directions
        }

        // -------------------------------------
        // Step 4: Count all unguarded cells (still 0)
        // -------------------------------------
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If a cell remains 0 → it’s not a wall, not a guard, not watched
                if (grid[i][j] == 0)
                {
                    ans++;
                }
            }
        }

        // -------------------------------------
        // Step 5: Return total count of unguarded cells
        // -------------------------------------
        return ans;
    }
};

***********************************************APPROACH 2nd(RECURSIVE)*********************************************

class Solution {// TC ---> O(m × n)                                   SC ---> O(m × n)
public:
    // 🔹 This function moves recursively in one direction from a guard's position
    // dx and dy represent the direction vector:
    // (-1, 0) → up, (1, 0) → down, (0, -1) → left, (0, 1) → right
    void guardDirection(int i, int j, int m, int n, vector<vector<int>>& grid, int dx, int dy) {
        // Base case 1: stop if we go outside the grid boundaries
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;

        // Base case 2: stop if we hit another guard (2) or a wall (3)
        if (grid[i][j] == 2 || grid[i][j] == 3)
            return;

        // Mark current cell as guarded (1) if it was empty
        if (grid[i][j] == 0)
            grid[i][j] = 1;

        // Recursive call: move further in the same direction
        guardDirection(i + dx, j + dy, m, n, grid, dx, dy);
    }

    // 🔹 For each guard, explore in all four directions using recursion
    void solve(int row, int col, int m, int n, vector<vector<int>>& grid) {
        // Move up
        guardDirection(row - 1, col, m, n, grid, -1, 0);
        // Move down
        guardDirection(row + 1, col, m, n, grid, 1, 0);
        // Move left
        guardDirection(row, col - 1, m, n, grid, 0, -1);
        // Move right
        guardDirection(row, col + 1, m, n, grid, 0, 1);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Step 1️⃣: Create a grid initialized with 0 → empty cell
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Step 2️⃣: Place guards on the grid and mark them as 2
        for (auto &x : guards)
            grid[x[0]][x[1]] = 2;

        // Step 3️⃣: Place walls on the grid and mark them as 3
        for (auto &x : walls)
            grid[x[0]][x[1]] = 3;

        // Step 4️⃣: For each guard, mark all cells visible to it using recursion
        for (auto &vec : guards)
            solve(vec[0], vec[1], m, n, grid);

        // Step 5️⃣: Count all cells that remain unguarded (value == 0)
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    ans++;
            }
        }

        // Step 6️⃣: Return the total count of unguarded cells
        return ans;
    }
};


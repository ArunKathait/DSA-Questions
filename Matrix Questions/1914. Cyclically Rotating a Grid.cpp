
class Solution { 
    
    // TC ---> O(N * M)
    // SC ---> O(N + M)

public:

    // Function to rotate a 1D vector by k positions
    // This performs LEFT ROTATION (Anti-clockwise)
    void rotate(vector<int>& temp, int k)
    { 
        int n = temp.size();

        // Step 1: Reverse complete vector
        reverse(temp.begin(), temp.end());

        // Step 2: Reverse first (n-k) elements
        reverse(temp.begin(), temp.begin() + (n-k));

        // Step 3: Reverse last k elements
        reverse(temp.begin() + (n-k), temp.end());
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        // Number of rows
        int n = grid.size();

        // Number of columns
        int m = grid[0].size();

        // Total layers/rings present in matrix
        // Example:
        // 4x4 -> 2 layers
        // 5x4 -> 2 layers
        int layers = min(n, m) / 2;

        // Process every layer independently
        for(int layer = 0; layer < layers; layer++)
        {
            // Stores elements of current layer
            vector<int> temp;

            // Boundaries of current layer
            int top = layer;
            int bottom = n - layer - 1;
            int left = layer;
            int right = m - layer - 1;

            // --------------------------------
            // Extract elements of current layer
            // --------------------------------

            // Top row (left -> right)
            for(int j = left; j <= right; j++)
            {
                temp.push_back(grid[top][j]);
            }

            // Right column (top+1 -> bottom)
            // Top-right corner already included
            for(int i = top + 1; i <= bottom; i++)
            {
                temp.push_back(grid[i][right]);
            }

            // Bottom row (right-1 -> left)
            // Bottom-right corner already included
            for(int j = right - 1; j >= left; j--)
            {
                temp.push_back(grid[bottom][j]);
            }

            // Left column (bottom-1 -> top+1)
            // Both corners already included
            for(int i = bottom - 1; i > top; i--)
            {
                temp.push_back(grid[i][left]);
            }

            // Reduce unnecessary rotations
            int rotations = k % temp.size();

            // Rotate extracted layer
            rotate(temp, rotations);

            // Pointer for temp vector
            int index = 0;

            // --------------------------------
            // Put rotated elements back
            // --------------------------------

            // Fill top row
            for(int j = left; j <= right; j++)
            {
                grid[top][j] = temp[index++];
            }

            // Fill right column
            for(int i = top + 1; i <= bottom; i++)
            {
                grid[i][right] = temp[index++];
            }

            // Fill bottom row
            for(int j = right - 1; j >= left; j--)
            {
                grid[bottom][j] = temp[index++];
            }

            // Fill left column
            for(int i = bottom - 1; i > top; i--)
            {
                grid[i][left] = temp[index++];
            }
        }

        // Return final rotated grid
        return grid;
    }
};

/* NOTE : 

🔥 Clockwise (Right Rotation)

Rotate by k = 2

Expected:

4 5 1 2 3

✅ Formula
reverse(arr.begin(), arr.end());

reverse(arr.begin(), arr.begin() + k);

reverse(arr.begin() + k, arr.end());

🔥 Anti-clockwise (Left Rotation)

Rotate by k = 2

Expected:

3 4 5 1 2

✅ Formula
reverse(arr.begin(), arr.end());

reverse(arr.begin(), arr.begin() + (n - k));

reverse(arr.begin() + (n - k), arr.end());

*/

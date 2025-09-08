
class Solution {// Time Complexity ---> O(N²)                           Space Complexity ---> O(N²)
public:
    vector<vector<int>> generateMatrix(int n) {
        // Define matrix boundaries
        int left = 0;        // leftmost column
        int right = n - 1;   // rightmost column
        int top = 0;         // top row
        int down = n - 1;    // bottom row

        int val = 1;         // number to be filled in the matrix (1 to n*n)
        int direction = 0;   // 0 = left->right, 1 = top->bottom, 2 = right->left, 3 = bottom->top

        // Create an n x n matrix initialized with 0
        vector<vector<int>> matrix(n, vector<int>(n));

        // Continue filling until boundaries cross each other
        while (top <= down && left <= right)
        {
            if (direction == 0)  // move left → right
            {
                for (int i = left; i <= right; i++) 
                {
                    // fill top row
                    matrix[top][i] = val++;   
                }

                // shift top boundary down
                top++; 
            }
            else if (direction == 1)  // move top → bottom
            {
                for (int i = top; i <= down; i++) 
                {
                    // fill right column
                    matrix[i][right] = val++;  
                }

                // shift right boundary left
                right--; 
            }
            else if (direction == 2)  // move right → left
            {
                for (int i = right; i >= left; i--) 
                {
                    // fill bottom row
                    matrix[down][i] = val++;  
                }

                // shift bottom boundary up
                down--; 
            }
            else if (direction == 3)  // move bottom → top
            {
                for (int i = down; i >= top; i--) 
                {
                    // fill left column
                    matrix[i][left] = val++;  
                }

                // shift left boundary right
                left++; 
            }

            // Cycle direction: 0 → 1 → 2 → 3 → back to 0
            direction = (direction + 1) % 4;
        }

        // Return the filled spiral matrix
        return matrix;
    }
};


class Solution {// TC--->O(N*M)                         SC--->O(N*M)
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Get the number of rows (n) and columns (m) of the matrix
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Initialize boundary pointers
        int left = 0;          // Left boundary
        int right = m-1;       // Right boundary
        int top = 0;           // Top boundary
        int down = n-1;        // Bottom boundary
        
        // Vector to store the result (spiral order)
        vector<int>ans;
        
        // Variable to keep track of the current direction
        // 0 = left to right, 1 = top to bottom, 2 = right to left, 3 = bottom to top
        int direction = 0;
        
        // Loop until the boundaries overlap or cross each other
        while(left <= right && top <= down)
        {
            // Traverse from left to right
            if(direction == 0)
            {
                for(int i=left;i<=right;i++)
                {
                    // Add the top row elements
                    ans.push_back(matrix[top][i]);
                }
                
                // Move the top boundary down
                top++;
            }
            
            // Traverse from top to bottom
            else if(direction == 1)
            {
                for(int i=top;i<=down;i++)
                {
                    // Add the right column elements
                    ans.push_back(matrix[i][right]);
                }
                
                // Move the right boundary left
                right--;
            }
            
            // Traverse from right to left
            else if(direction == 2)
            {
                for(int i=right;i>=left;i--)
                {
                    // Add the bottom row elements
                    ans.push_back(matrix[down][i]);
                }
                
                // Move the bottom boundary up
                down--;
            }
            
            // Traverse from bottom to top
            else if(direction == 3)
            {
                for(int i=down;i>=top;i--)
                {
                    // Add the left column elements
                    ans.push_back(matrix[i][left]);
                }
                
                // Move the left boundary right
                left++;
            }
            
            // Update the direction for the next loop iteration
            direction = (direction + 1)%4;
        }
        
        // Return the result in spiral order
        return ans;
    }
};

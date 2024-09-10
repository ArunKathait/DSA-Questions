
class Solution {// TC--->O(m * n)                   SC--->O(m * n)
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize a 2D matrix of size m x n, filled with -1 (default value)
        vector<vector<int>>ans(m,vector<int>(n,-1));
        
        // Define boundaries for the matrix traversal
        int left = 0;        // Left boundary (starts at 0)
        int right = n-1;     // Right boundary (starts at n-1)
        int top = 0;         // Top boundary (starts at 0)
        int down = m-1;      // Bottom boundary (starts at m-1)
        
        // Variable to keep track of the current direction
        // 0: left-to-right, 1: top-to-bottom, 2: right-to-left, 3: bottom-to-top
        int direction = 0;
        
        // Continue looping until the boundaries are valid
        while(left <= right && top <= down)
        {
            // Case 0: Traverse left to right
            if(direction == 0)
            {
                // Fill the top row from 'left' to 'right' if the current node exists
                for(int i=left;i<=right && head != NULL;i++)
                {
                    // Set the matrix cell to the current node's value
                    ans[top][i] = head->val;
                    
                    // Move to the next node in the list
                    head = head->next;
                }
                
                // Move the top boundary down after filling the row
                top++;
            }
            
            // Case 1: Traverse top to bottom
            if(direction == 1)
            {
                // Fill the right column from 'top' to 'down' if the current node exists
                for(int i=top;i<=down && head != NULL;i++)
                {
                    // Set the matrix cell to the current node's value
                    ans[i][right] = head->val;
                    
                    // Move to the next node in the list
                    head = head->next;
                }
                
                // Move the right boundary left after filling the column
                right--;
            }
            
            // Case 2: Traverse right to left
            if(direction == 2)
            {
                 // Fill the bottom row from 'right' to 'left' if the current node exists
                for(int i=right;i>=left && head != NULL;i--)
                {
                    // Set the matrix cell to the current node's value
                    ans[down][i] = head->val;
                    
                    // Move to the next node in the list
                    head = head->next;
                }
                
                // Move the bottom boundary up after filling the row
                down--;
            }
            
            // Case 3: Traverse bottom to top
            if(direction == 3)
            {
                // Fill the left column from 'down' to 'top' if the current node exists
                for(int i=down;i>=top && head != NULL;i--)
                {
                    // Set the matrix cell to the current node's value
                    ans[i][left] = head->val;
                    
                    // Move to the next node in the list
                    head = head->next;
                }
                
                // Move the left boundary right after filling the column
                left++;
            }
            
            // Change the direction for the next iteration, rotating through 0 -> 1 -> 2 -> 3 -> 0...
            direction = (direction + 1)%4;
        }
        
        // Return the filled spiral matrix
        return ans;
    }
};

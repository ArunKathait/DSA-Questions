
class Solution {// TC--->O(max(N,M)^2)                   SC--->O(N*M)
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        // Directions represent the order of movement:
        // Right -> Down -> Left -> Up
        vector<vector<int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
        
        // Vector to store the final sequence of matrix positions visited in the spiral order
        vector<vector<int>>ans;
        
        // 'dir' keeps track of the current direction we're moving in.
        // 'steps' counts how many steps we'll take in the current direction.
        
        // Start by moving to the right (directions[0])
        int dir = 0;
        int steps = 0;
        
        // Start by adding the initial position to the answer vector.
        ans.push_back({rStart,cStart});
        
        // Continue looping until we've visited all cells (rows * cols)
        while(ans.size() < rows*cols)
        {
            // Increase the number of steps when moving right (dir == 0) or left (dir == 2)
            if(dir == 0 || dir == 2)
            {
                steps++;
            }
            
            // Move in the current direction 'steps' times
            for(int count=0;count<steps;count++)
            {
                // Update the current position based on the direction
                rStart += directions[dir][0];// Update row
                cStart += directions[dir][1];// Update column
                
                // Check if the new position is within the grid bounds
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    // If within bounds, add the position to the answer vector
                    ans.push_back({rStart,cStart});
                }
            }
            
            // Change direction: right -> down -> left -> up, and repeat
            dir = (dir + 1)%4;
        }
        
        // Return the spiral order of visited positions
        return ans;
    }
};

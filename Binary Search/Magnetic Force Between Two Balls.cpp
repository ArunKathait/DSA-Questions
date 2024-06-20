************************************************APPROACH 1st(USING BINARY SEARCH)*************************************

class Solution {// TC--->O(NlogN + N*log(maxForce))                SC--->O(1)
public:
    // Helper function to determine if it's possible to place m balls
    // such that the minimum distance between any two balls is at least midForce
    bool possibleToPlace(vector<int>&position,int midForce,int m)
    {
        // Place the first ball at the first position
        int prev = position[0];
        
        // We have placed one ball
        int countBalls = 1;
        
        // Loop through the rest of the positions
        for(int i=1;i<position.size();i++)
        {
            int current = position[i];
            
            // Check if the current position is at least midForce away from the previous ball
            if(current - prev >= midForce)
            {
                // Place another ball
                countBalls++;
                
                // Update the position of the last placed ball
                prev = current;
            }
            
            // If we've placed all m balls, we can break early
            if(countBalls == m)
            {
                break; 
            }
        }
        
        // Return true if we've managed to place all m balls, false otherwise
        return countBalls == m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        // Sort the positions to facilitate the binary search
        sort(position.begin(),position.end());
        
        // Minimum possible force (distance) is 1
        int minForce = 1;
        
        // Maximum possible force (distance) is the largest position value
        int maxForce = *max_element(position.begin(),position.end());
        
        // Initialize the answer with the smallest possible force
        int ans = 1;
        
        // Binary search for the maximum minimum force
        while(minForce <= maxForce)
        {
            // Find the middle force
            int midForce = minForce + (maxForce - minForce)/2;
                 
            // Check if it's possible to place the balls with at least midForce distance apart   
            if(possibleToPlace(position,midForce,m))
            {
                // Update the answer to the current midForce
                ans = midForce;
                
                // Try for a larger force
                minForce = midForce + 1;
            }
            else
            {
                // Try for a smaller force
                maxForce = midForce - 1;
            }
        }
        // Return the maximum minimum force found
        return ans;
    }
};

***********************************************APPROACH 2nd(MINOR CHANGE)***************************************

class Solution {// TC--->O(NlogN + N*log(maxForce))                SC--->O(1)
public:
    // Helper function to determine if it's possible to place m balls
    // such that the minimum distance between any two balls is at least midForce
    bool possibleToPlace(vector<int>&position,int midForce,int m)
    {
        // Place the first ball at the first position
        int prev = position[0];
        
        // We have placed one ball
        int countBalls = 1;
        
        // Loop through the rest of the positions
        for(int i=1;i<position.size();i++)
        {
            int current = position[i];
            
            // Check if the current position is at least midForce away from the previous ball
            if(current - prev >= midForce)
            {
                // Place another ball
                countBalls++;
                
                // Update the position of the last placed ball
                prev = current;
            }
            
            // If we've placed all m balls, we can break early
            if(countBalls == m)
            {
                break; 
            }
        }
        
        // Return true if we've managed to place all m balls, false otherwise
        return countBalls == m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        
        // Sort the positions to facilitate the binary search
        sort(position.begin(),position.end());
        
        // Minimum possible force (distance) is 1
        int minForce = 1;
        
        // Maximum possible distance between any two balls placed at the extreme positions in the sorted array.
        int maxForce = position[n-1] - position[0];
        
        // Initialize the answer with the smallest possible force
        int ans = 1;
        
        // Binary search for the maximum minimum force
        while(minForce <= maxForce)
        {
            // Find the middle force
            int midForce = minForce + (maxForce - minForce)/2;
                 
            // Check if it's possible to place the balls with at least midForce distance apart   
            if(possibleToPlace(position,midForce,m))
            {
                // Update the answer to the current midForce
                ans = midForce;
                
                // Try for a larger force
                minForce = midForce + 1;
            }
            else
            {
                // Try for a smaller force
                maxForce = midForce - 1;
            }
        }
        // Return the maximum minimum force found
        return ans;
    }
};

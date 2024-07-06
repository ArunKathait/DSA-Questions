
class Solution {// TC--->O(time)             SC--->O(1)
public:
    int passThePillow(int n, int time) {
        // Initialize the flag to indicate the direction of passing (true for forward, false for backward)
        bool flag = true;
        
        // Initialize the starting position (1-based index)
        int i = 1;
        
        // Loop for the given amount of time
        while(time--)
        {
            // If the pillow reaches the first or last person, change the direction
            if(i == 0 || i == n)
            {
                flag = !flag;
            }
            
            // Move the pillow to the next person based on the current direction
            if(flag)
            {
                // Move forward
                i++;
            }
            else
            {
                // Move backward
                i--;
            }
        }
        
        // Return the final position of the pillow after the given time
        return i;
    }
};

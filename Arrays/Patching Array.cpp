
class Solution {// TC--->O(M + logN)               SC--->O(1)
public:
    int minPatches(vector<int>& nums, int n) {
        // Initialize the number of patches required to 0
        int patch = 0;
        
        // Initialize the current index in the nums array to 0
        int i = 0;
        
        // Initialize the current maximum range that can be formed to 0
        long maxRange = 0;
        
        // Loop until the maximum range is less than n
        while(maxRange < n)
        {
            // If the current index is within bounds and nums[i] can be used to extend the range
            if(i < nums.size() && nums[i] <= (maxRange + 1))
            {
                // Extend the range by adding nums[i]
                maxRange += nums[i];
                
                // Move to the next number in the array
                i++;
            }
            else
            {
                // Otherwise, add a patch (maxRange + 1) to extend the range
                maxRange += (maxRange + 1);
                
                 // Increment the number of patches used
                patch++;
            }
        }
        
        // Return the total number of patches required
        return patch;
    }
};


class Solution {// TC--->O(N)                         SC--->O(1)
public:
    // Function to find the length of the longest subarray where all elements are equal to the maximum value
    int longestSubarray(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
        
        // Variable to store the maximum value in the array
        int maxVal = 0;
        
        // Variable to store the length of the longest subarray of maxVal
        int ans = 0;
        
        // Variable to keep track of the current length of the subarray with maxVal
        int streak = 0;
        
        // Iterate through each number in the input array
        for(auto &num:nums)
        {
            // If the current number is greater than the current maximum value
            if(num > maxVal)
            {
                // Update maxVal to the current number
                maxVal = num;
                
                // Reset the current streak because we have a new max value
                streak = 0;
                
                // Reset the answer as well because we need to start over
                ans = 0;
            }
            
            // If the current number is equal to the current max value
            if(num == maxVal)
            {
                // Increment the streak as we are continuing with the subarray of maxVal
                streak++;
            }
            else
            {
                // If the current number is not maxVal, reset the streak to 0
                streak = 0;
            }
            
            // Update the answer to the maximum streak found so far
            ans = max(ans,streak);
        }
        
        // Return the length of the longest subarray where all elements are equal to maxVal
        return ans;
    }
};

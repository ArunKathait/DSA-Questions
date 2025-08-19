
class Solution {
public:
    // Overall Time Complexity: O(n) → We traverse the array only once.
    // Overall Space Complexity: O(1) → We only use a few variables (ans, count).
    long long zeroFilledSubarray(vector<int>& nums) {
        // Get the size of the array
        int n = nums.size();  

        // Final answer (use long long since the number of subarrays can be very large)
        long long ans = 0;    

        // Counter to keep track of consecutive zeros
        long long count = 0;  

        // Traverse the array
        for (int i = 0; i < n; i++) 
        {
            // If current element is NOT zero, reset consecutive zero count
            if (nums[i] != 0) 
            {
                count = 0;
            } 
            // If current element is zero
            else 
            {
                // Increase consecutive zero streak length
                count++;      
                
                // Add count to answer because:
                // - Each new zero extends all previous zero-filled subarrays by 1
                // - Plus it forms a new single-element subarray
                ans += count; 
            }
        }

        // Return total number of zero-filled subarrays
        return ans;  
    }
};

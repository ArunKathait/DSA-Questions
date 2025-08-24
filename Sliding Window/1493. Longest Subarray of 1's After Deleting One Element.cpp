
class Solution {// Time Complexity ---> O(n)                     Space Complexity ---> O(1)
public:
    int longestSubarray(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
         
        // Left pointer of sliding window
        int i = 0;

        // Right pointer of sliding window
        int j = 0;

        // Count of zeros in the current window
        int zeroCount = 0;

        // Maximum valid window length found so far
        int ans = 0;
        
        // Expand the window using the right pointer
        while (j < n)
        {
            // If the current element is zero, increment zeroCount
            if (nums[j] == 0) 
            {
                zeroCount++;
            }

            // If the window contains more than 1 zero,
            // shrink the window from the left until it becomes valid again
            while (zeroCount > 1) 
            {
                // If we are removing a zero from the left, reduce zeroCount
                if (nums[i] == 0) 
                {
                    zeroCount--;
                }
                // Move left pointer ahead
                i++;
            }

            // At this point, the window [i...j] has at most 1 zero
            // Update the maximum window size
            ans = max(ans, j - i + 1);

            // Expand the window by moving right pointer
            j++;
        }

        // Subtract 1 because we must delete exactly one element
        return ans - 1;
    }
};

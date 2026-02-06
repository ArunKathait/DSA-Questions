
class Solution {// TC ---> O(nlogn)                             SC ---> O(1)
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Sort the array
        // Sorting helps us easily track min and max using two pointers
        sort(nums.begin(), nums.end());

        // These will store the current minimum and maximum in the window
        int minVal = nums[0];
        int maxVal = nums[0];

        // Two pointers for sliding window
        int i = 0;  // left pointer (minimum element)
        int j = 0;  // right pointer (maximum element)

        // Stores the maximum length of a valid subarray found
        int length = 0;

        // Step 2: Sliding window approach
        while (j < n)
        {
            // Current window min and max
            minVal = nums[i];
            maxVal = nums[j];

            // If condition is violated:
            // maxVal > k * minVal
            // then shrink the window from the left
            while (i < j && maxVal > (long long)k * minVal)
            {
                i++;                  // move left pointer forward
                minVal = nums[i];     // update min value
            }

            // Update the maximum valid window size
            length = max(length, j - i + 1);

            // Expand window from the right
            j++;
        }

        // Step 3: Minimum removals = total elements - largest valid window
        return n - length;
    }
};

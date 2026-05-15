
class Solution {
public:

    // TC ---> O(log N)
    // SC ---> O(1)

    int findMin(vector<int>& nums) {

        // Total size of array
        int n = nums.size();

        // Binary search pointers
        int low = 0;
        int high = n - 1;

        // -----------------------------------------
        // Binary Search
        // -----------------------------------------
        while(low < high)
        {
            // Find middle index
            int mid = low + (high - low) / 2;

            // -----------------------------------------
            // Case 1:
            // nums[mid] > nums[high]
            //
            // Example:
            // 4 5 6 7 0 1 2
            //       ^
            //      mid
            //
            // Right side contains rotation point
            // so minimum lies on right side
            // -----------------------------------------
            if(nums[mid] > nums[high])
            {
                // Eliminate left half including mid
                low = mid + 1;
            }

            // -----------------------------------------
            // Case 2:
            // nums[mid] <= nums[high]
            //
            // Example:
            // 0 1 2 4 5 6
            //     ^
            //    mid
            //
            // Right side is sorted.
            // Minimum may be:
            // - at mid
            // - or on left side
            // -----------------------------------------
            else
            {
                // Keep mid inside search space
                high = mid;
            }
        }

        // -----------------------------------------
        // low == high
        //
        // Both point to minimum element
        // -----------------------------------------
        return nums[low];
    }
};

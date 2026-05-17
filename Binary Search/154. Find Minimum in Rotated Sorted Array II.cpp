
class Solution {
public:

    // TC ---> O(log N) average
    // Worst Case ---> O(N)
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
            // Minimum lies on right side
            // because rotation exists there
            // -----------------------------------------
            if(nums[mid] > nums[high])
            {
                // Eliminate left half including mid
                low = mid + 1;
            }

            // -----------------------------------------
            // Case 2:
            // nums[mid] < nums[high]
            //
            // Example:
            // 0 1 2 4 5
            //     ^
            //    mid
            //
            // Right side is sorted.
            // Minimum may be:
            // - at mid
            // - or on left side
            // -----------------------------------------
            else if(nums[mid] < nums[high])
            {
                // Keep mid inside search space
                high = mid;
            }

            // -----------------------------------------
            // Case 3:
            // nums[mid] == nums[high]
            //
            // Example:
            // 2 2 2 0 1 2
            //
            // We cannot determine:
            // - minimum on left?
            // - minimum on right?
            //
            // Since nums[high] is duplicate,
            // safely remove it
            // -----------------------------------------
            else
            {
                high--;
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

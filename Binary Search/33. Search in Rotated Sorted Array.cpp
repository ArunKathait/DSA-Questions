
class Solution {// Time  : O(log n)                                                      Space : O(1)
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        // We will use binary search.
        // Even though the complete array is rotated,
        // at least one half will always be sorted.

        while(low <= high)
        {
            // Calculate middle index safely
            int mid = low + (high - low) / 2;

            // If middle element is the target,
            // return its index.
            if(nums[mid] == target)
            {
                return mid;
            }

            // Check whether the LEFT half is sorted.
            //
            // Example:
            // [4, 5, 6, 7, 0, 1, 2]
            //  low       mid
            //
            // nums[low] <= nums[mid] means
            // left side is sorted.
            if(nums[low] <= nums[mid])
            {
                // Now check whether target lies
                // inside this sorted left half.
                //
                // We don't need to check nums[mid] == target
                // because it was already checked above.
                if(nums[low] <= target && target < nums[mid])
                {
                    // Target is in the left half.
                    high = mid - 1;
                }
                else
                {
                    // Target is NOT in the left half,
                    // so search in the right half.
                    low = mid + 1;
                }
            }

            // Otherwise, the RIGHT half is sorted.
            else
            {
                // Check whether target lies
                // inside the sorted right half.
                if(nums[mid] < target && target <= nums[high])
                {
                    // Target is in the right half.
                    low = mid + 1;
                }
                else
                {
                    // Target is NOT in the right half,
                    // so search in the left half.
                    high = mid - 1;
                }
            }
        }

        // Target does not exist in the array.
        return -1;
    }
};

/* 

1️⃣ Find mid

        low       mid       high
         ↓         ↓          ↓
        [4  5  6  7  0  1  2]


2️⃣ Check which half is sorted

   nums[low] <= nums[mid]
              ↓
        LEFT half is sorted


3️⃣ Check if target lies in sorted half

   nums[low] <= target < nums[mid]
              ↓
          YES → search LEFT
          NO  → search RIGHT


4️⃣ Otherwise

   RIGHT half is sorted

   nums[mid] < target <= nums[high]
              ↓
          YES → search RIGHT
          NO  → search LEFT


5️⃣ Repeat until target is found

*/

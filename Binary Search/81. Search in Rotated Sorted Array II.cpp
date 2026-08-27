
class Solution {// Average Time : O(log n)  ||  Worst Time   : O(n)  ||  Space : O(1)
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        // Modified Binary Search
        while(low <= high)
        {
            // Find the middle element
            int mid = low + (high - low) / 2;

            // If we found the target, return true
            if(nums[mid] == target)
            {
                return true;
            }

            // IMPORTANT CASE:
            // If nums[low], nums[mid] and nums[high]
            // are all equal, we cannot determine
            // which half is sorted.
            //
            // Example:
            // [1, 1, 1, 1, 1]
            //  ↑     ↑     ↑
            // low   mid   high
            //
            // We cannot decide whether the left or right
            // half is sorted.
            //
            // So safely remove the duplicate elements
            // from both ends.
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;

                // Continue with the smaller search space
                continue;
            }

            // Check whether the LEFT half is sorted.
            //
            // nums[low] <= nums[mid] means:
            //
            // [low ........ mid]
            //       sorted
            //
            if(nums[low] <= nums[mid])
            {
                // Check whether target lies inside
                // the sorted left half.
                //
                // We already checked nums[mid] == target,
                // so target < nums[mid] is enough.
                if(nums[low] <= target && target <= nums[mid])
                {
                    // Target is in the left half
                    high = mid - 1;
                }
                else
                {
                    // Target is not in the left half,
                    // so search the right half.
                    low = mid + 1;
                }
            }

            // Otherwise, the RIGHT half is sorted.
            else
            {
                // Check whether target lies inside
                // the sorted right half.
                if(nums[mid] <= target && target <= nums[high])
                {
                    // Target is in the right half
                    low = mid + 1;
                }
                else
                {
                    // Target is not in the right half,
                    // so search the left half.
                    high = mid - 1;
                }
            }
        }

        // Target was not found
        return false;
    }
};

/*  

        SEARCH IN ROTATED ARRAY II
                  ↓
              Find mid
                  ↓
        nums[mid] == target?
             /          \
           YES           NO
            ↓             ↓
          true      Are low, mid, high
                    all equal?
                         ↓
                    YES → low++, high--
                         ↓
                       continue
                         ↓
                       NO
                         ↓
              Is LEFT half sorted?
                 /             \
               YES             NO
                ↓               ↓
       target in left?    RIGHT is sorted
          /      \             ↓
        YES      NO      target in right?
         ↓        ↓         /       \
      high--    low++      YES       NO
                            ↓         ↓
                          low++     high--


┌─────────────────────────────────────────┐
│   SEARCH IN ROTATED SORTED ARRAY II     │
├─────────────────────────────────────────┤
│                                         │
│  1. Find mid                            │
│                                         │
│       low       mid       high          │
│        ↓         ↓         ↓            │
│       [4  5  6  0  0  1  2]             │
│                                         │
│  2. nums[mid] == target ?               │
│       YES → return true                 │
│                                         │
│  3. Duplicates problem?                 │
│                                         │
│  nums[low] == nums[mid] == nums[high]   │
│       ↓                                 │
│  low++ , high--                         │
│       ↓                                 │
│  continue                               │
│                                         │
│  4. LEFT half sorted?                   │
│                                         │
│  nums[low] <= nums[mid]                 │
│       ↓                                 │
│  Target in left range?                  │
│     YES → high = mid - 1                │
│     NO  → low = mid + 1                 │
│                                         │
│  5. Otherwise RIGHT half is sorted     │
│                                         │
│  Target in right range?                 │
│     YES → low = mid + 1                 │
│     NO  → high = mid - 1                │
│                                         │
├─────────────────────────────────────────┤
│  TIME                                   │
│  Average → O(log n)                     │
│  Worst   → O(n)  ← duplicates           │
│                                         │
│  SPACE → O(1)                           │
└─────────────────────────────────────────┘

🔥 Remember this

Target found → return true
All 3 equal → shrink both sides
Left sorted → check target range
Otherwise → right sorted
Duplicates can make it O(n).

*/

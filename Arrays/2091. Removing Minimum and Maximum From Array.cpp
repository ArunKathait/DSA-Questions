
class Solution {// Time: O(n)                                  Space: O(1)
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        // Store the index of the minimum element
        int minIndex = 0;

        // Store the index of the maximum element
        int maxIndex = 0;

        // Find the indices of minimum and maximum elements
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < nums[minIndex])
            {
                minIndex = i;
            }

            if(nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }

        // We don't care whether minimum or maximum comes first.
        // leftIndex  = index that comes earlier
        // rightIndex = index that comes later
        //
        // Example:
        // minIndex = 4, maxIndex = 1
        // leftIndex = 1
        // rightIndex = 4
        int leftIndex = min(minIndex, maxIndex);
        int rightIndex = max(minIndex, maxIndex);

        // CASE 1:
        // Remove elements only from the LEFT.
        //
        // We have to reach rightIndex because it is the
        // farther element from the left.
        //
        // If rightIndex = 4:
        // indices removed = 0,1,2,3,4
        // deletions = 5 = rightIndex + 1
        int bothLeft = rightIndex + 1;

        // CASE 2:
        // Remove elements only from the RIGHT.
        //
        // We have to reach leftIndex because it is the
        // farther element from the right.
        //
        // Number of elements from leftIndex to the end:
        // n - leftIndex
        int bothRight = n - leftIndex;

        // CASE 3:
        // Remove one element from the LEFT and the other
        // element from the RIGHT.
        //
        // Remove everything from 0 to leftIndex:
        // leftIndex + 1 deletions
        //
        // Remove everything from rightIndex to n-1:
        // n - rightIndex deletions
        //
        // Total:
        // leftIndex + 1 + n - rightIndex
        int oneEachSide = leftIndex + 1 + n - rightIndex;

        // We only need the minimum among these 3 strategies.
        return min({bothLeft, bothRight, oneEachSide});
    }
};

/*  

┌──────────────────────────────────────────┐
│   MINIMUM DELETIONS: MIN + MAX           │
├──────────────────────────────────────────┤
│                                          │
│ 1. Find index of minimum element         │
│    minIndex                              │
│                                          │
│ 2. Find index of maximum element         │
│    maxIndex                              │
│                                          │
│ 3. Arrange their positions:              │
│                                          │
│    leftIndex  = min(minIndex, maxIndex)  │
│    rightIndex = max(minIndex, maxIndex)  │
│                                          │
│ 4. There are ONLY 3 possibilities:       │
│                                          │
│    A) Remove BOTH from LEFT              │
│       → rightIndex + 1                   │
│                                          │
│    B) Remove BOTH from RIGHT             │
│       → n - leftIndex                    │
│                                          │
│    C) Remove ONE from each side          │
│       → leftIndex + 1                    │
│         + n - rightIndex                 │
│                                          │
│ 5. Take minimum of the 3:                │
│                                          │
│    min({bothLeft,                        │
│         bothRight,                       │
│         oneEachSide})                    │
│                                          │
│ Pattern:                                 │
│ Index Finding + 3 Cases + Min            │
└──────────────────────────────────────────┘

  */

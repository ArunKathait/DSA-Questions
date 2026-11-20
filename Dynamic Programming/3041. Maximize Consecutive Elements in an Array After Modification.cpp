**********************************************APPROACH 1st(MEMOIZATION)*************************************************
class Solution {// Time Complexity:  O(n log n)                 Space Complexity: O(n)
public:
    // Finds the first occurrence of target in the sorted array
    // starting from the given start index.
    int findVal(vector<int>& nums, int start, int target)
    {
        // lower_bound returns an iterator to the first element >= target.
        // Convert the iterator into an array index.
        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();

        // Check whether the target actually exists in the array.
        if(j < nums.size() && nums[j] == target)
        {
            return j;
        }

        // Target does not exist.
        return -1;
    }

    // Returns the maximum length of a valid subsequence
    // starting from index with the given increment state.
    int solve(int index, int n, int increment, vector<int>& nums, vector<vector<int>>& dp)
    {
        // If this state has already been calculated, return its result.
        if(dp[index][increment] != -1)
        {
            return dp[index][increment];
        }

        // Calculate the current selected value.
        // increment = 0 means we select nums[index] as it is.
        // increment = 1 means we increase nums[index] by 1.
        int currentVal = nums[index] + increment;

        // At minimum, the current element itself forms a subsequence of length 1.
        int length = 1;

        // OPTION 1:
        // Find the next element whose original value is currentVal + 1.
        // We select that element without incrementing it.
        int j = findVal(nums, index + 1, currentVal + 1);

        if(j != -1)
        {
            // Include the next element and continue from its index.
            // increment = 0 means the next element is not increased.
            length = max(length, 1 + solve(j, n, 0, nums, dp));
        }

        // OPTION 2:
        // Find the next element whose original value is currentVal.
        // We increase that element by 1, making its value currentVal + 1.
        j = findVal(nums, index + 1, currentVal);

        if(j != -1)
        {
            // Include the next element after increasing it by 1.
            // increment = 1 represents this increment operation.
            length = max(length, 1 + solve(j, n, 1, nums, dp));
        }

        // Store and return the maximum subsequence length for this state.
        return dp[index][increment] = length;
    }

    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();

        // dp[index][increment]:
        // Maximum valid subsequence length starting at index
        // when the current element is either unchanged (0)
        // or increased by 1 (1).
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // Sorting allows us to use binary search to find the next element.
        sort(nums.begin(), nums.end());

        int ans = 0;

        // Try every element as the starting element.
        for(int i = 0; i < n; i++)
        {
            // Try both possibilities:
            // 1. Start without incrementing the element.
            // 2. Start after incrementing the element by 1.
            ans = max({ans, solve(i, n, 0, nums, dp), solve(i, n, 1, nums, dp)});
        }

        // Return the maximum valid subsequence length.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Maximum Selected Elements                    │
├──────────────────────────────────────────────┤
│ Approach: Sorting + Binary Search + DP       │
│                                              │
│ Key Idea:                                    │
│ Sort the array and try every element as the  │
│ starting point.                              │
│                                              │
│ DP State:                                    │
│ dp[index][increment]                         │
│                                              │
│ increment = 0 → Original value               │
│ increment = 1 → Original value + 1           │
│                                              │
│ Transitions:                                 │
│ 1. Find currentVal + 1 (unchanged).          │
│ 2. Find currentVal (increment by 1).         │
│                                              │
│ Use lower_bound to find the next element.    │
│ Memoization avoids recalculating states.     │
│                                              │
│ Time Complexity:  O(n log n)                 │
│ Space Complexity: O(n)                       │
│ Extra Space:      O(n)                       │
└──────────────────────────────────────────────┘

*/

*******************************************APPROACH 2nd(TABULATION)***************************************************

class Solution {// Time Complexity: O(n log n)                           Space Complexity: O(n) 
public:
    // Finds the first occurrence of target in the sorted array
    // starting from the given start index.
    int findVal(vector<int>& nums, int start, int target)
    {
        // lower_bound returns the first element >= target.
        // Convert the iterator into an array index.
        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();

        // Check whether the target actually exists.
        if(j < nums.size() && nums[j] == target)
        {
            return j;
        }

        // Target not found.
        return -1;
    }

    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();

        // Sort the array so that we can use binary search
        // to find the next required element.
        sort(nums.begin(), nums.end());

        // dp[i][increment] represents the maximum length
        // of a valid subsequence starting from index i.
        //
        // increment = 0 -> Current element is not increased.
        // increment = 1 -> Current element is increased by 1.
        //
        // dp[n][0] and dp[n][1] represent the base case.
        // They remain 0 because there are no elements after index n-1.
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // Stores the maximum valid subsequence length.
        int ans = 1;

        // Traverse from right to left because each state
        // depends on states at indices greater than i.
        for(int i = n - 1; i >= 0; i--)
        {
            // Calculate both possibilities:
            // 0 -> Do not increment the current element.
            // 1 -> Increment the current element by 1.
            for(int increment = 0; increment < 2; increment++)
            {
                // Calculate the actual value of the current element.
                int currentVal = nums[i] + increment;

                // At minimum, the current element itself
                // forms a valid subsequence of length 1.
                int length = 1;

                // OPTION 1:
                // Find the next element whose original value
                // is currentVal + 1.
                //
                // This means we select the next element without
                // incrementing it.
                int j = findVal(nums, i + 1, currentVal + 1);

                if(j != -1)
                {
                    // Include the next element.
                    // dp[j][0] represents the best subsequence
                    // starting at j without incrementing that element.
                    length = max(length, 1 + dp[j][0]);
                }

                // OPTION 2:
                // Find the next element whose original value
                // is currentVal.
                //
                // We can increment that element by 1,
                // making its selected value currentVal + 1.
                j = findVal(nums, i + 1, currentVal);

                if(j != -1)
                {
                    // Include the next element after incrementing it.
                    // dp[j][1] represents the best subsequence
                    // starting at j with that element incremented.
                    length = max(length, 1 + dp[j][1]);
                }

                // Store the maximum length for the current state.
                dp[i][increment] = length;

                // Update the overall maximum answer.
                ans = max(ans, length);
            }
        }

        // Return the maximum valid subsequence length.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Maximum Selected Elements                    │
├──────────────────────────────────────────────┤
│ Approach: Sorting + Binary Search + DP       │
│             (Bottom-Up / Tabulation)         │
│                                              │
│ Key Idea:                                    │
│ Sort the array and calculate DP from right   │
│ to left because each state depends on        │
│ future indices.                              │
│                                              │
│ DP State:                                    │
│ dp[i][0] = Current element unchanged         │
│ dp[i][1] = Current element incremented by 1  │
│                                              │
│ Transitions:                                 │
│ 1. Find currentVal + 1 (no increment).       │
│ 2. Find currentVal (increment by 1).         │
│                                              │
│ Use lower_bound to find the next element.    │
│ Take the maximum of both transitions.        │
│                                              │
│ Time Complexity:  O(n log n)                 │
│ Space Complexity: O(n)                       │
│ Extra Space:      O(n)                       │
└──────────────────────────────────────────────┘

*/

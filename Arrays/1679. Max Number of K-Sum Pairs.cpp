***********************************************APPROACH 1st***********************************************************

class Solution {// TIME:  O(n log n)                                SPACE: O(1)
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        // Sort the array so we can use the two-pointer approach.
        sort(nums.begin(), nums.end());

        // Step 2: Initialize two pointers.
        int i = 0;       // Points to the smallest element.
        int j = n - 1;   // Points to the largest element.

        int ans = 0;     // Stores the maximum number of valid pairs.

        // Continue until both pointers meet.
        while(i < j)
        {
            int sum = nums[i] + nums[j];

            // If the sum equals k, we found a valid pair.
            if(sum == k)
            {
                ans++;  // Count this operation.
                i++;    // Move left pointer forward.
                j--;    // Move right pointer backward.
            }
            // If the sum is smaller than k,
            // we need a bigger sum, so increase the left pointer.
            else if(sum < k)
            {
                i++;
            }
            // If the sum is greater than k,
            // we need a smaller sum, so decrease the right pointer.
            else
            {
                j--;
            }
        }

        // Return the maximum number of valid operations.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│           MAXIMUM NUMBER OF K-SUM PAIRS              │
├──────────────────────────────────────────────────────┤
│ APPROACH: Sorting + Two Pointers                     │
│                                                      │
│ KEY IDEA:                                            │
│ • Sort the array.                                    │
│ • i = 0 (smallest), j = n-1 (largest).               │
│ • If sum == k → count pair, move both pointers.      │
│ • If sum < k → move i forward.                       │
│ • If sum > k → move j backward.                      │
│ • Stop when i >= j.                                  │
│                                                      │
├──────────────────────────────────────────────────────┤
│ TIME:  O(n log n)  [Sorting dominates]               │
│ SPACE: O(1) auxiliary (excluding sorting stack)      │
└──────────────────────────────────────────────────────┘

*/

************************************************APPROACH 2nd***********************************************************

class Solution {// TIME:  O(n)                            SPACE: O(n)
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;  // Stores the maximum number of valid pairs.

        unordered_map<int,int> ump;  // Stores the frequency of available numbers.

        // Traverse each number in the array.
        for(auto &num : nums)
        {
            // Calculate the number needed to make the sum equal to k.
            int target = k - num;

            // Check if the required complement is available.
            if(ump[target] > 0)
            {
                ans++;           // Found a valid pair, increment answer.
                ump[target]--;   // Decrease its frequency because it is used.
            }
            else
            {
                // Complement is not available, so store the current number.
                ump[num]++;
            }
        }

        // Return the total number of valid pairs.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│           MAXIMUM NUMBER OF K-SUM PAIRS              │
├──────────────────────────────────────────────────────┤
│ APPROACH: HashMap + Complement                       │
│                                                      │
│ KEY IDEA:                                            │
│ • Traverse the array once.                           │
│ • Calculate target = k - num.                        │
│ • If ump[target] > 0:                                │
│      → Increment ans.                                │
│      → Decrease complement frequency.                │
│ • Otherwise, store the current number.               │
│ • Each element can be used only once.                │
│                                                      │
├──────────────────────────────────────────────────────┤
│ TIME:  O(n) Average                                  │
│ SPACE: O(n)                                          │
└──────────────────────────────────────────────────────┘

*/

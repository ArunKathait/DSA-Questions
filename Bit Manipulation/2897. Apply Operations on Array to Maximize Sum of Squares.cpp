
class Solution {// Time Complexity:O(32n + 32k) = O(n+k))     Space Complexity: O(32) = O(1)
public:
    int M = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        // count[b] stores how many numbers have the b-th bit set.
        // Example: if bit 2 is set in 3 numbers, count[2] = 3.
        vector<int> count(32, 0);

        // Step 1: Count the set bits at every position.
        for (auto& num : nums) 
        {
            for (int bit = 0; bit < 32; bit++) 
            {
                // Check whether the bit-th bit is set in num.
                if (num & (1 << bit)) 
                {
                    count[bit]++;
                }
            }
        }

        // Stores the sum of squares of the k constructed numbers.
        long long ans = 0;

        // Step 2: Construct k numbers greedily.
        while (k--) 
        {
            long long current = 0;
            // Step 3: Build the largest possible current number
            // using the set bits that are still available.
            for (int bit = 0; bit < 32; bit++) 
            {
                if (count[bit] > 0) 
                {
                    // Set this bit in the current number.
                    current = (current | (1 << bit));

                    // This occurrence of the bit has been used.
                    // It cannot be reused in another number.
                    count[bit]--;
                }
            }

            // Step 4: Add the square of the completed number.
            // Apply modulo to keep the value manageable.
            ans = (ans + (current * current)) % M;
        }

        // Return the sum of squares.
        return ans;
    }
};

/*

┌────────────────────────────────────────┐
│          MAX SUM OF SQUARES            │
├────────────────────────────────────────┤
│ Approach: Greedy + Bit Counting        │
│                                        │
│ 1. Initialize count[32] = 0.           │
│ 2. Count set bits at each position     │
│    across all numbers.                 │
│ 3. Repeat k times:                     │
│    • Initialize current = 0.           │
│    • If count[bit] > 0, set that bit   │
│      in current and decrement count.   │
│    • Add (current)² to ans modulo M.   │
│ 4. Return ans.                         │
│                                        │
│ KEY: Use every available bit once      │
│ per constructed number.                │
│                                        │
│ TC: O(32n + 32k) = O(n + k)            │
│ SC: O(32) = O(1) auxiliary             │
└────────────────────────────────────────┘

*/

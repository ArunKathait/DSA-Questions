

class Solution {// Time Complexity: O(nlogn*d)                   Space Complexity: O(n)
public:
    // Calculate the sum of digits of a number.
    // Example: 38 -> 3 + 8 = 11
    int getDigitSum(int num) 
    {
        int sum = 0;

        while (num) 
        {
            sum += (num % 10); // Extract the last digit and add it.
            num /= 10;         // Remove the last digit.
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Create a copy so that the original ordering
        // can be compared with the required sorted ordering.
        vector<int> afterSorted(nums);

        // Sorting rule:
        // 1. Smaller digit sum comes first.
        // 2. If digit sums are equal, smaller number comes first.
        auto lambda = [&](int num1, int num2) 
        {
            int sum1 = getDigitSum(num1);
            int sum2 = getDigitSum(num2);

            if (sum1 != sum2) 
            {
                return sum1 < sum2;
            }

            return num1 < num2;
        };

        // Sort the copy according to our custom sorting rule.
        sort(afterSorted.begin(), afterSorted.end(), lambda);

        // Store each number's current index in the original array.
        // This lets us find the required number in O(1) average time.
        unordered_map<int, int> valToIndex;

        for (int i = 0; i < n; i++) 
        {
            valToIndex[nums[i]] = i;
        }

        int swap = 0; // Count the swaps performed.

        for (int i = 0; i < n; i++) 
        {
            int currentVal = nums[i];       // Number currently at index i.
            int expectedVal = afterSorted[i]; // Number that should be at index i.

            // If the current number is already correct,
            // there is no need to swap it.
            if (currentVal == expectedVal) 
            {
                continue;
            }

            // Find the current index of the number
            // that belongs at index i.
            int idx = valToIndex[expectedVal];

            // Swap the two values.
            // expectedVal moves to its correct position i.
            // currentVal moves to index idx.
            nums[i] = expectedVal;
            nums[idx] = currentVal;

            // Update the map because both numbers have moved.
            // expectedVal is now at index i.
            valToIndex[expectedVal] = i;

            // currentVal is now at index idx.
            valToIndex[currentVal] = idx;

            // Count this swap.
            swap++;
        }

        // Return the total number of swaps performed.
        return swap;
    }
};

/*

┌─────────────────────────────────────────┐
│      MINIMUM SWAPS — DIGIT SUM          │
├─────────────────────────────────────────┤
│ 1. Copy the original array              │
│ 2. Sort by digit sum, then by value     │
│ 3. Store value → index in a hash map    │
│ 4. Swap misplaced elements              │
│ 5. Update both indices in the map       │
│ 6. Count each swap                      │
│                                         │
│ KEY IDEA:                               │
│ Place each element at its correct       │
│ sorted position using a hash map.       │
│                                         │
│ Time  : O(n log n × d)                  │
│ Space : O(n)                            │
│                                         │
│ d = maximum number of digits            │
│ Assumption: All elements are distinct   │
└─────────────────────────────────────────┘

*/

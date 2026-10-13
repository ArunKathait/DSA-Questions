************************************************APPROACH 1st********************************************************

class Solution {// TIME:  O(n log n)                SPACE: O(log n) auxiliary
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // Get the total number of elements.
        int n = nums.size();

        // Step 1: Convert every element to its absolute value.
        // This makes all numbers non-negative.
        for (int i = 0; i < n; i++) 
        {
            nums[i] = abs(nums[i]);
        }

        // Step 2: Sort the array in ascending order.
        // Smaller values will be subtracted, and larger values
        // will be added to maximize the final sum.
        sort(nums.begin(), nums.end());

        // Find the middle index to divide the array into two halves.
        int mid = n / 2;

        int i = 0;

        // Store the alternating sum.
        // Use long long because the sum of squares can be large.
        long long ans = 0;

        // Step 3: Subtract the squares of the smaller half.
        // Example: -nums[0]^2 - nums[1]^2
        while (i < mid) 
        {
            // 1LL ensures multiplication happens using long long,
            // preventing integer overflow during squaring.
            ans -= 1LL * nums[i] * nums[i];
            i++;
        }

        // Step 4: Add the squares of the larger half.
        // Example: +nums[mid]^2 + nums[mid+1]^2
        while (i < n) 
        {
            ans += 1LL * nums[i] * nums[i];
            i++;
        }

        // Step 5: Return the maximum alternating sum.
        return ans;
    }
};

/*

┌──────────────────────────────────────┐
│         MAX ALTERNATING SUM          │
├──────────────────────────────────────┤
│ Approach: Greedy + Sorting           │
│                                      │
│ 1.Convert elements to absolute value.│
│ 2. Sort the array.                   │
│ 3. Subtract squares of smaller half. │
│ 4. Add squares of larger half.       │
│                                      │
│ TC: O(n log n)                       │
│ SC: O(log n) auxiliary               │
│                                      │
│ Key: Subtract small, add large.      │
└──────────────────────────────────────┘

*/

*************************************************APPROACH 2nd********************************************************

class Solution {// Time Complexity: O(n) average              Space Complexity: (O(1)
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // Get the total number of elements.
        int n = nums.size();

        // Step 1: Square every element.
        // The problem asks for the maximum alternating sum of squares.
        // Example: [1, 2, 3, 4] becomes [1, 4, 9, 16].
        for (int i = 0; i < n; i++) 
        {
            nums[i] = nums[i] * nums[i];
        }

        // Step 2: Partition the array around the middle index.
        // After nth_element():
        // - The first n/2 elements are the smaller half (in any order).
        // - The remaining elements are the larger half (in any order).
        // - Every element in the first half is <= every element
        //   in the second half.
        // Unlike sort(), nth_element() does not fully sort the array.
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        // Step 3: Calculate the sum of the larger half.
        // 0LL makes the initial accumulator a long long.
        long long largeHalf = accumulate(nums.begin() + n / 2, nums.end(), 0LL);

        // Step 4: Calculate the sum of the smaller half.
        long long smallHalf = accumulate(nums.begin(), nums.begin() + n / 2, 0LL);

        // Step 5: Add the larger values and subtract the smaller values.
        // This maximizes the alternating sum.
        return largeHalf - smallHalf;
    }
};

/*

┌──────────────────────────────────────┐
│         MAX ALTERNATING SUM          │
├──────────────────────────────────────┤
│ Approach: Greedy + nth_element()     │
│                                      │
│ 1. Square every element.             │
│ 2. Partition at index n/2.            │
│ 3. Sum the larger half.              │
│ 4. Sum the smaller half.             │
│ 5. Return largeHalf - smallHalf.     │
│                                      │
│ TC: O(n) average                     │
│ SC: O(1) auxiliary*                  │
│                                      │
│ Key: Partition instead of sorting.   │
└──────────────────────────────────────┘

*/

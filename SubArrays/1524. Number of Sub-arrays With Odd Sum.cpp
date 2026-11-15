*************************************************APPROACH 1st(BRUTE FORCE)***********************************************

class Solution {// Time Complexity: O(n^2)                Space Complexity: O(1)
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int ans = 0; // Stores the count of subarrays having an odd sum

        // i represents the starting index of the subarray
        for(int i = 0; i < n; i++)
        {
            int sum = 0; // Reset sum for every new starting index

            // j represents the ending index of the subarray
            for(int j = i; j < n; j++)
            {
                // Add the current element to calculate the subarray sum
                sum += arr[j];

                // Check whether the current subarray sum is odd
                if(sum % 2 != 0)
                {
                    ans++; // Increment count if the sum is odd
                }
            }
        }

        return ans; // Return total number of odd-sum subarrays
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Number of Subarrays With Odd Sum    │
├──────────────────────────────────────────────┤
│ • Approach: Brute Force (Prefix Running Sum) │
│ • Key Idea: Generate all possible subarrays. │
│   Maintain running sum and check whether     │ 
│   sum % 2 != 0. Increment answer if odd.     │
├──────────────────────────────────────────────┤
│ • Time Complexity:       O(n²)               │
│ • Auxiliary Space:       O(1)                │
│ • Output Space:          O(1)                │
└──────────────────────────────────────────────┘

*/

***************************************************APPROACH 2nd(OPTIMAL)**********************************************

class Solution {//  Time Complexity: O(n)     Space: O(1)
public:
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;  // Stores the count of subarrays having odd sum

        int odd = 0;  // Counts prefix sums having odd parity
        int even = 1; // Counts prefix sums having even parity
                      // Initially 1 because the empty prefix has sum 0

        int sum = 0;  // Maintains the running prefix sum

        // Traverse the array and calculate prefix sums
        for(auto &num : arr)
        {
            sum += num; // Add current element to prefix sum

            // Case 1: Current prefix sum is even
            if(sum % 2 == 0)
            {
                // To get an odd subarray sum, subtract an odd prefix sum
                // Even prefix - Odd prefix = Odd subarray sum
                ans = (ans + odd) % MOD;

                // Store the current even prefix sum
                even++;
            }
            else
            {
                // Case 2: Current prefix sum is odd

                // To get an odd subarray sum, subtract an even prefix sum
                // Odd prefix - Even prefix = Odd subarray sum
                ans = (ans + even) % MOD;

                // Store the current odd prefix sum
                odd++;
            }
        }

        return ans; // Return total number of odd-sum subarrays
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Number of Subarrays With Odd Sum    │
├──────────────────────────────────────────────┤
│ • Approach: Prefix Sum + Parity              │
│ • Key Idea: Count even and odd prefix sums.  │
│   Different parities produce an odd sum.     │
│ • Initialization: even = 1, odd = 0          │
│ • Pattern: Prefix Sum + Counting             │
├──────────────────────────────────────────────┤
│ • Time Complexity:       O(n)                │
│ • Auxiliary Space:       O(1)                │
│ • Output Space:          O(1)                │
└──────────────────────────────────────────────┘

*/

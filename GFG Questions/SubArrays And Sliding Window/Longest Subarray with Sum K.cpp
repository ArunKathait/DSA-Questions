
class Solution {// TC ---> O(N)                                        SC ---> O(N)
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();

        // Store:
        // prefix sum -> first index where this prefix sum appeared
        //
        // We store the FIRST occurrence because it gives us
        // the longest possible subarray.
        unordered_map<int, int> ump;

        // Stores the maximum length found so far
        int ans = 0;

        // These variables are not needed for this approach,
        // so they can be removed.
        int i = 0;
        int j = 0;

        // Stores the prefix sum from index 0 to current index
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            // Add current element to the prefix sum
            sum += arr[i];

            // If prefix sum itself is k,
            // then subarray [0...i] has sum k.
            //
            // Length = i + 1
            if(sum == k)
            {
                ans = i + 1;
            }

            // Suppose current prefix sum = sum.
            //
            // We need a previous prefix sum:
            //
            // previousSum + k = sum
            //
            // Therefore:
            //
            // previousSum = sum - k
            //
            // If sum-k exists, then the elements after
            // that previous index up to i have sum exactly k.
            if(ump.find(sum - k) != ump.end())
            {
                // Previous index = ump[sum-k]
                // Current index  = i
                //
                // Length = i - previousIndex
                ans = max(ans, i - ump[sum - k]);
            }

            // Store the FIRST occurrence of this prefix sum.
            //
            // Why only the first?
            // Because an earlier index gives a longer subarray.
            //
            // Example:
            // sum = 5 appears at index 2 and index 5.
            //
            // If current index = 8:
            //
            // Using index 2 → length = 8 - 2 = 6
            // Using index 5 → length = 8 - 5 = 3
            //
            // So we keep index 2.
            if(ump.find(sum) == ump.end())
            {
                ump[sum] = i;
            }
        }

        return ans;
    }
};

/*

┌──────────────────────────────────────────┐
│       LONGEST SUBARRAY SUM = K           │
├──────────────────────────────────────────┤
│                                          │
│ Prefix Sum = sum                         │
│                                          │
│ We need:                                 │
│                                          │
│ previousSum + k = sum                    │
│                                          │
│ Therefore:                               │
│                                          │
│ previousSum = sum - k                    │
│                                          │
│ If (sum - k) exists in map:              │
│                                          │
│     subarray sum = k                     │
│                                          │
│     length = currentIndex                │
│              - previousIndex             │
│                                          │
│ Store FIRST occurrence of every sum      │
│ → gives maximum length                   │
│                                          │
│ Pattern:                                 │
│ Prefix Sum + HashMap                     │
└──────────────────────────────────────────┘

*/

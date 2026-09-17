class Solution {// TC → O(N)                                  SC → O(N)
public:

    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        // ---------------------------------------------------------
        // Sliding window pointers
        //
        // i = left boundary of the current window
        // j = right boundary of the current window
        // ---------------------------------------------------------
        int i = 0;
        int j = 0;


        // ---------------------------------------------------------
        // minLengthTillIndex[j] =
        // shortest valid subarray found from index 0 to j
        //
        // Initially, no valid subarray has been found,
        // so we use INT_MAX.
        // ---------------------------------------------------------
        vector<int> minLengthTillIndex(n, INT_MAX);


        // Current sum of the sliding window [i ... j]
        int currentSum = 0;


        // ---------------------------------------------------------
        // Stores the shortest subarray with sum == target
        // found so far.
        //
        // Example:
        // If we find valid lengths:
        // 5, 3, 4, 2
        //
        // bestMinLength will become:
        // 5 -> 3 -> 3 -> 2
        // ---------------------------------------------------------
        int bestMinLength = INT_MAX;


        // ---------------------------------------------------------
        // Stores the minimum combined length of two
        // non-overlapping subarrays.
        // ---------------------------------------------------------
        int ans = INT_MAX;


        // ---------------------------------------------------------
        // Move the right pointer through the array.
        // ---------------------------------------------------------
        while(j < n)
        {

            // Add arr[j] to the current sliding window.
            //
            // Current window = [i ... j]
            currentSum += arr[j];


            // -----------------------------------------------------
            // If currentSum becomes greater than target,
            // shrink the window from the left.
            //
            // This works because arr contains positive numbers.
            //
            // We keep removing arr[i] until:
            // currentSum <= target
            // -----------------------------------------------------
            while(currentSum > target)
            {
                currentSum -= arr[i];
                i++;
            }


            // -----------------------------------------------------
            // If currentSum == target,
            // then [i ... j] is a valid subarray.
            // -----------------------------------------------------
            if(currentSum == target)
            {

                // Length of current valid subarray
                //
                // Example:
                // i = 2, j = 4
                //
                // length = 4 - 2 + 1 = 3
                int length = j - i + 1;


                // -------------------------------------------------
                // We need TWO non-overlapping subarrays.
                //
                // Current subarray is:
                //
                //        [ i ........ j ]
                //
                // Therefore, the previous subarray must be
                // completely inside:
                //
                //        [ 0 .... i-1 ]
                //
                // minLengthTillIndex[i-1] gives us the shortest
                // valid subarray in that range.
                // -------------------------------------------------
                if(i > 0 && minLengthTillIndex[i - 1] != INT_MAX)
                {
                    // Combine:
                    //
                    // previous shortest subarray
                    // +
                    // current subarray
                    //
                    // Since previous one ends before i,
                    // they cannot overlap.
                    ans = min(ans,length + minLengthTillIndex[i - 1]);
                }


                // -------------------------------------------------
                // Update the shortest valid subarray found so far.
                //
                // Suppose we found lengths:
                //
                // 5 -> best = 5
                // 3 -> best = 3
                // 7 -> best = 3
                //
                // So we always keep the minimum.
                // -------------------------------------------------
                bestMinLength = min(bestMinLength, length);
            }


            // -----------------------------------------------------
            // Store the best valid subarray length found
            // from index 0 to j.
            //
            // Even if there is no valid subarray ending at j,
            // bestMinLength still contains the best one found
            // earlier.
            // -----------------------------------------------------
            minLengthTillIndex[j] = bestMinLength;


            // Move the right pointer to the next element.
            j++;
        }


        // ---------------------------------------------------------
        // If ans is still INT_MAX,
        // we could not find two non-overlapping subarrays.
        //
        // Otherwise return their minimum combined length.
        // ---------------------------------------------------------
        return ans == INT_MAX ? -1 : ans;
    }
};

/*

🔑 The most important part

Think of the algorithm as maintaining two pieces of information:

Current window:
[i ........ j]
     ↓
sum == target

And:

Best previous subarray:
[0 ........ i-1]
       ↓
minLengthTillIndex[i-1]

Then we combine them:

[ previous subarray ][ current subarray ]
        ↓                    ↓
minLengthTillIndex[i-1]     length

                ↓

        minimum combined length

╔════════════════════════════════════════════╗
║     MIN SUM OF LENGTHS — SLIDING WINDOW    ║
╠════════════════════════════════════════════╣
║ Pattern: Sliding Window + Prefix Minimum   ║
║                                            ║
║ Window: [i ... j]                          ║
║ → currentSum = sum of current window       ║
║                                            ║
║ If sum > target:                           ║
║ → remove arr[i] and move i                 ║
║                                            ║
║ If sum == target:                          ║
║ → length = j - i + 1                       ║
║                                            ║
║ Previous non-overlap:                      ║
║ → minLengthTillIndex[i-1]                  ║
║                                            ║
║ Combine:                                   ║
║ ans = min(ans, length + previousLength)    ║
║                                            ║
║ bestMinLength:                             ║
║ → shortest valid subarray found so far     ║
║                                            ║
║ Key: Previous subarray must end before i   ║
║                                            ║
║ TC → O(N)                                  ║
║ SC → O(N)                                  ║
╚════════════════════════════════════════════╝

*/
